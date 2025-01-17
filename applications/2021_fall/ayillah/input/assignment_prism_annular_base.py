#!/usr/bin/env python

###
### This file is generated automatically by SALOME v9.7.0 with dump python functionality
###

import sys
import salome

salome.salome_init()
import salome_notebook
notebook = salome_notebook.NoteBook()
sys.path.insert(0, r'/home/student/software/femus/applications/2021_fall/ayillah/input')

####################################################
##       Begin of NoteBook variables section      ##
####################################################
notebook.set("n_inner", 6)
notebook.set("n_radial_layers", 1)
notebook.set("z_offset", 1)
notebook.set("n_inner", 6)
notebook.set("n_radial_layers", 1)
notebook.set("z_offset", 1)
####################################################
##        End of NoteBook variables section       ##
####################################################
###
### GEOM component
###

import GEOM
from salome.geom import geomBuilder
import math
import SALOMEDS


geompy = geomBuilder.New()

O = geompy.MakeVertex(0, 0, 0)
OX = geompy.MakeVectorDXDYDZ(1, 0, 0)
OY = geompy.MakeVectorDXDYDZ(0, 1, 0)
OZ = geompy.MakeVectorDXDYDZ(0, 0, 1)
Disk_1 = geompy.MakeDiskR(1, 1)
Disk_2 = geompy.MakeDiskR(0.5, 1)
Cut_1 = geompy.MakeCutList(Disk_1, [Disk_2], True)
[Edge_1,Edge_2] = geompy.ExtractShapes(Cut_1, geompy.ShapeType["EDGE"], True)
[Edge_1, Edge_2] = geompy.GetExistingSubObjects(Cut_1, False)
[Edge_1, Edge_2] = geompy.GetExistingSubObjects(Cut_1, False)
Pipe_1 = geompy.MakePipe(Cut_1, OZ)
Face_1 = geompy.GetSubShape(Pipe_1, [10])
Face_2 = geompy.GetSubShape(Pipe_1, [15])
Face_3 = geompy.GetSubShape(Pipe_1, [20])
Face_4 = geompy.GetSubShape(Pipe_1, [3])
geompy.addToStudy( O, 'O' )
geompy.addToStudy( OX, 'OX' )
geompy.addToStudy( OY, 'OY' )
geompy.addToStudy( OZ, 'OZ' )
geompy.addToStudy( Disk_1, 'Disk_1' )
geompy.addToStudy( Disk_2, 'Disk_2' )
geompy.addToStudy( Cut_1, 'Cut_1' )
geompy.addToStudyInFather( Cut_1, Edge_1, 'Edge_1' )
geompy.addToStudyInFather( Cut_1, Edge_2, 'Edge_2' )
geompy.addToStudy( Pipe_1, 'Pipe_1' )
geompy.addToStudyInFather( Pipe_1, Face_1, 'Face_1' )
geompy.addToStudyInFather( Pipe_1, Face_2, 'Face_2' )
geompy.addToStudyInFather( Pipe_1, Face_3, 'Face_3' )
geompy.addToStudyInFather( Pipe_1, Face_4, 'Face_4' )

###
### SMESH component
###

import  SMESH, SALOMEDS
from salome.smesh import smeshBuilder

smesh = smeshBuilder.New()
#smesh.SetEnablePublish( False ) # Set to False to avoid publish in study if not needed or in some particular situations:
                                 # multiples meshes built in parallel, complex and numerous mesh edition (performance)

Number_of_Segments_1 = smesh.CreateHypothesis('NumberOfSegments')
Number_of_Segments_1.SetNumberOfSegments( "n_inner" )
Number_of_Segments_1.SetReversedEdges( [] )
Number_of_Segments_1.SetObjectEntry( "Cut_1" )
Number_of_Segments_2 = smesh.CreateHypothesis('NumberOfSegments')
Number_of_Segments_2.SetNumberOfSegments( "n_radial_layers" )
Number_of_Segments_2.SetReversedEdges( [] )
Number_of_Segments_2.SetObjectEntry( "Cut_1" )
Mesh_1 = smesh.Mesh(Cut_1)
Regular_1D = Mesh_1.Segment(geom=Edge_1)
Number_of_Segments_3 = Regular_1D.NumberOfSegments("n_inner")
Propagation_of_1D_Hyp = Regular_1D.Propagation()
QuadFromMedialAxis_1D2D = Mesh_1.Quadrangle(algo=smeshBuilder.QUAD_MA_PROJ)
Number_of_Layers_1 = QuadFromMedialAxis_1D2D.NumberOfLayers("n_radial_layers")
isDone = Mesh_1.Compute()
Groupremove_1_0 = Mesh_1.GroupOnGeom(Edge_1,'Group_1_0',SMESH.EDGE)
[ smeshObj_1, smeshObj_2, Groupremove_1_0 ] = Mesh_1.GetGroups()
Groupremove_2_0 = Mesh_1.GroupOnGeom(Edge_2,'Group_2_0',SMESH.EDGE)
[ smeshObj_1, smeshObj_2, Groupremove_1_0, Groupremove_2_0 ] = Mesh_1.GetGroups()
[ smeshObj_3, smeshObj_4, smeshObj_5, smeshObj_6 ] = Mesh_1.ExtrusionSweepObjects( [ Mesh_1 ], [], [ Mesh_1 ], [ 0, 0, 10 ], 1, 1, [  ], 0, [  ], [  ], 0 )
[ smeshObj_1, smeshObj_2, Groupremove_1_0, Groupremove_2_0, smeshObj_3, smeshObj_4, smeshObj_5, smeshObj_6 ] = Mesh_1.GetGroups()
[ smeshObj_7, smeshObj_8, smeshObj_9, smeshObj_10, smeshObj_11, smeshObj_12, smeshObj_13, smeshObj_14 ] = Mesh_1.ExtrusionSweepObjects( [ Mesh_1 ], [], [ Mesh_1 ], [ 0, 0, 10 ], 1, 1, [  ], 0, [  ], [  ], 0 )
[ smeshObj_1, smeshObj_2, Groupremove_1_0, Groupremove_2_0, smeshObj_3, smeshObj_4, smeshObj_5, smeshObj_6, smeshObj_7, smeshObj_11, smeshObj_8, smeshObj_12, smeshObj_9, smeshObj_13, smeshObj_10, smeshObj_14 ] = Mesh_1.GetGroups()
[ smeshObj_15, smeshObj_16, smeshObj_17, smeshObj_18, smeshObj_19, smeshObj_20, smeshObj_21, smeshObj_22 ] = Mesh_1.ExtrusionSweepObjects( [ Mesh_1 ], [], [ Mesh_1 ], [ 0, 0, 10 ], 1, 1, [  ], 0, [  ], [  ], 0 )
[ smeshObj_1, smeshObj_2, Groupremove_1_0, Groupremove_2_0, smeshObj_3, smeshObj_4, smeshObj_5, smeshObj_6, smeshObj_7, smeshObj_11, smeshObj_8, smeshObj_12, smeshObj_9, smeshObj_13, smeshObj_10, smeshObj_14, smeshObj_15, smeshObj_19, smeshObj_16, smeshObj_20, smeshObj_17, smeshObj_21, smeshObj_18, smeshObj_22 ] = Mesh_1.GetGroups()
Mesh_1.RemoveGroup( smeshObj_11 )
Mesh_1.RemoveGroup( smeshObj_12 )
Mesh_1.RemoveGroup( smeshObj_20 )
Mesh_1.RemoveGroup( smeshObj_19 )
Groupremove_1_0.SetName( 'Group_1_0_rm' )
Groupremove_2_0.SetName( 'Group_2_0_rm' )
smeshObj_13.SetName( 'Group_1_0_top_rm' )
smeshObj_14.SetName( 'Group_2_0_top_rm' )
smeshObj_21.SetName( 'Group_1_0_top_rm' )
smeshObj_22.SetName( 'Group_2_0_top_rm' )
Mesh_1.RemoveGroup( smeshObj_4 )
Mesh_1.RemoveGroup( smeshObj_3 )
Mesh_1.RemoveGroup( smeshObj_8 )
Mesh_1.RemoveGroup( smeshObj_7 )
Mesh_1.RemoveGroup( smeshObj_16 )
Mesh_1.RemoveGroup( smeshObj_15 )
Mesh_1.RemoveGroup( smeshObj_10 )
Mesh_1.RemoveGroup( smeshObj_9 )
Mesh_1.RemoveGroup( smeshObj_6 )
Mesh_1.RemoveGroup( smeshObj_5 )
Mesh_1.RemoveGroup( smeshObj_14 )
Mesh_1.RemoveGroup( smeshObj_13 )
smeshObj_17.SetName( 'Group_1_0' )
smeshObj_18.SetName( 'Group_2_0' )
[ Groupremove_1_0, Groupremove_2_0, smeshObj_17, smeshObj_21, smeshObj_18, smeshObj_22 ] = Mesh_1.GetGroups()
Mesh_1.RemoveGroup( smeshObj_18 )
Mesh_1.RemoveGroup( smeshObj_17 )
[ Groupremove_1_0, Groupremove_2_0, smeshObj_21, smeshObj_22 ] = Mesh_1.GetGroups()
isDone = Mesh_1.Compute()
[ Groupremove_1_0, Groupremove_2_0, smeshObj_21, smeshObj_22 ] = Mesh_1.GetGroups()
Mesh_1.ConvertToQuadratic(0, Mesh_1,True)
[ Group_1_0, Group_2_0 ] = Mesh_1.ExtrusionSweepObjects( [ Mesh_1 ], [], [ Mesh_1 ], [ 0, 0, 1 ], 1, 1, [  ], 0, [  ], [  ], 0 )
Mesh_1.RemoveGroup( smeshObj_21 )
Mesh_1.RemoveGroup( smeshObj_22 )
[ Groupremove_1_0, Groupremove_2_0, Group_1_0, Group_2_0 ] = Mesh_1.GetGroups()
Group_3_0 = Mesh_1.CreateEmptyGroup( SMESH.FACE, 'Group_3_0' )
nbAdd = Group_3_0.Add( [ 65, 70, 75, 80, 85, 90 ] )
[ Groupremove_1_0, Groupremove_2_0, Group_1_0, Group_2_0, Group_3_0 ] = Mesh_1.GetGroups()
Group_4_0 = Mesh_1.CreateEmptyGroup( SMESH.FACE, 'Group_4_0' )
nbAdd = Group_4_0.Add( [ 13, 14, 15, 16, 17, 18 ] )
[ Groupremove_1_0, Groupremove_2_0, Group_1_0, Group_2_0, Group_3_0, Group_4_0 ] = Mesh_1.GetGroups()
Group_2_0.SetName( 'Group_2_0' )
Group_1_0.SetName( 'Group_1_0' )
Groupremove_2_0.SetName( 'Groupremove_2_0_rm' )
Groupremove_1_0.SetName( 'Groupremove_1_0_rm' )
Groupremove_1_0.SetName( 'Groupremove_1_0' )
Groupremove_2_0.SetName( 'Groupremove_2_0' )
[ Groupremove_1_0, Groupremove_2_0, Group_1_0, Group_2_0, Group_3_0, Group_4_0 ] = Mesh_1.GetGroups()
smesh.SetName(Mesh_1, 'Mesh_1')
try:
  Mesh_1.ExportMED(r'/home/student/software/femus/applications/2021_fall/ayillah/input/prism_annular_base.med',auto_groups=0,version=41,overwrite=1,meshPart=None,autoDimension=0)
  pass
except:
  print('ExportMED() failed. Invalid file name?')
Number_of_Segments_4 = smesh.CreateHypothesis('NumberOfSegments')
Number_of_Segments_4.SetNumberOfSegments( 4 )
Mesh_2 = smesh.Mesh(Pipe_1)
Number_of_Segments_5 = smesh.CreateHypothesis('NumberOfSegments')
Number_of_Segments_5.SetNumberOfSegments( "n_inner" )
NETGEN_3D_Parameters_1 = smesh.CreateHypothesis('NETGEN_Parameters_3D', 'NETGENEngine')
NETGEN_3D_Parameters_1.SetMaxSize( 0.3 )
NETGEN_3D_Parameters_1.SetMinSize( 0.120537 )
NETGEN_3D_Parameters_1.SetOptimize( 1 )
NETGEN_3D_Parameters_1.SetFineness( 2 )
NETGEN_3D_Parameters_1.SetElemSizeWeight( 3.65848e+146 )
NETGEN_3D_Parameters_1.SetCheckOverlapping( 0 )
NETGEN_3D_Parameters_1.SetCheckChartBoundary( 64 )
NETGEN_2D_Parameters_1 = smesh.CreateHypothesis('NETGEN_Parameters_2D_ONLY', 'NETGENEngine')
NETGEN_2D_Parameters_1.SetMaxSize( 0.3 )
NETGEN_2D_Parameters_1.SetMinSize( 0.120537 )
NETGEN_2D_Parameters_1.SetOptimize( 1 )
NETGEN_2D_Parameters_1.SetFineness( 2 )
NETGEN_2D_Parameters_1.SetChordalError( -1 )
NETGEN_2D_Parameters_1.SetChordalErrorEnabled( 0 )
NETGEN_2D_Parameters_1.SetUseSurfaceCurvature( 1 )
NETGEN_2D_Parameters_1.SetWorstElemMeasure( 0 )
NETGEN_2D_Parameters_1.SetUseDelauney( 0 )
NETGEN_2D_Parameters_1.SetQuadAllowed( 0 )
NETGEN_2D_Parameters_1.SetCheckChartBoundary( 112 )
Propagation_of_1D_Hyp_1 = smesh.CreateHypothesis('Propagation')
Max_Element_Volume_1 = smesh.CreateHypothesis('MaxElementVolume')
Max_Element_Volume_1.SetMaxElementVolume( 0.027 )
Regular_1D_1 = Mesh_2.Segment()
Number_of_Segments_6 = Regular_1D_1.NumberOfSegments("n_inner")
Quadratic_Mesh_1 = Regular_1D_1.QuadraticMesh()
NETGEN_2D = Mesh_2.Triangle(algo=smeshBuilder.NETGEN_2D)
NETGEN_2D_Parameters_2 = NETGEN_2D.Parameters()
NETGEN_2D_Parameters_2.SetMaxSize( 0.3 )
NETGEN_2D_Parameters_2.SetMinSize( 0.120537 )
NETGEN_2D_Parameters_2.SetOptimize( 1 )
NETGEN_2D_Parameters_2.SetFineness( 2 )
NETGEN_2D_Parameters_2.SetChordalError( -1 )
NETGEN_2D_Parameters_2.SetChordalErrorEnabled( 0 )
NETGEN_2D_Parameters_2.SetUseSurfaceCurvature( 1 )
NETGEN_2D_Parameters_2.SetWorstElemMeasure( 0 )
NETGEN_2D_Parameters_2.SetUseDelauney( 0 )
NETGEN_2D_Parameters_2.SetQuadAllowed( 0 )
NETGEN_2D_Parameters_2.SetCheckChartBoundary( 176 )
NETGEN_3D = Mesh_2.Tetrahedron()
NETGEN_3D_Parameters_2 = NETGEN_3D.Parameters()
NETGEN_3D_Parameters_2.SetMaxSize( 0.3 )
NETGEN_3D_Parameters_2.SetMinSize( 0.120537 )
NETGEN_3D_Parameters_2.SetOptimize( 1 )
NETGEN_3D_Parameters_2.SetFineness( 2 )
NETGEN_3D_Parameters_2.SetElemSizeWeight( 3.65848e+146 )
NETGEN_3D_Parameters_2.SetCheckOverlapping( 0 )
NETGEN_3D_Parameters_2.SetCheckChartBoundary( 144 )
status = Mesh_2.RemoveHypothesis(Regular_1D)
status = Mesh_2.RemoveHypothesis(NETGEN_2D)
status = Mesh_2.RemoveHypothesis(NETGEN_3D)
status = Mesh_2.RemoveHypothesis(Number_of_Segments_6)
status = Mesh_2.RemoveHypothesis(Quadratic_Mesh_1)
status = Mesh_2.RemoveHypothesis(NETGEN_2D_Parameters_2)
NETGEN_1D_2D_3D = Mesh_2.Tetrahedron(algo=smeshBuilder.NETGEN_1D2D3D)
status = Mesh_2.RemoveHypothesis(NETGEN_3D_Parameters_2)
NETGEN_3D_Parameters_1_1 = NETGEN_1D_2D_3D.Parameters()
NETGEN_3D_Parameters_1_1.SetMaxSize( 0.3 )
NETGEN_3D_Parameters_1_1.SetMinSize( 0.120537 )
NETGEN_3D_Parameters_1_1.SetSecondOrder( 0 )
NETGEN_3D_Parameters_1_1.SetOptimize( 1 )
NETGEN_3D_Parameters_1_1.SetFineness( 2 )
NETGEN_3D_Parameters_1_1.SetChordalError( -1 )
NETGEN_3D_Parameters_1_1.SetChordalErrorEnabled( 0 )
NETGEN_3D_Parameters_1_1.SetUseSurfaceCurvature( 1 )
NETGEN_3D_Parameters_1_1.SetFuseEdges( 1 )
NETGEN_3D_Parameters_1_1.SetQuadAllowed( 0 )
NETGEN_3D_Parameters_1_1.SetCheckChartBoundary( 208 )
Mesh_1.ConvertToQuadratic(0, Mesh_2,True)
Mesh_1.ConvertToQuadratic(0)
Mesh_1.ConvertToQuadratic(0, Mesh_2,True)
Mesh_1.ConvertToQuadratic(0)
isDone = Mesh_2.Compute()
Mesh_1.ConvertToQuadratic(0)
Group_1_0_1 = Mesh_2.GroupOnGeom(Face_1,'Group_1_0',SMESH.FACE)
[ Group_1_0_1 ] = Mesh_2.GetGroups()
Group_2_0_1 = Mesh_2.GroupOnGeom(Face_2,'Group_2_0',SMESH.FACE)
[ Group_1_0_1, Group_2_0_1 ] = Mesh_2.GetGroups()
Group_3_0_1 = Mesh_2.GroupOnGeom(Face_3,'Group_3_0',SMESH.FACE)
[ Group_1_0_1, Group_2_0_1, Group_3_0_1 ] = Mesh_2.GetGroups()
Group_4_0_1 = Mesh_2.GroupOnGeom(Face_4,'Group_4_0',SMESH.FACE)
[ Group_1_0_1, Group_2_0_1, Group_3_0_1, Group_4_0_1 ] = Mesh_2.GetGroups()
Sub_mesh_1 = Mesh_1.GetSubMesh( Edge_1, 'Sub-mesh_1' )

## some objects were removed
aStudyBuilder = salome.myStudy.NewBuilder()
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_16))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_17))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_18))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_15))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_10))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_3))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_5))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_4))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_7))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_6))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_14))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_9))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_19))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_8))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_21))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_20))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_22))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_1))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_2))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_11))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_12))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)
SO = salome.myStudy.FindObjectIOR(salome.myStudy.ConvertObjectToIOR(smeshObj_13))
if SO: aStudyBuilder.RemoveObjectWithChildren(SO)

## Set names of Mesh objects
smesh.SetName(Group_4_0_1, 'Group_4_0')
smesh.SetName(Group_2_0_1, 'Group_2_0')
smesh.SetName(Group_3_0_1, 'Group_3_0')
smesh.SetName(Group_1_0_1, 'Group_1_0')
smesh.SetName(NETGEN_2D_Parameters_2, 'NETGEN 2D Parameters_2')
smesh.SetName(NETGEN_3D_Parameters_2, 'NETGEN 3D Parameters_2')
smesh.SetName(Propagation_of_1D_Hyp_1, 'Propagation of 1D Hyp. on Opposite Edges_1')
smesh.SetName(Max_Element_Volume_1, 'Max. Element Volume_1')
smesh.SetName(NETGEN_3D_Parameters_1_1, 'NETGEN 3D Parameters_1')
smesh.SetName(Number_of_Segments_6, 'Number of Segments_6')
smesh.SetName(Quadratic_Mesh_1, 'Quadratic Mesh_1')
smesh.SetName(Group_1_0, 'Group_1_0')
smesh.SetName(Group_2_0, 'Group_2_0')
smesh.SetName(Group_3_0, 'Group_3_0')
smesh.SetName(Group_4_0, 'Group_4_0')
smesh.SetName(Regular_1D.GetAlgorithm(), 'Regular_1D')
smesh.SetName(QuadFromMedialAxis_1D2D.GetAlgorithm(), 'QuadFromMedialAxis_1D2D')
smesh.SetName(NETGEN_2D.GetAlgorithm(), 'NETGEN 2D')
smesh.SetName(NETGEN_3D.GetAlgorithm(), 'NETGEN 3D')
smesh.SetName(NETGEN_1D_2D_3D.GetAlgorithm(), 'NETGEN 1D-2D-3D')
smesh.SetName(Mesh_1.GetMesh(), 'Mesh_1')
smesh.SetName(Mesh_2.GetMesh(), 'Mesh_2')
smesh.SetName(Groupremove_1_0, 'Groupremove_1_0')
smesh.SetName(Groupremove_2_0, 'Groupremove_2_0')
smesh.SetName(Number_of_Segments_2, 'Number of Segments_2')
smesh.SetName(Propagation_of_1D_Hyp, 'Propagation of 1D Hyp. on Opposite Edges_2')
smesh.SetName(Number_of_Segments_1, 'Number of Segments_1')
smesh.SetName(Number_of_Segments_5, 'Number of Segments_5')
smesh.SetName(Number_of_Segments_4, 'Number of Segments_4')
smesh.SetName(Number_of_Layers_1, 'Number of Layers_1')
smesh.SetName(Number_of_Segments_3, 'Number of Segments_3')
smesh.SetName(NETGEN_2D_Parameters_1, 'NETGEN 2D Parameters_1')
smesh.SetName(Sub_mesh_1, 'Sub-mesh_1')
smesh.SetName(NETGEN_3D_Parameters_1, 'NETGEN 3D Parameters_1')


if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser()
