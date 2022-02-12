#include "GeomElemTet10.hpp"


namespace femus {




// =======================
GeomElemTet10::GeomElemTet10() : GeomElemBase() {  }
	  
// =======================
          GeomElemTet10::~GeomElemTet10() {    }

          
// =======================
      float GeomElemTet10::get_embedding_matrix(const uint a ,const uint b,const uint c )  {  return _embedding_matrix[a][b][c];  }
      

// =======================
//STATIC data member
  const unsigned  GeomElemTet10::_faces[4][6] = {
      {0, 2, 1, 6, 5, 4},
      {0, 1, 3, 4, 8, 7},
      {1, 2, 3, 5, 9, 8},
      {2, 0, 3, 6, 7, 9}
  };


	   const float GeomElemTet10::_embedding_matrix[8][10][10] =
 { // ------------------------------------------
  {// embedding matrix for child 0
    //    0      1      2      3      4      5      6      7      8      9
    {    1.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.}, // 0
    {    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.,    0.}, // 1
    {    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.}, // 2
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.}, // 3
    { 0.375,-0.125,    0.,    0.,  0.75,    0.,    0.,    0.,    0.,    0.}, // 4
    {    0.,-0.125,-0.125,    0.,   0.5,  0.25,   0.5,    0.,    0.,    0.}, // 5
    { 0.375,    0.,-0.125,    0.,    0.,    0.,  0.75,    0.,    0.,    0.}, // 6
    { 0.375,    0.,    0.,-0.125,    0.,    0.,    0.,  0.75,    0.,    0.}, // 7
    {    0.,-0.125,    0.,-0.125,   0.5,    0.,    0.,   0.5,  0.25,    0.}, // 8
    {    0.,    0.,-0.125,-0.125,    0.,    0.,   0.5,   0.5,    0.,  0.25}  // 9
  },
  {// embedding matrix for child 1
    //    0      1      2      3      4      5      6      7      8      9
    {    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.,    0.}, // 0
    {    0.,    1.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.}, // 1
    {    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.}, // 2
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.}, // 3
    {-0.125, 0.375,    0.,    0.,  0.75,    0.,    0.,    0.,    0.,    0.}, // 4
    {    0., 0.375,-0.125,    0.,    0.,  0.75,    0.,    0.,    0.,    0.}, // 5
    {-0.125,    0.,-0.125,    0.,   0.5,   0.5,  0.25,    0.,    0.,    0.}, // 6
    {-0.125,    0.,    0.,-0.125,   0.5,    0.,    0.,  0.25,   0.5,    0.}, // 7
    {    0., 0.375,    0.,-0.125,    0.,    0.,    0.,    0.,  0.75,    0.}, // 8
    {    0.,    0.,-0.125,-0.125,    0.,   0.5,    0.,    0.,   0.5,  0.25}  // 9
  },
  { // embedding matrix for child 2
    //    0      1      2      3      4      5      6      7      8      9
    {    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.}, // 0
    {    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.}, // 1
    {    0.,    0.,    1.,    0.,    0.,    0.,    0.,    0.,    0.,    0.}, // 2
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.}, // 3
    {-0.125,-0.125,    0.,    0.,  0.25,   0.5,   0.5,    0.,    0.,    0.}, // 4
    {    0.,-0.125, 0.375,    0.,    0.,  0.75,    0.,    0.,    0.,    0.}, // 5
    {-0.125,    0., 0.375,    0.,    0.,    0.,  0.75,    0.,    0.,    0.}, // 6
    {-0.125,    0.,    0.,-0.125,    0.,    0.,   0.5,  0.25,    0.,   0.5}, // 7
    {    0.,-0.125,    0.,-0.125,    0.,   0.5,    0.,    0.,  0.25,   0.5}, // 8
    {    0.,    0., 0.375,-0.125,    0.,    0.,    0.,    0.,    0.,  0.75}  // 9
  },
  { // embedding matrix for child 3
    //    0      1      2      3      4      5      6      7      8      9
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.}, // 0
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.}, // 1
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.}, // 2
    {    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.,    0.,    0.}, // 3
    {-0.125,-0.125,    0.,    0.,  0.25,    0.,    0.,   0.5,   0.5,    0.}, // 4
    {    0.,-0.125,-0.125,    0.,    0.,  0.25,    0.,    0.,   0.5,   0.5}, // 5
    {-0.125,    0.,-0.125,    0.,    0.,    0.,  0.25,   0.5,    0.,   0.5}, // 6
    {-0.125,    0.,    0., 0.375,    0.,    0.,    0.,  0.75,    0.,    0.}, // 7
    {    0.,-0.125,    0., 0.375,    0.,    0.,    0.,    0.,  0.75,    0.}, // 8
    {    0.,    0.,-0.125, 0.375,    0.,    0.,    0.,    0.,    0.,  0.75}  // 9
  },
  {// embedding matrix for child 4
    //    0      1      2      3      4      5      6      7      8      9
    {    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.,    0.}, // 0
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.}, // 1
    {    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.}, // 2
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.}, // 3
    {-0.125,    0.,    0.,-0.125,   0.5,    0.,    0.,  0.25,   0.5,    0.}, // 4
    {-0.125,-0.125,-0.125,-0.125,  0.25,  0.25,  0.25,  0.25,  0.25,  0.25}, // 5
    {    0.,-0.125,-0.125,    0.,   0.5,  0.25,   0.5,    0.,    0.,    0.}, // 6
    {    0.,-0.125,    0.,-0.125,   0.5,    0.,    0.,   0.5,  0.25,    0.}, // 7
    {-0.125,-0.125,    0.,    0.,  0.25,    0.,    0.,   0.5,   0.5,    0.}, // 8
    {    0.,    0.,-0.125,-0.125,    0.,    0.,   0.5,   0.5,    0.,  0.25}  // 9
  },
  { // embedding matrix for child 5
    //    0      1      2      3      4      5      6      7      8      9
    {    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.,    0.}, // 0
    {    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.}, // 1
    {    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.}, // 2
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.}, // 3
    {-0.125,    0.,-0.125,    0.,   0.5,   0.5,  0.25,    0.,    0.,    0.}, // 4
    {-0.125,-0.125,    0.,    0.,  0.25,   0.5,   0.5,    0.,    0.,    0.}, // 5
    {    0.,-0.125,-0.125,    0.,   0.5,  0.25,   0.5,    0.,    0.,    0.}, // 6
    {-0.125,    0.,    0.,-0.125,   0.5,    0.,    0.,  0.25,   0.5,    0.}, // 7
    {    0.,    0.,-0.125,-0.125,    0.,   0.5,    0.,    0.,   0.5,  0.25}, // 8
    {-0.125,-0.125,-0.125,-0.125,  0.25,  0.25,  0.25,  0.25,  0.25,  0.25}  // 9
  },
  // embedding matrix for child 6
  {
    //    0      1      2      3      4      5      6      7      8      9
    {    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.}, // 0
    {    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.,    0.}, // 1
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.}, // 2
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.}, // 3
    {-0.125,-0.125,    0.,    0.,  0.25,   0.5,   0.5,    0.,    0.,    0.}, // 4
    {    0.,-0.125,    0.,-0.125,    0.,   0.5,    0.,    0.,  0.25,   0.5}, // 5
    {-0.125,    0.,    0.,-0.125,    0.,    0.,   0.5,  0.25,    0.,   0.5}, // 6
    {-0.125,-0.125,-0.125,-0.125,  0.25,  0.25,  0.25,  0.25,  0.25,  0.25}, // 7
    {    0.,    0.,-0.125,-0.125,    0.,   0.5,    0.,    0.,   0.5,  0.25}, // 8
    {    0.,-0.125,-0.125,    0.,    0.,  0.25,    0.,    0.,   0.5,   0.5}  // 9
  },
  {// embedding matrix for child 7
    //    0      1      2      3      4      5      6      7      8      9
    {    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.,    0.}, // 0
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.}, // 1
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.}, // 2
    {    0.,    0.,    0.,    0.,    0.,    0.,    0.,    1.,    0.,    0.}, // 3
    {-0.125,-0.125,-0.125,-0.125,  0.25,  0.25,  0.25,  0.25,  0.25,  0.25}, // 4
    {    0.,-0.125,-0.125,    0.,    0.,  0.25,    0.,    0.,   0.5,   0.5}, // 5
    {-0.125,    0.,    0.,-0.125,    0.,    0.,   0.5,  0.25,    0.,   0.5}, // 6
    {    0.,    0.,-0.125,-0.125,    0.,    0.,   0.5,   0.5,    0.,  0.25}, // 7
    {-0.125,-0.125,    0.,    0.,  0.25,    0.,    0.,   0.5,   0.5,    0.}, // 8
    {-0.125,    0.,-0.125,    0.,    0.,    0.,  0.25,   0.5,    0.,   0.5}  // 9
  }
};



} //end namespace femus


