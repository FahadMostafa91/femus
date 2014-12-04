#include "FETri6.hpp"


namespace femus {




// =======================
FETri6::FETri6(std::vector<GeomEl> geomel_in) : FEElemBase(geomel_in) {  }
	  
// =======================
          FETri6::~FETri6() {    }

          
// =======================
      float FETri6::get_embedding_matrix(const uint a ,const uint b,const uint c )  {  return _embedding_matrix[a][b][c];  }
      

// =======================
//STATIC data member
	   const float FETri6::_embedding_matrix[4][6][6] =
{ // ---------------------------------------
  {// embedding matrix for child 0
    //  0      1      2    3    4    5
    { 1.0,   0.0,   0.0, 0.0, 0.0, 0.0}, // 0
    { 0.0,   0.0,   0.0, 1.0, 0.0, 0.0}, // 1
    { 0.0,   0.0,   0.0, 0.0, 0.0, 1.0}, // 2
    {.375, -.125,   0.0, .75, 0.0, 0.0}, // 3
    { 0.0, -.125, -.125, 0.5, .25, 0.5}, // 4
    {.375,   0.0, -.125, 0.0, 0.0, .75}  // 5
  },
  {// embedding matrix for child 1
    //  0      1      2    3    4    5
    {  0.0,  0.0,   0.0, 1.0, 0.0, 0.0}, // 0
    {  0.0,  1.0,   0.0, 0.0, 0.0, 0.0}, // 1
    {  0.0,  0.0,   0.0, 0.0, 1.0, 0.0}, // 2
    {-.125, .375,   0.0, .75, 0.0, 0.0}, // 3
    {  0.0, .375, -.125, 0.0, .75, 0.0}, // 4
    {-.125,  0.0, -.125, 0.5, 0.5, .25}  // 5
  },

  // embedding matrix for child 2
  {
    //  0       1     2    3    4    5
    {  0.0,   0.0,  0.0, 0.0, 0.0, 1.0}, // 0
    {  0.0,   0.0,  0.0, 0.0, 1.0, 0.0}, // 1
    {  0.0,   0.0,  1.0, 0.0, 0.0, 0.0}, // 2
    {-.125, -.125,  0.0, .25, 0.5, 0.5}, // 3
    {  0.0, -.125, .375, 0.0, .75, 0.0}, // 4
    {-.125,   0.0, .375, 0.0, 0.0, .75}  // 5
  },

  // embedding matrix for child 3
  {
    //  0       1      2    3    4    5
    {  0.0,   0.0,   0.0, 1.0, 0.0, 0.0}, // 0
    {  0.0,   0.0,   0.0, 0.0, 1.0, 0.0}, // 1
    {  0.0,   0.0,   0.0, 0.0, 0.0, 1.0}, // 2
    {-.125,   0.0, -.125, 0.5, 0.5, .25}, // 3
    {-.125, -.125,   0.0, .25, 0.5, 0.5}, // 4
    {  0.0, -.125, -.125, 0.5, .25, 0.5}  // 5
  }
};
 
 


} //end namespace femus


 
 
 
 