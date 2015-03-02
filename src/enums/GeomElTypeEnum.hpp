#ifndef __femus_enums_GeomElTypeEnum_hpp__
#define __femus_enums_GeomElTypeEnum_hpp__


enum  GeomElType { HEX=0, 
                   TET,   //1
		   WEDGE, //2
		   QUAD,  //3
		   TRI,   //4
		   LINE   //5
  
                 };

#define N_GEOM_ELS 6
		 
#define LEV_PICK  0


#endif