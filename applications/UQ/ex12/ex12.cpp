#include "FemusInit.hpp"
#include "MultiLevelProblem.hpp"
#include "VTKWriter.hpp"
#include "TransientSystem.hpp"
#include "NonLinearImplicitSystem.hpp"

#include "NumericVector.hpp"
#include "adept.h"

#include "petsc.h"
#include "petscmat.h"
#include "PetscMatrix.hpp"

#include "slepceps.h"
#include "sparseGrid.hpp"

//THIS EXTENDS WHAT IS IN EX10 TO SPARSE GRIDS (so stochastic dimension grater than 3)

using namespace femus;



//BEGIN stochastic data

unsigned alpha = 6;
unsigned M = pow ( 10, alpha ); //number of samples
unsigned N = 2; //dimension of the parameter space (each of the M samples has N entries)
unsigned L = alpha ;
bool output = false; //for debugging
bool matlabView = true;

//FOR NORMAL DISTRIBUTION
boost::mt19937 rng; // I don't seed it on purpouse (it's not relevant)
boost::normal_distribution<> nd ( 0., 1. );
boost::variate_generator < boost::mt19937&,
      boost::normal_distribution<> > var_nor ( rng, nd );

//FOR UNIFORM DISTRIBUTION
boost::mt19937 rng1; // I don't seed it on purpouse (it's not relevant)
boost::random::uniform_real_distribution<> un ( - 1., 1. );
boost::variate_generator < boost::mt19937&,
      boost::random::uniform_real_distribution<> > var_unif ( rng1, un );

//FOR LAPLACE DISTRIBUTION
boost::mt19937 rng2; // I don't seed it on purpouse (it's not relevant)
boost::random::uniform_real_distribution<> un1 ( - 0.5, 0.49999999999 );
boost::variate_generator < boost::mt19937&,
      boost::random::uniform_real_distribution<> > var_unif1 ( rng2, un1 );
double b = 2.;
//END

int main ( int argc, char** argv )
{

    std::vector < std::vector < double > >  samples;
    samples.resize ( M );

    for ( unsigned m = 0; m < M; m++ ) {
        samples[m].resize ( N );
    }


    for ( unsigned m = 0; m < M; m++ ) {
        for ( unsigned n = 0; n < N; n++ ) {

            double var = var_nor();
            double varunif = var_unif();
            double U = var_unif1();
//     samples[m][n] = var * var * var;
//     samples[m][n] = exp(var);
//         samples[m][n] = exp (varunif);
            samples[m][n] = var;

            //exp of truncated gaussian
//     if(fabs(var) <= 1.) {
//       samples[m][n] = var / (0.5 * ((1. + erf((1. / 0.3) / sqrt(2))) - (1. + erf((- 1. / 0.3) / sqrt(2))))) ;    //truncated Gaussian
//     }
//     else samples[m][n] = 0.;

            //laplace distribution
//     double signU = 0.;
//     if(U < 0) signU = - 1.;
//     else if(U > 0) signU = 1.;
//     samples[m][n] = 0. - b * signU * log(1. - 2. * fabs(U)) ;

//     std::cout << "samples[" << m << "][" << n << "]=" << samples[m][n] << std::endl;

        }
    }

    clock_t total_time = clock();
    clock_t grid_time = clock();
    sparseGrid spg ( samples, output );


    std::cout << std::endl << " Builds sparse grid in: " << std::setw ( 11 ) << std::setprecision ( 6 ) << std::fixed
              << static_cast<double> ( ( clock() - grid_time ) ) / CLOCKS_PER_SEC << " s" << std::endl;

    clock_t nodal_time = clock();
    spg.EvaluateNodalValuesPDF ( samples );

    std::cout << std::endl << " Builds nodal values in: " << std::setw ( 11 ) << std::setprecision ( 6 ) << std::fixed
              << static_cast<double> ( ( clock() - nodal_time ) ) / CLOCKS_PER_SEC << " s" << std::endl;


    //BEGIN these are just tests
//     double phi;
//     double x = 0.;
//     unsigned nn = 0;
//     unsigned ll = 0;
//     unsigned ii = 0;
//     bool scale = false;
//     spg.EvaluateOneDimensionalPhi(phi, x, nn, ll, ii, scale);
//
// //     std::cout << "phi = " << phi << std::endl;
//
//     std::vector< std::vector < unsigned > > id;
//     id.resize(N);
//     for(unsigned n=0; n<N; n++){
//         id[n].resize(3);
//     }
//
//     id[0][0] = 0;
//     id[0][1] = 0;
//     id[0][2] = 0;
//     id[1][0] = 1;
//     id[1][1] = 0;
//     id[1][2] = 0;
//
//     double phiTensorProduct;
//     std::vector<double> coords(N);
//     for(unsigned n=0; n<N; n++){
//         coords[n]=0.;
//     }
//
//     spg.EvaluatePhi (phiTensorProduct, coords, id, false);
//
// //     std::cout<<"phiTensorProduct = " << phiTensorProduct << std::endl;
    //END

    //BEGIN  create grid for plot in 2D
    //sampling from [-1,1] for both variables, testing on uniform PDF on [-1.5,1,5] x [-1.5,1.5]

    std::vector < unsigned > refinementLevel ( N );

    refinementLevel[0] = L; //refinement level in x

    if ( N > 1 )  refinementLevel[1] = L; //refinement level in y

    if ( N > 2 )  refinementLevel[2] = L; //refinement level in x

    std::vector < unsigned > gridPoints ( N );
    std::vector < std::vector < double> > gridBounds ( N );

    for ( unsigned n = 0; n < N; n++ ) {
        gridPoints[n] = static_cast<unsigned> ( pow ( 2, refinementLevel[n] ) + 1 );
        gridBounds[n].resize ( 2 );
    }

    unsigned gridSize = 1;

    for ( unsigned n = 0; n < N; n++ ) {
        gridSize *= gridPoints[n];
    }

    gridBounds[0][0] = -5.5; //-1.5 for uniform // -5.5 for Gaussian
    gridBounds[0][1] = 5.5; //1.5 for uniform // 5.5 for Gaussian

    if ( N > 1 ) {

        gridBounds[1][0] = -5.5;
        gridBounds[1][1] = 5.5;
    }

    if ( N > 2 ) {

        gridBounds[2][0] = -1.5;
        gridBounds[2][1] = 1.5;
    }

    std::vector < double > h ( N );

    for ( unsigned n = 0; n < N; n++ ) {
        h[n] = ( gridBounds[n][1] - gridBounds[n][0] ) / pow ( 2, refinementLevel[n] );
    }

    std::vector < std::vector < double > > grid;

    unsigned counterGrid = 0;

    for ( unsigned j = 0; j < gridPoints[1]; j++ ) {
        for ( unsigned i = 0; i < gridPoints[0]; i++ ) {
            grid.resize ( counterGrid + 1 );
            grid[counterGrid].resize ( N );
            grid[counterGrid][0] = gridBounds[0][0] + i * h[0];
            grid[counterGrid][1] = gridBounds[1][0] + j * h[1];
            counterGrid++;
        }
    }

//END create grid


    std::vector< std::vector < unsigned > > idPhi ( N );

    for ( unsigned n = 0; n < N; n++ ) {
        idPhi[n].resize ( 3 );
    }

        //BEGIN these are just tests
    // phi_000 * phi_100
//     idPhi[0][0] = 0;
//     idPhi[0][1] = 0;
//     idPhi[0][2] = 0;
//     idPhi[1][0] = 1;
//     idPhi[1][1] = 0;
//     idPhi[1][2] = 0;

    // phi_010 * phi_100
//     idPhi[0][0] = 0;
//     idPhi[0][1] = 1;
//     idPhi[0][2] = 0;
//     idPhi[1][0] = 1;
//     idPhi[1][1] = 0;
//     idPhi[1][2] = 0;

    // phi_012 * phi_100
//     idPhi[0][0] = 0;
//     idPhi[0][1] = 1;
//     idPhi[0][2] = 2;
//     idPhi[1][0] = 1;
//     idPhi[1][1] = 0;
//     idPhi[1][2] = 0;
//END


//BEGIN grid plot
    if ( matlabView ) {
        std::cout << "x=[" << std::endl;

        for ( unsigned i = 0; i < grid.size(); i++ ) {
            std::cout << grid[i][0] << std::endl;
        }

        std::cout << "];" << std::endl;

        std::cout << "y=[" << std::endl;

        for ( unsigned i = 0; i < grid.size(); i++ ) {
            std::cout << grid[i][1] << std::endl;
        }

        std::cout << "];" << std::endl;

        clock_t pdf_time = clock();

        std::cout << "PDF=[" << std::endl;

        for ( unsigned i = 0; i < grid.size(); i++ ) {
            double pdfValue;
            spg.EvaluatePDF ( pdfValue, grid[i] );
            std::cout << pdfValue << std::endl;
//             double phiTensorProductTest;
//             spg.EvaluatePhi ( phiTensorProductTest, grid[i], idPhi, false );
//             std::cout << grid[i][0] << " , " << grid[i][1] << std::endl;
//             std::cout << phiTensorProductTest << std::endl;
        }

        std::cout << "];" << std::endl;

        std::cout << std::endl << " Builds PDF in: " << std::setw ( 11 ) << std::setprecision ( 6 ) << std::fixed
                  << static_cast<double> ( ( clock() - pdf_time ) ) / CLOCKS_PER_SEC << " s" << std::endl;

    }

//END grid plot


    //BEGIN these are just tests
//     double phiTensorProductTest;
//     std::vector< double> trialX ( 2 );
//     trialX[0] = -0.75;
//     trialX[1] = 0.;
//     spg.EvaluatePhi ( phiTensorProductTest, trialX, idPhi, true );
//     std::cout << phiTensorProductTest << std::endl;
//END

//BEGIN compute error
    clock_t error_time = clock();

    double sumError = 0.;

    for ( unsigned m = 0; m < samples.size(); m++ ) {
        double pdfValue;
        spg.EvaluatePDF ( pdfValue, samples[m] );
//         double uniformPDF = ( fabs ( samples[m][0] ) <= 1 && fabs ( samples[m][1] ) <= 1 ) ? 0.25 : 0.;
        double Gaussian = exp(-samples[m][0]*samples[m][0]*0.5) * exp(-samples[m][1]*samples[m][1]*0.5) / (2*acos(-1));
        double errorSquared = ( pdfValue - Gaussian ) * ( pdfValue - Gaussian );
        sumError += errorSquared;
    }

    double aL2E = sqrt ( sumError ) / M;

    std::cout << " Averaged L2 error is = " << aL2E << std::endl;

    //END

    std::cout << std::endl << " Computes error in: " << std::setw ( 11 ) << std::setprecision ( 6 ) << std::fixed
              << static_cast<double> ( ( clock() - error_time ) ) / CLOCKS_PER_SEC << " s" << std::endl;


    std::cout << std::endl << " Total time: " << std::setw ( 11 ) << std::setprecision ( 6 ) << std::fixed
              << static_cast<double> ( ( clock() - total_time ) ) / CLOCKS_PER_SEC << " s" << std::endl;

    return 0;

} //end main



