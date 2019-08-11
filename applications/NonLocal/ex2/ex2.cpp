
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

#include "../include/nonlocal_assembly1.hpp"


//2D NONLOCAL EX : nonlocal diffusion for a body with different material properties

using namespace femus;

double InitalValueU (const std::vector < double >& x) {
  double value;

//     value =  x[0] + 0. * ( 0.51 * 0.51 - x[0] * x[0] ) * ( 0.51 * 0.51 - x[1] * x[1] );
//     value =  x[0];
//     value =  x[0] * x[0];
//     value =  x[0] * x[0] * x[0] ;
//     value =  x[0] * x[0] * x[0] + x[1] * x[1] * x[1];
//     value =  x[0] * x[0] * x[0] * x[0] + 0.1 * x[0] * x[0]; //this is x^4 + delta x^2
//     value =  x[0] * x[0] * x[0] * x[0]; //this is x^4
//     value =  2 * x[0] + x[0] * x[0] * x[0] * x[0] * x[0]; //this is 2x + x^5


//      value = (x[0] < 0.) ? x[0] * x[0] * x[0] : 3 * x[0] * x[0] * x[0];

  double u1 = a1 + b1 * x[0] - 1. / (2. * kappa1) * x[0] * x[0];
  double u2 = a2 + b2 * x[0] - 1. / (2. * kappa2) * x[0] * x[0];

  value = (x[0] < 0.) ? u1 : u2;


  return value;
}

void GetL2Norm (MultiLevelProblem& ml_prob, MultiLevelProblem& ml_prob2);

bool SetBoundaryCondition (const std::vector < double >& x, const char SolName[], double& value, const int facename, const double time) {

  bool dirichlet = true;
//     value = 0.;
//     value = x[0];
//     value = x[0] * x[0];
//     value = x[0] * x[0] * x[0] ;
//   value = (x[0] < 0.) ? x[0] * x[0] * x[0] : 3 * x[0] * x[0] * x[0];
//     value = x[0] * x[0] * x[0] + x[1] * x[1] * x[1];
//     value = x[0] * x[0] * x[0] * x[0] + 0.1 * x[0] * x[0]; //this is x^4 + delta x^2
//     value = x[0] * x[0] * x[0] * x[0];
//        value =  2 * x[0] + x[0] * x[0] * x[0] * x[0] * x[0]; //this is 2x + x^5

  double u1 = a1 + b1 * x[0] - 1. / (2. * kappa1) * x[0] * x[0];
  double u2 = a2 + b2 * x[0] - 1. / (2. * kappa2) * x[0] * x[0];

  value = (x[0] < 0.) ? u1 : u2;

  if (facename == 2) {
    if (!strcmp (SolName, "u_local")) {
      value = a1;
    }
    else {
      dirichlet = false; //Neumann at the interface boundaries
      value = 0.;
    }
  }

  return dirichlet;
}

unsigned numberOfUniformLevels = 2;

int main (int argc, char** argv) {

  clock_t total_time = clock();

  // init Petsc-MPI communicator
  FemusInit mpinit (argc, argv, MPI_COMM_WORLD);

  MultiLevelMesh mlMsh;
  double scalingFactor = 1.;
  unsigned numberOfSelectiveLevels = 0;
//     mlMsh.ReadCoarseMesh ( "../input/nonlocal_boundary_test.neu", "second", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/interface.neu", "second", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/maxTest1.neu", "eighth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/maxTest2.neu", "second", scalingFactor );
//         mlMsh.ReadCoarseMesh ( "../input/maxTest3.neu", "second", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/maxTest4.neu", "eighth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/maxTest5.neu", "eighth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/maxTest6.neu", "eighth", scalingFactor );
//   mlMsh.ReadCoarseMesh ("../input/maxTest7.neu", "eighth", scalingFactor);
//     mlMsh.ReadCoarseMesh ( "../input/maxTest8.neu", "eighth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/maxTest9.neu", "eighth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/maxTest10.neu", "eighth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/maxTest2Continuous.neu", "second", scalingFactor );
  //mlMsh.ReadCoarseMesh ( "../input/martaTest0.neu", "second", scalingFactor );
//      mlMsh.ReadCoarseMesh ( "../input/martaTest1.neu", "second", scalingFactor );
//    mlMsh.ReadCoarseMesh ( "../input/martaTest2.neu", "second", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/martaTest3.neu", "second", scalingFactor );
//        mlMsh.ReadCoarseMesh ( "../input/martaTest4.neu", "second", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/martaTest5.neu", "fifth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/martaTest7.neu", "fifth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/martaTest8.neu", "fifth", scalingFactor );
//            mlMsh.ReadCoarseMesh ( "../input/martaTest9.neu", "fifth", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/martaTest4Coarser.neu", "second", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/trial1.neu", "second", scalingFactor );
//     mlMsh.ReadCoarseMesh ( "../input/trial2.neu", "second", scalingFactor );
  mlMsh.ReadCoarseMesh ("../input/d1_2e-4_d2_2e-3_h_2e-4.neu", "eighth", scalingFactor);
  mlMsh.RefineMesh (numberOfUniformLevels + numberOfSelectiveLevels, numberOfUniformLevels , NULL);

  mlMsh.EraseCoarseLevels (numberOfUniformLevels - 1);
//     numberOfUniformLevels = 1;

  unsigned dim = mlMsh.GetDimension();

  MultiLevelSolution mlSol (&mlMsh);

  // add variables to mlSol
  mlSol.AddSolution ("u", LAGRANGE, FIRST, 2);

  mlSol.AddSolution ("u_local", LAGRANGE, FIRST, 2);

  mlSol.AddSolution ("u_exact", LAGRANGE, FIRST, 2);

  mlSol.Initialize ("All");

  mlSol.Initialize ("u_exact", InitalValueU);

  mlSol.AttachSetBoundaryConditionFunction (SetBoundaryCondition);

  // ******* Set boundary conditions *******
  mlSol.GenerateBdc ("All");


  //BEGIN assemble and solve nonlocal problem
  MultiLevelProblem ml_prob (&mlSol);

  // ******* Add FEM system to the MultiLevel problem *******
  LinearImplicitSystem& system = ml_prob.add_system < LinearImplicitSystem > ("NonLocal");
  system.AddSolutionToSystemPDE ("u");

  // ******* System FEM Assembly *******
  system.SetAssembleFunction (AssembleNonLocalSys);
  system.SetMaxNumberOfLinearIterations (1);
  // ******* set MG-Solver *******
  system.SetMgType (V_CYCLE);

  system.SetAbsoluteLinearConvergenceTolerance (1.e-50);
  //   system.SetNonLinearConvergenceTolerance(1.e-9);
//   system.SetMaxNumberOfNonLinearIterations(20);

  system.SetNumberPreSmoothingStep (1);
  system.SetNumberPostSmoothingStep (1);

  // ******* Set Preconditioner *******
  system.SetMgSmoother (GMRES_SMOOTHER);

  system.SetSparsityPatternMinimumSize (500u);   //TODO tune

  system.init();

  // ******* Set Smoother *******
  system.SetSolverFineGrids (GMRES);

  system.SetPreconditionerFineGrids (ILU_PRECOND);

  system.SetTolerances (1.e-20, 1.e-20, 1.e+50, 100);

// ******* Solution *******

  system.MGsolve();

  //END assemble and solve nonlocal problem

  //BEGIN assemble and solve local problem
  MultiLevelProblem ml_prob2 (&mlSol);

  // ******* Add FEM system to the MultiLevel problem *******
  LinearImplicitSystem& system2 = ml_prob2.add_system < LinearImplicitSystem > ("Local");
  system2.AddSolutionToSystemPDE ("u_local");

  // ******* System FEM Assembly *******
  system2.SetAssembleFunction (AssembleLocalSys);
  system2.SetMaxNumberOfLinearIterations (1);
  // ******* set MG-Solver *******
  system2.SetMgType (V_CYCLE);

  system2.SetAbsoluteLinearConvergenceTolerance (1.e-50);

  system2.SetNumberPreSmoothingStep (1);
  system2.SetNumberPostSmoothingStep (1);

  // ******* Set Preconditioner *******
  system2.SetMgSmoother (GMRES_SMOOTHER);

  system2.init();

  // ******* Set Smoother *******
  system2.SetSolverFineGrids (GMRES);

  system2.SetPreconditionerFineGrids (ILU_PRECOND);

  system2.SetTolerances (1.e-20, 1.e-20, 1.e+50, 100);

// ******* Solution *******

  system2.MGsolve();

  //END assemble and solve local problem


  //BEGIN compute errors
  GetL2Norm (ml_prob, ml_prob2);
  //END compute errors

  // ******* Print solution *******
  mlSol.SetWriter (VTK);
  std::vector<std::string> print_vars;
  print_vars.push_back ("All");
  mlSol.GetWriter()->SetDebugOutput (true);
  mlSol.GetWriter()->Write (DEFAULT_OUTPUTDIR, "biquadratic", print_vars, 0);

  std::cout << std::endl << " total CPU time : " << std::setw (11) << std::setprecision (6) << std::fixed
            << static_cast<double> ( (clock() - total_time)) / CLOCKS_PER_SEC << " s" << std::endl;

  return 0;

} //end main


void GetL2Norm (MultiLevelProblem& ml_prob, MultiLevelProblem& ml_prob2) {

  LinearImplicitSystem* mlPdeSys  = &ml_prob.get_system<LinearImplicitSystem> ("NonLocal");
  const unsigned level = mlPdeSys->GetLevelToAssemble();
  Mesh*                    msh = ml_prob._ml_msh->GetLevel (level);
  elem*                     el = msh->el;
  MultiLevelSolution*    mlSol = ml_prob._ml_sol;
  Solution*                sol = ml_prob._ml_sol->GetSolutionLevel (level);

  LinearImplicitSystem* mlPdeSys2  = &ml_prob2.get_system<LinearImplicitSystem> ("Local");
  MultiLevelSolution*    mlSol2 = ml_prob2._ml_sol;
  Solution*                sol2 = ml_prob2._ml_sol->GetSolutionLevel (level);

  const unsigned  dim = msh->GetDimension();

  unsigned xType = 2; // get the finite element type for "x", it is always 2 (LAGRANGE QUADRATIC)

  double error_solExact_norm2 = 0.;

  double error_solExact_local_norm2 = 0.;

  double error_solLocal_norm2 = 0.;

  double solNonlocal_norm2 = 0.;

  double solLocal_norm2 = 0.;

  double sol_exact_norm2 = 0.;

  unsigned soluIndex;
  soluIndex = mlSol->GetIndex ("u");
  unsigned soluType = mlSol->GetSolutionType (soluIndex);

  unsigned soluIndexLocal;
  soluIndexLocal = mlSol2->GetIndex ("u_local");

  unsigned    iproc = msh->processor_id();
  unsigned    nprocs = msh->n_processors();

  for (int iel = msh->_elementOffset[iproc]; iel < msh->_elementOffset[iproc + 1]; iel++) {

    short unsigned ielGeom = msh->GetElementType (iel);
    unsigned nDofu  = msh->GetElementDofNumber (iel, soluType);
    unsigned nDofx = msh->GetElementDofNumber (iel, xType);

    vector < vector < double > > x1 (dim);

    for (int i = 0; i < dim; i++) {
      x1[i].resize (nDofx);
    }

    vector < double >  soluNonLoc (nDofu);
    vector < double >  soluLoc (nDofu);

    for (unsigned i = 0; i < nDofu; i++) {
      unsigned solDof = msh->GetSolutionDof (i, iel, soluType);
      soluNonLoc[i] = (*sol->_Sol[soluIndex]) (solDof);
      soluLoc[i] = (*sol2->_Sol[soluIndexLocal]) (solDof);
    }

    for (unsigned i = 0; i < nDofx; i++) {
      unsigned xDof  = msh->GetSolutionDof (i, iel, xType);

      for (unsigned jdim = 0; jdim < dim; jdim++) {
        x1[jdim][i] = (*msh->_topology->_Sol[jdim]) (xDof);
      }
    }

    vector <double> phi;  // local test function
    vector <double> phi_x; // local test function first order partial derivatives
    double weight; // gauss point weight

    // *** Gauss point loop ***
    for (unsigned ig = 0; ig < msh->_finiteElement[ielGeom][soluType]->GetGaussPointNumber(); ig++) {
      // *** get gauss point weight, test function and test function partial derivatives ***
      msh->_finiteElement[ielGeom][soluType]->Jacobian (x1, ig, weight, phi, phi_x);
      double soluNonLoc_gss = 0.;
      double soluLoc_gss = 0.;
      double soluExact_gss = 0.;
      double x_gss = 0.;
      double y_gss = 0.;

      for (unsigned i = 0; i < nDofu; i++) {
        soluNonLoc_gss += phi[i] * soluNonLoc[i];
        soluLoc_gss += phi[i] * soluLoc[i];
        x_gss += phi[i] * x1[0][i]; // this is x at the Gauss point
//                 y_gss += phi[i] * x1[1][i]; // this is y at the Gauss point
      }

      double u1 = a1 + b1 * x_gss - 1. / (2. * kappa1) * x_gss * x_gss;
      double u2 = a2 + b2 * x_gss - 1. / (2. * kappa2) * x_gss * x_gss;

      soluExact_gss = (x_gss < 0.) ? u1 : u2;

//             soluExact_gss = x_gss * x_gss * x_gss * x_gss + 0.1 * x_gss * x_gss; // this is x^4 + delta * x^2

//             soluExact_gss = x_gss * x_gss; // this is x^2

//             soluExact_gss = (x_gss < 0.) ? x_gss * x_gss * x_gss : 3.* x_gss * x_gss * x_gss; // this is x^3 for x< 0 and 3 x^3 for x >= 0

//             soluExact_gss = x_gss * x_gss * x_gss + y_gss * y_gss * y_gss ; // this is x^3 + y^3

//             soluExact_gss = x_gss * x_gss * x_gss * x_gss; // this is x^4

//             soluExact_gss = 2 * x_gss  + x_gss * x_gss * x_gss * x_gss * x_gss ; // this is 2x + x^5

      error_solExact_norm2 += (soluNonLoc_gss - soluExact_gss) * (soluNonLoc_gss - soluExact_gss) * weight;

      error_solExact_local_norm2 += (soluLoc_gss - soluExact_gss) * (soluLoc_gss - soluExact_gss) * weight;

      error_solLocal_norm2 += (soluNonLoc_gss - soluLoc_gss) * (soluNonLoc_gss - soluLoc_gss) * weight;

      solNonlocal_norm2 += soluNonLoc_gss * soluNonLoc_gss * weight;

      solLocal_norm2 += soluLoc_gss * soluLoc_gss * weight;

      sol_exact_norm2 += soluExact_gss * soluExact_gss * weight;
    }
  }

  double norm2 = 0.;
  MPI_Allreduce (&error_solExact_norm2, &norm2, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  double norm = sqrt (norm2);
  std::cout.precision (14);
  std::cout << "L2 norm of ERROR: Nonlocal - exact = " << norm << std::endl;

  norm2 = 0.;
  MPI_Allreduce (&error_solExact_local_norm2, &norm2, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  norm = sqrt (norm2);
  std::cout.precision (14);
  std::cout << "L2 norm of ERROR: Local - exact = " << norm << std::endl;

  norm2 = 0.;
  MPI_Allreduce (&error_solLocal_norm2, &norm2, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  norm = sqrt (norm2);
  std::cout.precision (14);
  std::cout << "L2 norm of ERROR: Nonlocal - local = " << norm << std::endl;

  norm2 = 0.;
  MPI_Allreduce (&solNonlocal_norm2, &norm2, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  norm = sqrt (norm2);
  std::cout.precision (14);
  std::cout << "L2 norm of NONLOCAL soln = " << norm << std::endl;

  norm2 = 0.;
  MPI_Allreduce (&solLocal_norm2, &norm2, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  norm = sqrt (norm2);
  std::cout.precision (14);
  std::cout << "L2 norm of LOCAL soln = " << norm << std::endl;

  norm2 = 0.;
  MPI_Allreduce (&sol_exact_norm2, &norm2, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  norm = sqrt (norm2);
  std::cout.precision (14);
  std::cout << "L2 norm of EXACT soln = " << norm << std::endl;


  double littleL2norm = 0.;
  std::vector<double> littleLInfinitynorm (nprocs, 0.);

  for (unsigned i =  msh->_dofOffset[soluType][iproc]; i <  msh->_dofOffset[soluType][iproc + 1]; i++) {

    double nonLocalNodalValue = (*sol->_Sol[soluIndex]) (i);
    double LocalNodalValue = (*sol2->_Sol[soluIndexLocal]) (i);

    double difference = fabs (nonLocalNodalValue - LocalNodalValue);

    if (difference > littleLInfinitynorm[iproc]) littleLInfinitynorm[iproc] = difference;

    littleL2norm += difference * difference;

  }

  norm2 = 0.;
  MPI_Allreduce (&littleL2norm, &norm2, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  norm = sqrt (norm2);
  std::cout.precision (14);
  std::cout << "l2 norm of ERROR: Nonlocal - local = " << norm << std::endl;

  for (int kproc = 0; kproc < nprocs; kproc++) {
    MPI_Bcast (&littleLInfinitynorm[iproc], 1, MPI_DOUBLE, kproc, MPI_COMM_WORLD);
  }

  double littleLInfinityNorm = littleLInfinitynorm[0];

  for (unsigned kproc = 0; kproc < nprocs; kproc++) {
    if (littleLInfinitynorm[kproc] > littleLInfinityNorm) littleLInfinityNorm = littleLInfinitynorm[kproc];
  }

  std::cout.precision (14);
  std::cout << "linfinity norm of ERROR: Nonlocal - local = " << littleLInfinityNorm << std::endl;


}






