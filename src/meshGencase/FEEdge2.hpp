#ifndef __femus_meshGencase_FEEdge2_hpp__
#define __femus_meshGencase_FEEdge2_hpp__

//Class for
#include <cstdlib>
#include <iostream>

#include "GeomElemBase.hpp"


namespace femus {



class FEEdge2 : public GeomElemBase  {

public:
  
     FEEdge2();
     
    ~FEEdge2();
  
    unsigned int  get_dimension() const { return 1; };
    unsigned int n_nodes()        const { return 2; };
    std::string   get_name_med()  const { return "SE2"; };
    std::string   get_name_xdmf() const { return "Polyline"; };
    
     float get_embedding_matrix(const uint,const uint,const uint){std::cout << "Edge2: embedding matrix not implemented\n"; abort();};
//       static const float _embedding_matrix[][][];   // (volume)

      double get_prol(const uint /*j*/) {std::cout << "Edge2: prolongation not implemented \n"; abort();};

};


} //end namespace femus



#endif
