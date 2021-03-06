// !!! This is a generated file, do not edit !!!
#ifndef _PXZ_ALGO_INTERFACE_ALGOINTERFACE_H_
#define _PXZ_ALGO_INTERFACE_ALGOINTERFACE_H_

#include "AlgoTypes.h"

PXZ_MODULE_BEGIN(AlgoI)

class PXZ_EXPORTED AlgoInterface
{
public:
   //! Assemble faces of CAD shapes
   /*!
     \param occurrences Occurrences of components to assemble
     \param tolerance Assembling tolerance
     \param removeDuplicatedFaces If True, duplicated faces will be removed
   */
   static void assembleCAD(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & tolerance, const CoreI::Boolean & removeDuplicatedFaces = true);

   //! Create the BRep shape from a Tessellated shape with Domain Patch Attributes (after tessellate)
   /*!
     \param occurrences Occurrences of components to process
   */
   static void backToInitialBRep(const SceneI::OccurrenceList & occurrences);

   //! bakes impostors textures
   /*!
     \param occurrence 
     \param XFrames 
     \param YFrames 
     \param hemi 
     \param resolution 
     \param padding 
     \param roughness 
     \param metallic 
     \param ao 
     \return octahedralImp The structure containing impostor data
   */
   static OctahedralImpostor bakeImpostor(const SceneI::Occurrence & occurrence, const CoreI::Int & XFrames, const CoreI::Int & YFrames, const CoreI::Bool & hemi = false, const CoreI::Int & resolution = 1024, const CoreI::Int & padding = 0, const CoreI::Boolean & roughness = false, const CoreI::Boolean & metallic = false, const CoreI::Boolean & ao = false);

   //! Bake vertex attributes on meshes from other meshes
   /*!
     \param destinationOccurrences Occurrences of the meshes where to store the baked vertex attributes
     \param sourceOccurrences Occurrences of components from which to bake vertex attributes
     \param skinnedMesh Enabling skinned mesh baking (joint assignation for animation transfert)
     \param positions Enabling vertex position baking
     \param useCurrentPositionAsTPose Use the current position as the T-Pose
   */
   static void bakeVertexAttributes(const SceneI::OccurrenceList & destinationOccurrences, const SceneI::OccurrenceList & sourceOccurrences, const CoreI::Boolean & skinnedMesh, const CoreI::Boolean & positions, const CoreI::Boolean & useCurrentPositionAsTPose = false);

   //! calculate the normal of each point of a Point Cloud
   /*!
     \param occurrences Occurrences of part to process
   */
   static void calculateNormalsInPointClouds(const SceneI::OccurrenceList & occurrences);

   //! Explode and (re)merge a set of mesh parts by visible materials
   /*!
     \param occurrences Occurrences of the parts to merge
     \param mergeNoMaterials If true, merge all parts with no active material together, else do not merge them
     \param mergeHiddenPartsMode Hidden parts handling mode, Destroy them, make visible or merge separately
     \return mergedOccurrences Resulting occurrences of the merged parts
   */
   static SceneI::OccurrenceList combineMeshesByMaterials(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & mergeNoMaterials = true, const SceneI::MergeHiddenPartsMode & mergeHiddenPartsMode = SceneI::MergeHiddenPartsMode::Destroy);

   //! Create instances when there are similar parts.
   /*!
     \param occurrences Occurrence for which we want to find similar parts and create instances using prototypes.
     \param checkMeshTopo 
     \param checkVertexPositions 
     \param vertexPositionPrecision 
     \param checkUVTopo 
     \param checkUVVertexPositions 
     \param UVPositionprecision 
     \param keepExistingPrototypes 
   */
   static void convertSimilarOccurencesToInstances(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & checkMeshTopo, const CoreI::Boolean & checkVertexPositions, const CoreI::Int & vertexPositionPrecision, const CoreI::Boolean & checkUVTopo, const CoreI::Boolean & checkUVVertexPositions, const CoreI::Int & UVPositionprecision, const CoreI::Boolean & keepExistingPrototypes);

   //! Explode each mesh to approximated convex decomposition
   /*!
     \param occurrences Occurrences of part to process
     \param maxCount Maximum number of convex hull to generated
     \param vertexCount Maximum number of vertices per convex hull
     \param approximate Approximate method
     \param resolution Resolution
     \param concavity Concavity
   */
   static void convexDecomposition(const SceneI::OccurrenceList & occurrences, const CoreI::Int & maxCount, const CoreI::Int & vertexCount, const CoreI::Boolean & approximate, const CoreI::Int & resolution = 100000, const CoreI::Double & concavity = 0.001);

   //! crack polygonal edges according to given criteria
   /*!
     \param occurrences Occurrences of components to process
     \param useAttributesFilter Filters by attribute
     \param useSharpEdgeFilter Filters by edge sharpness.
     \param sharpAngleFilter Sharp angle, if negative the default sharp angle value is used
     \param useNonManifoldFilter Filters by manifold-ness.
   */
   static void crackEdges(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & useAttributesFilter = true, const CoreI::Boolean & useSharpEdgeFilter = false, const GeomI::Angle & sharpAngleFilter = -1, const CoreI::Boolean & useNonManifoldFilter = false);

   //! Create free edges from patch borders
   /*!
     \param occurrences Occurrences of components to process
   */
   static void createFreeEdgesFromPatches(const SceneI::OccurrenceList & occurrences);

   //! Create identified patch from existing patch (this is usefull before cloning for baking)
   /*!
     \param occurrences Occurrences of components to process
   */
   static void createIdentifiedPatchesFromPatches(const SceneI::OccurrenceList & occurrences);

   //! Create instances when there are similar parts. This can be used to repair instances or to simplify a model that has similar parts that could be instanciated instead to reduce the number of unique meshes (reduces drawcalls, GPU memory usage and file size). Using 1.0 (100%) in all similarity criterias is non destructive. Using lower values will help finding more similar parts, even if their polycount or dimensions varies a bit.
   /*!
     \param occurrences Occurrence for which we want to find similar parts and create instances using prototypes.
     \param dimensionsSimilarity The percentage of similarity on dimensions. A value of 1.0 (100%) will find parts that have exactly the same dimensions. A lower value will increase the likelyhood to find similar parts, at the cost of precision.
     \param polycountSimilarity The percentage of similarity on polycount. A value of 1.0 (100%) will find parts that have exactly the same polycount. A lower value will increase the likelyhood to find similar parts, at the cost of precision.
     \param ignoreSymmetry If True, symmetries will be ignored, otherwise negative scaling will be applied in the occurrence transformation.
     \param keepExistingPrototypes If True, existing prototypes will be kept. Otherwise, the selection will be singularized and instanced will be created from scratch.
     \param createNewOccurrencesForPrototypes If True, a new occurrence will be created for each prototype. Those occurrences won't appear in the hierarchy, and so deleting one of the part in the scene has no risks of singularizing. If set to False, an arbitrary occurrence will be used as the prototype for other similar occurrences, which is less safe but will result in less occurrences.
   */
   static void createInstancesBySimilarity(const SceneI::OccurrenceList & occurrences, const CoreI::Coeff & dimensionsSimilarity, const CoreI::Coeff & polycountSimilarity, const CoreI::Boolean & ignoreSymmetry, const CoreI::Boolean & keepExistingPrototypes, const CoreI::Boolean & createNewOccurrencesForPrototypes);

   //! Create normal attributes on tessellations
   /*!
     \param occurrences Occurrences of components to create attributes
     \param sharpEdge Edges with an angle between their polygons greater than sharpEdge will be considered sharp (default use the Pixyz sharpAngle parameter)
     \param override If true, override existing normals, else only create normals on meshes without normals
     \param useAreaWeighting If true, normal computation will be weighted using polygon areas
   */
   static void createNormals(const SceneI::OccurrenceList & occurrences, const GeomI::Angle & sharpEdge = -1, const CoreI::Boolean & override = true, const CoreI::Boolean & useAreaWeighting = false);

   //! Create tangent attributes on tessellations
   /*!
     \param occurrences Occurrences of components to create attributes
     \param sharpEdge Edges with an angle between their polygons greater than sharpEdge will be considered sharp (default use the Pixyz sharpAngle parameter)
     \param uvChannel UV channel to use for the tangents creation
     \param override If true, override existing tangents, else only create tangents on meshes without tangents
   */
   static void createTangents(const SceneI::OccurrenceList & occurrences, const GeomI::Angle & sharpEdge = -1, const CoreI::Int & uvChannel = 0, const CoreI::Boolean & override = true);

   //! Create visibility patches from existing patches
   /*!
     \param occurrences Occurrences of components to process
   */
   static void createVisibilityPatchesFromPatch(const SceneI::OccurrenceList & occurrences);

   //! reduce the polygon count by removing some vertices
   /*!
     \param occurrences Occurrences of components to process
     \param surfacicTolerance Maximum distance between surfacic vertices and resulting simplified surfaces
     \param lineicTolerance Maximum distance between lineic vertices and resulting simplified lines
     \param normalTolerance Maximum angle between original normals and those interpolated on the simplified surface
     \param texCoordTolerance Maximum distance (in UV space) between original texcoords and those interpolated on the simplified surface
     \param releaseConstraintOnSmallArea If True, release constraint of normal and/or texcoord tolerance on small areas (according to surfacicTolerance)
   */
   static void decimate(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & surfacicTolerance, const GeomI::Distance & lineicTolerance = 0.1, const GeomI::Angle & normalTolerance = 5, const CoreI::Double & texCoordTolerance = -1, const CoreI::Boolean & releaseConstraintOnSmallArea = false);

   //! reduce the polygon count by collapsing some edges to obtain an simplified mesh
   /*!
     \param occurrences Occurrences of components to process
     \param surfacicTolerance Error max between the simplified mesh et the old one
     \param boundaryWeight Boundary importance during the decimation
     \param normalWeight Normal importance during the decimation
     \param UVWeight UV importance during the decimation
     \param sharpNormalWeight Importance of sharp edges during the decimation
     \param UVSeamWeight Importance of UV seams during the decimation
     \param normalMaxDeviation Constraint the normals deviation on decimated model
     \param forbidUVOverlaps Forbid UV to fold over and overlap during the decimation
     \param UVMaxDeviation Constraint the uv deviation on decimated model
     \param UVSeamMaxDeviation Constraint the uv seams deviation on decimated model
     \param protectTopology If false, the topology of the mesh can change and some edges can become non-manifold. But the visual quality will be better on model with complex topology
     \param qualityTradeoff For big models it is recommanded to choose PreferSpeed tradeoff. In PreferSpeed mode, quadrics are computed only on position (and not on other vertex attributes)
   */
   static void decimateEdgeCollapse(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & surfacicTolerance, const CoreI::Double & boundaryWeight = 1., const CoreI::Double & normalWeight = 1., const CoreI::Double & UVWeight = 1., const CoreI::Double & sharpNormalWeight = 1., const CoreI::Double & UVSeamWeight = 10., const GeomI::Angle & normalMaxDeviation = -1, const CoreI::Boolean & forbidUVOverlaps = true, const CoreI::Double & UVMaxDeviation = -1, const CoreI::Double & UVSeamMaxDeviation = -1, const CoreI::Boolean & protectTopology = false, const QualitySpeedTradeoff & qualityTradeoff = QualitySpeedTradeoff::PreferQuality);

   //! decimate Point Cloud Occurences according to tolerance 
   /*!
     \param occurrences Occurrences of part to process
     \param tolerance Avarage distance between points
   */
   static void decimatePointClouds(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & tolerance = 500);

   //! reduce the polygon count by collapsing some edges to obtain a target triangle count (iterative version that use less memory)
   /*!
     \param occurrences List of occurrences to process
     \param targetStrategy Select between targetCount or ratio to define the number of triangles left after the decimation process
     \param UVImportance Select importance of texture coordinates
     \param protectTopology If False, the topology of the mesh can change and some edges can become non-manifold
     \param iterativeThreshold Number of triangles above which the iterative algorithm is used to limit the memory usage
   */
   static void decimateTarget(const SceneI::OccurrenceList & occurrences, const DecimateOptionsSelector & targetStrategy, const UVImportanceEnum & UVImportance = UVImportanceEnum::PreserveSeamsAndReduceDeformation, const CoreI::Boolean & protectTopology = false, const CoreI::Int & iterativeThreshold = 5000000);

   //! Delete designed attribute on tessellations
   /*!
     \param occurrence Occurrence to detele attribute from
     \param type Attribute type
   */
   static void deleteAttibute(const SceneI::Occurrence & occurrence, const AttributType & type);

   //! Delete BRep representation on parts
   /*!
     \param occurrences Occurrences of components to process
     \param onlyTessellated If True, delete only BRep represensation on part with a tessellated shape
   */
   static void deleteBRepShapes(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & onlyTessellated = true);

   //! Delete all free vertices of the mesh of given parts
   /*!
     \param occurrences Occurrences of components to process
   */
   static void deleteFreeVertices(const SceneI::OccurrenceList & occurrences);

   //! Delete all free line of the mesh of given parts
   /*!
     \param occurrences Occurrences of components to process
   */
   static void deleteLines(const SceneI::OccurrenceList & occurrences);

   //! Remove normal attributes on tessellations
   /*!
     \param occurrences Occurrences of components to delete
   */
   static void deleteNormals(const SceneI::OccurrenceList & occurrences);

   //! Delete patches attributes on tessellations
   /*!
     \param occurrences Occurrences of components to process
     \param keepOnePatchByMaterial If set, one patch by material will be kept, else all patches will be deleted and materials on patches will be lost
   */
   static void deletePatches(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & keepOnePatchByMaterial = true);

   //! Delete all polygons of the mesh of given parts
   /*!
     \param occurrences Occurrences of components to process
   */
   static void deletePolygons(const SceneI::OccurrenceList & occurrences);

   //! Remove tangent attributes on tessellations
   /*!
     \param occurrences Occurrences of components to delete
   */
   static void deleteTangents(const SceneI::OccurrenceList & occurrences);

   //! Delete texture coordinates on tessellations
   /*!
     \param occurrences Occurrences of components to process
     \param channel Choose Texture coordinates channel to delete (-1 for all channels)
   */
   static void deleteTextureCoordinates(const SceneI::OccurrenceList & occurrences, const CoreI::Int & channel = -1);

   //! delete the visibility patches of given occurrences
   /*!
     \param occurrences Occurrences of components to process
   */
   static void deleteVisibilityPatches(const SceneI::OccurrenceList & occurrences);

   //! returns the max error to set to reach a given target
   /*!
     \param occurrences List of occurrences to process
     \param TargetStrategy Select between targetCount or ratio to define the number of triangles left after the decimation process
     \param boundaryWeight Defines how important the edges defining the mesh boundaries (free edges) are during the decimation process, to preserve them from distortion
     \param normalWeight Defines how important vertex normals are during the decimation process, to preserve the smoothing of the mesh from being damaged
     \param UVWeight Defines how important UVs (texture coordinates) are during the decimation process, to preserve them from being distorted (along with the textures using the UVs)
     \param sharpNormalWeight Defines how important sharp edges (or hard edges) are during the decimation process, to preserve them from being distorted
     \param UVSeamWeight Defines how important UV seams (UV islands contours) are during the decimation process, to preserve them from being distorted (along with the textures using the UVs)
     \param forbidUVFoldovers Forbids UVs to fold over and overlap each other during the decimation
     \param protectTopology If False, the topology of the mesh can change and some edges can become non-manifold; but the visual quality will be better on model with complex topology
     \return errorMax Max error that can be used in decimateEdgeCollapse function
   */
   static CoreI::Double evalDecimateErrorForTarget(const SceneI::OccurrenceList & occurrences, const DecimateOptionsSelector & TargetStrategy, const CoreI::Double & boundaryWeight = 1., const CoreI::Double & normalWeight = 1., const CoreI::Double & UVWeight = 1., const CoreI::Double & sharpNormalWeight = 1., const CoreI::Double & UVSeamWeight = 10., const CoreI::Boolean & forbidUVFoldovers = true, const CoreI::Boolean & protectTopology = false);

   //! Explode all CAD Parts by body
   /*!
     \param occurrences Occurrences of part to process
     \param groupOpenShells Group all open shells in one part
   */
   static void explodeBodies(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & groupOpenShells = false);

   //! Explode connected set of polygons to parts
   /*!
     \param occurrences Occurrences of part to process
   */
   static void explodeConnectedMeshes(const SceneI::OccurrenceList & occurrences);

   //! Explode all parts by material
   /*!
     \param occurrences Occurrences of part to process
   */
   static void explodePartByMaterials(const SceneI::OccurrenceList & occurrences);

   //! Explode all parts by patch
   /*!
     \param occurrences Occurrences of part to process
   */
   static void explodePatches(const SceneI::OccurrenceList & occurrences);

   //! Explode parts to respect a maximum vertex count
   /*!
     \param occurrences Occurrences of part to process
     \param maxVertexCount The maximum number of vertices by part
     \param maxTriangleCount The maximum number of triangles by part (quadrangles count twice)
     \param countMergedVerticesOnce If true, one vertex used in several triangles with different normals will be counted once (for Unity must be False)
   */
   static void explodeVertexCount(const SceneI::OccurrenceList & occurrences, const CoreI::Int & maxVertexCount, const CoreI::Int & maxTriangleCount, const CoreI::Boolean & countMergedVerticesOnce = true);

   //! Explode parts by voxel
   /*!
     \param occurrences Occurrences of part to process
     \param voxelSize Voxel size
   */
   static void explodeVoxel(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize);

   //! Extract neutral axis from tessellations
   /*!
     \param occurrences Occurrences of components to process
     \param maxDiameter Maximum diameter of beams
     \param removeOriginalMesh Remove or not the original mesh at the end of the algorithm
   */
   static void extractNeutralAxis(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxDiameter, const CoreI::Boolean & removeOriginalMesh);

   //! returns all the tessellation of the given occurrences (only returns editable mesh, see algo.toEditableMesh)
   /*!
     \param occurrences Occurrences of components to process
     \return tessellations All the tessellation of the given occurrences
   */
   static PolygonalI::TessellationList getTessellations(const SceneI::OccurrenceList & occurrences);

   //! returns the visibility statistics for some occurrences
   /*!
     \param occurrences Occurrences of components to process
     \return visibleCountFront 
     \return visibleCountBack 
   */
   static getVisibilityStatsReturn getVisibilityStats(const SceneI::OccurrenceList & occurrences);

   //! Create cad patches on tessellation (needed by some functions)
   /*!
     \param occurrences Occurrences of components to process
     \param useAttributesFilter Filters by attributes
     \param useSharpEdgeFilter Filters by edge sharpness
     \param sharpAngle Sharp angle in degree, if negative the default sharp angle value is used
     \param useBoundaryFilter Filters by boundaries
     \param useNonManifoldFilter Filters by manifold-ness
     \param useLineEdgeFilter Filters by edge
     \param useQuadLineFilter Filters by quad lines
   */
   static void identifyPatches(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & useAttributesFilter = true, const CoreI::Boolean & useSharpEdgeFilter = false, const GeomI::Angle & sharpAngle = -1, const CoreI::Boolean & useBoundaryFilter = true, const CoreI::Boolean & useNonManifoldFilter = true, const CoreI::Boolean & useLineEdgeFilter = true, const CoreI::Boolean & useQuadLineFilter = false);

   //! Generate a textured quadrangle over an existing mesh of coplanar lines
   /*!
     \param lines Lines to select
     \param useColor Set color policy.
     \param resolution Texture resolution
     \param thickness The thickness of the lines in pixels
   */
   static void lineToTexture(const SceneI::OccurrenceList & lines, const UseColorOption & useColor, const CoreI::Int & resolution = 512, const CoreI::Int & thickness = 5);

   //! List features from tessellations
   /*!
     \param occurrences Occurrences of components to process
     \param throughHoles List through holes
     \param blindHoles List blind holes
     \param maxDiameter Maximum diameter of the holes to be list (-1=no max diameter)
     \return features List of features by occurrence
   */
   static OccurrenceFeaturesList listFeatures(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & throughHoles = true, const CoreI::Boolean & blindHoles = false, const GeomI::Distance & maxDiameter = -1);

   //! Replace the tessellations of the selected parts by a marching cube representation
   /*!
     \param occurrences Occurrences of part to process
     \param voxelSize Size of voxels
     \param elements Type of elements used to detect the voxels, polygons or points or hybrid
     \param dilation Dilation iterations on the voxel grid (only if surfacic=false)
     \param surfacic Prefer this mode if the source is surfacic, the result is not guaranteed to be watertight
     \return marchingCubePart Resulting part occurrence
   */
   static SceneI::Occurrence marchingCubes(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize, const ElementFilter & elements = ElementFilter::Polygons, const CoreI::Int & dilation = 0, const CoreI::Boolean & surfacic = false);

   //! merge near vertices according to the given distance
   /*!
     \param occurrences Occurrences of components to process
     \param maxDistance Maximum distance between two vertex to merge
     \param mask Topological category of the vertices to merge
   */
   static void mergeVertices(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxDistance, const PolygonalI::TopologyCategoryMask & mask);

   //! Apply noise to vertex positions along their normals
   /*!
     \param occurrences Occurrences of parts to noise
     \param maxAmplitude Maximum distance between original vertex and noisy vertex
   */
   static void noiseMesh(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxAmplitude);

   //! Optimize CAD Face loops by merging useless loop edges
   /*!
     \param occurrences Occurrences of components to optimize
   */
   static void optimizeCADLoops(const SceneI::OccurrenceList & occurrences);

   //! Optimize mesh for rendering (lossless, only reindexing)
   /*!
     \param occurrences Occurrences of components to optimize
   */
   static void optimizeForRendering(const SceneI::OccurrenceList & occurrences);

   //! Sort sub meshes by materials
   /*!
     \param occurrences Occurrences of parts to process
   */
   static void optimizeSubMeshes(const SceneI::OccurrenceList & occurrences);

   //! Resizes scene textures based on a number of texels per 3D space units (e.g: mm)
   /*!
     \param root Root from which texture resizing will process
     \param texelPerMm Number of texel per millimeter in a 3D space
   */
   static void optimizeTextureSize(const SceneI::Occurrence & root, const CoreI::Double & texelPerMm);

   //! Replace the tessellations of the selected parts by a proxy mesh based on a voxelization
   /*!
     \param occurrences Occurrences of part to process
     \param voxelSize Size of voxels
     \param elements Type of elements used to detect the voxels, polygons or points or hybrid
     \param dilation Dilation iterations on the voxel grid (only if surfacic=false)
     \param surfacic Prefer this mode if the source is surfacic, the result is not guaranteed to be watertight
     \return proxyMeshPart Resulting part occurrence
   */
   static SceneI::Occurrence proxyMesh(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize, const ElementFilter & elements = ElementFilter::Polygons, const CoreI::Int & dilation = 0, const CoreI::Boolean & surfacic = false);

   //! Remove some features from tessellations
   /*!
     \param occurrences Occurrences of components to process
     \param throughHoles Remove through holes
     \param blindHoles Remove blind holes
     \param surfacicHoles Remove surfacic holes
     \param maxDiameter Maximum diameter of the holes to be removed (-1=no max diameter)
     \param fillWithMaterial If set, the given material will be used to fill the holes
   */
   static void removeHoles(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & throughHoles, const CoreI::Boolean & blindHoles, const CoreI::Boolean & surfacicHoles, const GeomI::Distance & maxDiameter, const MaterialI::Material & fillWithMaterial = 0);

   //! Repair CAD shapes, assemble faces, remove duplicated faces, optimize loops and repair topology
   /*!
     \param occurrences Occurrences of components to clean
     \param tolerance Tolerance
     \param orient If true reorient the model
   */
   static void repairCAD(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & tolerance, const CoreI::Boolean & orient = true);

   //! Replace geometries by other shapes, or primitives
   /*!
     \param occurrences Occurrences of components to replace
     \param replaceBy Shape replacement option
   */
   static void replaceBy(const SceneI::OccurrenceList & occurrences, const ReplaceByOption & replaceBy);

   //! Replace objects by a bounding box
   /*!
     \param occurrences Occurrences of components to replace
     \param boxType Bounding box type, oriented, axis-aligned, ...
   */
   static void replaceByBox(const SceneI::OccurrenceList & occurrences, const ReplaceByBoxType & boxType);

   //! Replace objects by convex hull
   /*!
     \param occurrences Occurrences of components to replace
   */
   static void replaceByConvexHull(const SceneI::OccurrenceList & occurrences);

   //! Replace objects by a primitive shapes
   /*!
     \param occurrences Occurrences of components to replace
     \param primitive Primitive type and parameters
     \param generateUV Primitive type and parameters
   */
   static void replaceByPrimitive(const SceneI::OccurrenceList & occurrences, const PrimitiveShapeParameters & primitive, const CoreI::Boolean & generateUV = true);

   //! Update the tessellated representation of each CAD part with new tessellation parameters
   static CoreI::AutoValueReturn getAutoValuesForretessellateUsingretrieve(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxSag, const GeomI::Distance & maxLength, const GeomI::Angle & maxAngle, const CoreI::Boolean & createNormals = true, const UVGenerationMode & uvMode = UVGenerationMode::NoUV, const CoreI::Int & uvChannel = 1, const CoreI::Double & uvPadding = 0.0, const CoreI::Boolean & createTangents = false, const CoreI::Boolean & createFreeEdges = false);

   //! Update the tessellated representation of each CAD part with new tessellation parameters
   /*!
     \param occurrences Occurrences of components to tessellate
     \param maxSag Maximum distance between the geometry and the tessellation
     \param maxLength Maximum length of elements
     \param maxAngle Maximum angle between normals of two adjacent elements
     \param createNormals If true, normals will be generated
     \param uvMode Select the texture coordinates generation mode
     \param uvChannel The UV channel of the generated texture coordinates (if any)
     \param uvPadding The UV padding between UV island in UV coordinate space (between 0-1). This parameter is handled as an heuristic so it might not be respected
     \param createTangents If true, tangents will be generated
     \param createFreeEdges If true, free edges will be created for each patch borders
   */
   static void retessellate(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxSag, const GeomI::Distance & maxLength, const GeomI::Angle & maxAngle, const CoreI::Boolean & createNormals = true, const UVGenerationMode & uvMode = UVGenerationMode::NoUV, const CoreI::Int & uvChannel = 1, const CoreI::Double & uvPadding = 0.0, const CoreI::Boolean & createTangents = false, const CoreI::Boolean & createFreeEdges = false);

   //! Replace the tessellations of the selected parts by a retopology of the external hull
   /*!
     \param occurrences Occurrences of part to process
     \param targetTriangleCount Target triangle count
     \param pureQuad Retopologize to a pure quad mesh if True, else the resulting mesh will be quad dominant but can contains triangles
     \param pointCloud Set to true if occurrences are point cloud, else False
     \param precision If set, define the precision of the features to preserve
     \return retopologizedPart Resulting part occurrence
   */
   static SceneI::Occurrence retopologize(const SceneI::OccurrenceList & occurrences, const CoreI::Int & targetTriangleCount, const CoreI::Bool & pureQuad, const CoreI::Bool & pointCloud, const GeomI::Distance & precision = -1);

   //! Selects occurrences in the whole scene that are similar to the selected occurrences. If several occurrences are selected, the selection afterwards will contain similar parts for each input occurrence.
   /*!
     \param occurrences Occurrences for which we want to find similar occurrences in the scene.
     \param dimensionsSimilarity The percentage of similarity on dimensions. A value of 1.0 (100%) will find parts that have exactly the same dimensions. A lower value will increase the likelyhood to find similar parts, at the cost of precision.
     \param polycountSimilarity The percentage of similarity on polycount. A value of 1.0 (100%) will find parts that have exactly the same polycount. A lower value will increase the likelyhood to find similar parts, at the cost of precision.
     \param ignoreSymmetry If True, symmetries will be ignored, otherwise negative scaling will be applied in the occurrence transformation.
   */
   static void selectSimilar(const SceneI::OccurrenceList & occurrences, const CoreI::Coeff & dimensionsSimilarity, const CoreI::Coeff & polycountSimilarity, const CoreI::Boolean & ignoreSymmetry);

   /*!
     \param occurrences Occurrences of components to process
     \param mode Computation of cost
     \param maxIterations Maximum number of swapping iteration
     \param lockSignificantEdges Forbid to swap significant edges (e.g. UV seams, sharp edges, patch borders, ...)
   */
   static void smoothMesh(const SceneI::OccurrenceList & occurrences, const CostEvaluation & mode, const CoreI::Int & maxIterations = 100, const CoreI::Boolean & lockSignificantEdges = true);

   //! Extrudes a circular section along an underlying polyline (curve)
   /*!
     \param occurrences Occurrences of components to check
     \param radius Radius of cylinders
     \param sides Number of points to create cylinders
     \param createNormals 
     \param keepLines 
     \param generateUV 
   */
   static void sweep(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & radius, const CoreI::Int & sides, const CoreI::Boolean & createNormals, const CoreI::Boolean & keepLines, const CoreI::Boolean & generateUV);

   //! Create a tessellated representation from a CAD representation for each given part
   /*!
     \param occurrences Occurrences of components to tessellate
     \param maxSag Maximum distance between the geometry and the tessellation
     \param maxLength Maximum length of elements
     \param maxAngle Maximum angle between normals of two adjacent elements
     \param createNormals If true, normals will be generated
     \param uvMode Select the texture coordinates generation mode
     \param uvChannel The UV channel of the generated texture coordinates (if any)
     \param uvPadding The UV padding between UV island in UV coordinate space (between 0-1). This parameter is handled as an heuristic so it might not be respected
     \param createTangents If true, tangents will be generated
     \param createFreeEdges If true, free edges will be created for each patch borders
     \param keepBRepShape If true, BRep shapes will be kept for Back to Brep or Retessellate
     \param overrideExistingTessellation If true, already tessellated parts will be re-tessellated
   */
   static void tessellate(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxSag, const GeomI::Distance & maxLength, const GeomI::Angle & maxAngle, const CoreI::Boolean & createNormals = true, const UVGenerationMode & uvMode = UVGenerationMode::NoUV, const CoreI::Int & uvChannel = 1, const CoreI::Double & uvPadding = 0.0, const CoreI::Boolean & createTangents = false, const CoreI::Boolean & createFreeEdges = false, const CoreI::Boolean & keepBRepShape = true, const CoreI::Boolean & overrideExistingTessellation = false);

   //! Creates a tessellated representation from a CAD representation for each given part. It multiplies the length of the diagonal of the bounding box by the sagRatio. If the output value is above maxSag, then maxSag is used as tessellation value. Else if the output value is below maxSag, it is used as tessellation value.
   /*!
     \param occurrences Occurrences of components to tessellate
     \param maxSag Maximum distance between the geometry and the tessellation
     \param sagRatio Maximum ratio distance between the geometry and the tessellation
     \param maxLength Maximum length of elements
     \param maxAngle Maximum angle between normals of two adjacent elements
     \param createNormals If true, normals will be generated
     \param uvMode Select the texture coordinates generation mode
     \param uvChannel The UV channel of the generated texture coordinates (if any)
     \param uvPadding The UV padding between UV island in UV coordinate space (between 0-1). This parameter is handled as an heuristic so it might not be respected
     \param createTangents If true, tangents will be generated
     \param createFreeEdges If true, free edges will be created for each patch borders
     \param keepBRepShape If true, BRep shapes will be kept for Back to Brep or Retessellate
     \param overrideExistingTessellation If true, already tessellated parts will be re-tessellated
   */
   static void tessellateRelativelyToAABB(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxSag, const CoreI::Double & sagRatio, const GeomI::Distance & maxLength, const GeomI::Angle & maxAngle, const CoreI::Boolean & createNormals = true, const UVGenerationMode & uvMode = UVGenerationMode::NoUV, const CoreI::Int & uvChannel = 1, const CoreI::Double & uvPadding = 0.0, const CoreI::Boolean & createTangents = false, const CoreI::Boolean & createFreeEdges = false, const CoreI::Boolean & keepBRepShape = true, const CoreI::Boolean & overrideExistingTessellation = false);

   //! Replace the tessellations of the selected parts by a voxelization of the external skin
   /*!
     \param occurrences Occurrences of part to process
     \param voxelSize Size of voxels
     \param elements Type of elements used to detect the voxels, polygons or points or hybrid
     \param dilation Dilation iterations on the voxel grid
     \param useCurrentAnimationPosition Use the current animation position instead of the t-pose
     \return voxelizedPart Resulting part occurrence
   */
   static SceneI::Occurrence voxelize(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize, const ElementFilter & elements = ElementFilter::Polygons, const CoreI::Int & dilation = 0, const CoreI::Boolean & useCurrentAnimationPosition = false);

   //! Explode point clouds to voxels
   /*!
     \param occurrences Occurrences of part to process
     \param voxelSize Size of voxels
   */
   static void voxelizePointClouds(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize = 500);


   /**
    * \defgroup Baking 
    * @{
    */
   //! Bake UV from a mesh to another mesh
   /*!
     \param source Occurrence of the source mesh
     \param destination Occurrence of the destination mesh
     \param sourceChannel Source UV channel to bake
     \param destinationChannel Destination UV channel to bake to
     \param tolerance Tolerance when point is projected on seam (if the model come from a decimation it is recommanded to use the lineic tolerance here)
   */
   static void bakeUV(const SceneI::Occurrence & source, const SceneI::Occurrence & destination, const CoreI::Int & sourceChannel = 0, const CoreI::Int & destinationChannel = 0, const GeomI::Distance & tolerance = 0.001);

   //! Combine all given meshes to one mesh with one material (baked)
   /*!
     \param occurrences Occurrences of part to process
     \param bakingOptions Baking options
     \param overrideExistingUVs If True, overide existing UVs on channel
     \return occurrence 
   */
   static SceneI::Occurrence combineMeshes(const SceneI::OccurrenceList & occurrences, const BakeOption & bakingOptions, const CoreI::Boolean & overrideExistingUVs = false);

   /**@}*/

   /**
    * \defgroup Hidden Detection All hidden part detection/removal related function
    * @{
    */
   //! Create visilibity information on parts viewed from a set of camera automatically placed on a sphere around the scene
   /*!
     \param occurrences Occurrences of components to process
     \param level Level of parts to remove : Parts, Patches or Polygons
     \param resolution Resolution of the visibility viewer
     \param sphereCount Segmentation of the sphere sphereCount x sphereCount
     \param fovX Horizontal field of view (in degree)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
   */
   static void createVisibilityInformation(const SceneI::OccurrenceList & occurrences, const SelectionLevel & level, const CoreI::Int & resolution, const CoreI::Int & sphereCount, const CoreI::Double & fovX = 90, const CoreI::Boolean & considerTransparentOpaque = false);

   //! Create visilibity information on parts viewed from a given set of camera
   /*!
     \param occurrences Occurrences of components to process
     \param cameraPositions List of camera positions
     \param cameraDirections List of camera directions
     \param cameraUps List of camera up vectors
     \param resolution Resolution of the visibility viewer
     \param fovX Horizontal field of view (in degree)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
   */
   static void createVisibilityInformationFromViewPoints(const SceneI::OccurrenceList & occurrences, const GeomI::Point3List & cameraPositions, const GeomI::Point3List & cameraDirections, const GeomI::Point3List & cameraUps, const CoreI::Int & resolution, const CoreI::Double & fovX = 90, const CoreI::Boolean & considerTransparentOpaque = false);

   //! Return parts occurrences not viewed from a sphere around the scene
   /*!
     \param occurrences Occurrences of components to process
     \param resolution Resolution of the visibility viewer
     \param sphereCount Segmentation of the sphere sphereCount x sphereCount
     \param fovX Horizontal field of view (in degree)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
     \return hiddenOccurrences Hidden occurrences
   */
   static SceneI::OccurrenceList getHiddenOccurrences(const SceneI::OccurrenceList & occurrences, const CoreI::Int & resolution, const CoreI::Int & sphereCount, const CoreI::Double & fovX = 90, const CoreI::Boolean & considerTransparentOpaque = false);

   //! Delete parts, patches or polygons not viewed from a sphere around the scene
   /*!
     \param occurrences Occurrences of components to process
     \param level Level of parts to remove : Parts, Patches or Polygons
     \param resolution Resolution of the visibility viewer
     \param sphereCount Segmentation of the sphere sphereCount x sphereCount
     \param fovX Horizontal field of view (in degree)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
     \param adjacencyDepth Mark neighbors polygons as visible
     \return viewedOccurrences For each occurrence in occurrences, tell if the occurrence has been viewed (True) or not (True)
   */
   static CoreI::BoolList hiddenRemoval(const SceneI::OccurrenceList & occurrences, const SelectionLevel & level, const CoreI::Int & resolution, const CoreI::Int & sphereCount, const CoreI::Double & fovX = 90, const CoreI::Boolean & considerTransparentOpaque = false, const CoreI::Int & adjacencyDepth = 1);

   //! Delete parts, patches or polygons not viewed from spheres generated with a set of camera position
   /*!
     \param occurrences Occurrences of components to process
     \param level Level of parts to remove : Parts, Patches or Polygons
     \param cameraPositions List of camera positions
     \param resolution Resolution of the visibility viewer
     \param sphereCount Segmentation of the sphere sphereCount x sphereCount
     \param fovX Horizontal field of view (in degree)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
     \param adjacencyDepth Mark neighbors polygons as visible
     \return viewedOccurrences For each occurrence in occurrences, tell if the occurrence has been viewed (True) or not (True)
   */
   static CoreI::BoolList hiddenRemovalCamera(const SceneI::OccurrenceList & occurrences, const SelectionLevel & level, const GeomI::Point3List & cameraPositions, const CoreI::Int & resolution, const CoreI::Int & sphereCount, const CoreI::Double & fovX = 90, const CoreI::Boolean & considerTransparentOpaque = false, const CoreI::Int & adjacencyDepth = 1);

   //! Delete parts, patches or polygons not viewed from a set of camera position/orientation
   /*!
     \param occurrences Occurrences of components to process
     \param level Level of parts to remove : Parts, Patches or Polygons
     \param cameraPositions List of camera positions
     \param cameraDirections List of camera directions
     \param cameraUps List of camera up vectors
     \param resolution Resolution of the visibility viewer
     \param fovX Horizontal field of view (in degree)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
     \param adjacencyDepth Mark neighbors polygons as visible
     \return viewedOccurrences For each occurrence in occurrences, tell if the occurrence has been viewed (True) or not (True)
   */
   static CoreI::BoolList hiddenRemovalViewPoints(const SceneI::OccurrenceList & occurrences, const SelectionLevel & level, const GeomI::Point3List & cameraPositions, const GeomI::Point3List & cameraDirections, const GeomI::Point3List & cameraUps, const CoreI::Int & resolution, const CoreI::Double & fovX = 90, const CoreI::Boolean & considerTransparentOpaque = false, const CoreI::Int & adjacencyDepth = 1);

   //! Select parts not viewed from a sphere around the scene
   /*!
     \param occurrences Occurrences of components to process
     \param resolution Resolution of the visibility viewer
     \param sphereCount Segmentation of the sphere sphereCount x sphereCount
     \param fovX Horizontal field of view (in degree)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
   */
   static void hiddenSelection(const SceneI::OccurrenceList & occurrences, const CoreI::Int & resolution, const CoreI::Int & sphereCount, const CoreI::Double & fovX = 90, const CoreI::Boolean & considerTransparentOpaque = false);

   //! Create visilibity information on parts viewed from a set of camera automatically generated
   /*!
     \param occurrences Occurrences of components to process
     \param voxelSize Size of the voxels in mm (smaller it is, more viewpoints there are)
     \param minimumCavityVolume Minimum volume of a cavity in cubic meter (smaller it is, more viewpoints there are)
     \param resolution Resolution of the visibility viewer
     \param mode Select where to place camera (all cavities, only outer or only inner cavities)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
   */
   static void smartHiddenCreateVisibilityInformation(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize, const GeomI::Volume & minimumCavityVolume, const CoreI::Int & resolution, const SmartHiddenType & mode = SmartHiddenType::All, const CoreI::Boolean & considerTransparentOpaque = false);

   //! Delete parts, patches or polygons not viewed from a set of camera automatically generated
   /*!
     \param occurrences Occurrences of components to process
     \param level Level of parts to remove : Parts, Patches or Polygons
     \param voxelSize Size of the voxels in mm (smaller it is, more viewpoints there are)
     \param minimumCavityVolume Minimum volume of a cavity in cubic meter (smaller it is, more viewpoints there are)
     \param resolution Resolution of the visibility viewer
     \param mode Select where to place camera (all cavities, only outer or only inner cavities)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
     \param adjacencyDepth Mark neighbors polygons as visible
     \return viewedOccurrences For each occurrence in occurrences, tell if the occurrence has been viewed (True) or not (True)
   */
   static CoreI::BoolList smartHiddenRemoval(const SceneI::OccurrenceList & occurrences, const SelectionLevel & level, const GeomI::Distance & voxelSize, const GeomI::Volume & minimumCavityVolume, const CoreI::Int & resolution, const SmartHiddenType & mode = SmartHiddenType::All, const CoreI::Boolean & considerTransparentOpaque = false, const CoreI::Int & adjacencyDepth = 1);

   //! Select parts not viewed from a set of camera automatically generated
   /*!
     \param occurrences Occurrences of components to process
     \param voxelSize Size of the voxels in mm (smaller it is, more viewpoints there are)
     \param minimumCavityVolume Minimum volume of a cavity in cubic meter (smaller it is, more viewpoints there are)
     \param resolution Resolution of the visibility viewer
     \param mode Select where to place camera (all cavities, only outer or only inner cavities)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
   */
   static void smartHiddenSelection(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize, const GeomI::Volume & minimumCavityVolume, const CoreI::Int & resolution, const SmartHiddenType & mode = SmartHiddenType::All, const CoreI::Boolean & considerTransparentOpaque = false);

   /**@}*/

   /**
    * \defgroup Sawing 
    * @{
    */
   //! Saw the mesh with an axis-aligned bounding box
   /*!
     \param occurrences Occurrences of part to process
     \param aabb Axis-Aligned Bounding Box
     \param mode The sawing mode
     \param innerSuffix Only if mode is set to SawAndSplit, set the suffix of the inner part
     \param outerSuffix Only if mode is set to SawAndSplit, set the suffix of the outer part
   */
   static void sawWithAABB(const SceneI::OccurrenceList & occurrences, const GeomI::AABB & aabb, const SawingMode & mode, const CoreI::String & innerSuffix = "_inner", const CoreI::String & outerSuffix = "_outer");

   //! Saw the mesh with an oriented bounding box
   /*!
     \param occurrences Occurrences of part to process
     \param obb Minimum Bounding Box
     \param mode The sawing mode
     \param innerSuffix Only if mode is set to SawAndSplit, set the suffix of the inner part
     \param outerSuffix Only if mode is set to SawAndSplit, set the suffix of the outer part
   */
   static void sawWithOBB(const SceneI::OccurrenceList & occurrences, const GeomI::OBB & obb, const SawingMode & mode, const CoreI::String & innerSuffix = "_inner", const CoreI::String & outerSuffix = "_outer");

   //! Saw the mesh with a plane
   /*!
     \param occurrences Occurrences of part to process
     \param planeOrigin The plane origin
     \param planeNormal The plane normal
     \param mode The sawing mode
     \param innerSuffix Only if mode is set to SawAndSplit, set the suffix of the inner part
     \param outerSuffix Only if mode is set to SawAndSplit, set the suffix of the outer part
   */
   static void sawWithPlane(const SceneI::OccurrenceList & occurrences, const GeomI::Point3 & planeOrigin, const GeomI::Vector3 & planeNormal, const SawingMode & mode, const CoreI::String & innerSuffix = "_inner", const CoreI::String & outerSuffix = "_outer");

   /**@}*/

   /**
    * \defgroup UV Mapping 
    * @{
    */
   //! Apply a transformation matrix on texture coordinates
   /*!
     \param occurrences Occurrences of part to process
     \param matrix Transformationmatrix
     \param channel UV channel to transform
   */
   static void applyUvTransform(const SceneI::OccurrenceList & occurrences, const GeomI::Matrix4 & matrix, const CoreI::Int & channel = 0);

   //! Generates the texture coordinates and automatically cut
   /*!
     \param occurrences Occurrences of part to process
     \param channel The UV channel which will contains the texture coordinates
     \param maxAngleDistorsion Maximum angle distorsion |2PI-SumVtxAng|/2PI
     \param maxAreaDistorsion Maximum area distorsion before scale to 1. |2DArea-3DArea|/3DArea 
     \param sharpToSeam If enabled, sharp edges are automatically considered as UV seams
     \param forbidOverlapping If enabled, UV cannot overlap
   */
   static void automaticUVMapping(const SceneI::OccurrenceList & occurrences, const CoreI::Int & channel = 0, const CoreI::Double & maxAngleDistorsion = 0.5, const CoreI::Double & maxAreaDistorsion = -1, const CoreI::Bool & sharpToSeam = true, const CoreI::Bool & forbidOverlapping = true);

   //! Copy an UV channel to another UV channel
   /*!
     \param occurrences Occurrences of part to process
     \param sourceChannel The source UV channel to copy
     \param destinationChannel The destination UV channel to copy into
   */
   static void copyUV(const SceneI::OccurrenceList & occurrences, const CoreI::Int & sourceChannel = 0, const CoreI::Int & destinationChannel = 0);

   //! Generate texture coordinates using the projection on object Axis Aligned Bounding Box
   /*!
     \param occurrences Occurrences of part to process
     \param useLocalAABB If enabled, uses part own bounding box, else use global one
     \param uv3dSize 3D size of the UV space [0-1]
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
   */
   static void mapUvOnAABB(const SceneI::OccurrenceList & occurrences, const CoreI::Bool & useLocalAABB, const GeomI::Distance & uv3dSize, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a box
   static CoreI::AutoValueReturn getAutoValuesFormapUvOnBoxUsingfit(const SceneI::OccurrenceList & occurrences, const Box & box, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a box
   /*!
     \param occurrences Occurrences of part to process
     \param box Box definition
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
   */
   static void mapUvOnBox(const SceneI::OccurrenceList & occurrences, const Box & box, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on object AABB, with same scale on each axis
   /*!
     \param occurrences Occurrences of part to process
     \param uv3dSize 3D size of the UV space [0-1]
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
   */
   static void mapUvOnCubicAABB(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & uv3dSize, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on custom AABB
   /*!
     \param occurrences Occurrences of part to process
     \param aabb Axis aligned bounding box to project on
     \param uv3dSize 3D size of the UV space [0-1]
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
   */
   static void mapUvOnCustomAABB(const SceneI::OccurrenceList & occurrences, const GeomI::AABB & aabb, const GeomI::Distance & uv3dSize, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a cylinder
   static CoreI::AutoValueReturn getAutoValuesFormapUvOnCylinderUsingfit(const SceneI::OccurrenceList & occurrences, const Cylinder & cylinder, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a cylinder
   /*!
     \param occurrences Occurrences of part to process
     \param cylinder Cylinder definition
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
   */
   static void mapUvOnCylinder(const SceneI::OccurrenceList & occurrences, const Cylinder & cylinder, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a fitting cylinder
   /*!
     \param occurrences Occurrences of part to process
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
     \param useAABB If true use for the fitting the global Axis Aligned Bounding Box (AABB), else use a Minimum Bounding Box (MBB only based on transformed AABB of occurrences)
   */
   static void mapUvOnFittingCylinder(const SceneI::OccurrenceList & occurrences, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true, const CoreI::Boolean & useAABB = true);

   //! Generate texture coordinates using the projection on a fitting sphere
   /*!
     \param occurrences Occurrences of part to process
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
     \param useAABB If true use for the fitting the global Axis Aligned Bounding Box (AABB), else use a Minimum Bounding Box (MBB only based on transformed AABB of occurrences)
   */
   static void mapUvOnFittingSphere(const SceneI::OccurrenceList & occurrences, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true, const CoreI::Boolean & useAABB = true);

   //! Generate texture coordinates using the projection on object Minimum Bounding Box
   /*!
     \param occurrences Occurrences of part to process
     \param useLocalMBB If enabled, uses part own bounding box, else use global one
     \param uv3dSize 3D size of the UV space [0-1]
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
   */
   static void mapUvOnMBB(const SceneI::OccurrenceList & occurrences, const CoreI::Bool & useLocalMBB, const GeomI::Distance & uv3dSize, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a plane
   static CoreI::AutoValueReturn getAutoValuesFormapUvOnPlaneUsingfit(const SceneI::OccurrenceList & occurrences, const Plane & plane, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a plane
   /*!
     \param occurrences Occurrences of part to process
     \param plane Plane definition
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
   */
   static void mapUvOnPlane(const SceneI::OccurrenceList & occurrences, const Plane & plane, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a sphere
   static CoreI::AutoValueReturn getAutoValuesFormapUvOnSphereUsingfit(const SceneI::OccurrenceList & occurrences, const Sphere & sphere, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Generate texture coordinates using the projection on a sphere
   /*!
     \param occurrences Occurrences of part to process
     \param sphere Sphere definition
     \param channel The UV channel which will contains the texture coordinates
     \param overrideExistingUVs If True, overide existing UVs on channel
   */
   static void mapUvOnSphere(const SceneI::OccurrenceList & occurrences, const Sphere & sphere, const CoreI::Int & channel = 0, const CoreI::Boolean & overrideExistingUVs = true);

   //! Normalize UVs to fit in the [0-1] uv space
   /*!
     \param occurrences Occurrences of part to process
     \param sourceUVChannel UV Channel to normalize
     \param destinationUVChannel UV channel to store the normalized UV (if -1, sourceUVChannel will be replaced)
     \param uniform If true, the scale will be uniform. Else UV can be deformed with a non-uniform scale
     \param sharedUVSpace If true, all parts will be processed as if they were merged to avoid overlapping of their UV coordinates
     \param ignoreNullIslands If true, islands with null height and width will be ignored and their UV coordinates will be set to [0,0] (Slower if enabled)
   */
   static void normalizeUV(const SceneI::OccurrenceList & occurrences, const CoreI::Int & sourceUVChannel, const CoreI::Int & destinationUVChannel = -1, const CoreI::Boolean & uniform = true, const CoreI::Boolean & sharedUVSpace = true, const CoreI::Boolean & ignoreNullIslands = false);

   //! Relax UVs
   /*!
     \param occurrences Occurrences of part to process
     \param method What the method used to relax is based on
     \param iterations Number of relax iterations
     \param channel The UV channel to repack
   */
   static void relaxUV(const SceneI::OccurrenceList & occurrences, const RelaxUVMethod & method, const CoreI::Int & iterations = 100, const CoreI::Int & channel = 0);

   //! Remove one or all UV channel(s)
   /*!
     \param occurrences Occurrences of part to process
     \param channel The UV channel to remove (all if channel=-1)
   */
   static void removeUV(const SceneI::OccurrenceList & occurrences, const CoreI::Int & channel = -1);

   //! Pack existing UV (create atlas)
   /*!
     \param occurrences Occurrences of part to process
     \param channel The UV channel to repack
     \param shareMap If True, the UV of all given parts will be packed together
     \param resolution Resolution wanted for the final map
     \param padding Set the padding (in pixels) between UV islands
     \param uniformRatio If true, UV of different part will have the same ratio
     \param iterations Fitting iterations
     \param removeOverlaps Remove overlaps to avoid multiple triangles UVs to share the same pixel
     \return failedParts Parts which failed to be repacked at this resolution (try to increase the resolution or decrease the padding)
   */
   static SceneI::OccurrenceList repackUV(const SceneI::OccurrenceList & occurrences, const CoreI::Int & channel = 0, const CoreI::Boolean & shareMap = true, const CoreI::Int & resolution = 1024, const CoreI::Int & padding = 2, const CoreI::Boolean & uniformRatio = false, const CoreI::Int & iterations = 3, const CoreI::Boolean & removeOverlaps = true);

   //! Apply a scale on texture coordinates
   /*!
     \param occurrences Occurrences of part to process
     \param scaleU Scale to apply to U coordinate
     \param scaleV Scale to apply to V coordinate
     \param channel UV channel to transform
   */
   static void scaleUV(const SceneI::OccurrenceList & occurrences, const CoreI::Double & scaleU, const CoreI::Double & scaleV, const CoreI::Int & channel = 0);

   //! Create UV patches with disk-like topology
   /*!
     \param occurrences Occurrences of part to process
     \param threshold Threshold of the front's Gaussian Curvature
     \param channel The UV channel to repack
   */
   static void segmentDiskFront(const SceneI::OccurrenceList & occurrences, const CoreI::Double & threshold = 25.0, const CoreI::Int & channel = 0);

   //! Smooth texture coordinates
   /*!
     \param occurrences Occurrences of part to process
     \param iterations Number of smooth iterations
     \param channel The UV channel which will contains the texture coordinates to smooth
   */
   static void smoothUV(const SceneI::OccurrenceList & occurrences, const CoreI::Int & iterations = 1, const CoreI::Int & channel = 0);

   //! Swap two UV channels
   /*!
     \param occurrences Occurrences of part to process
     \param firstChannel First UV Channel to swap
     \param secondChannel Second UV Channel to swap
   */
   static void swapUvChannels(const SceneI::OccurrenceList & occurrences, const CoreI::Int & firstChannel, const CoreI::Int & secondChannel);

   /**@}*/

   /**
    * \defgroup fitting 
    * @{
    */
   //! Returns the fitting cylinder of a set of occurrences (based on MBB)
   /*!
     \param occurrences Occurrences to fit
     \param useAABB If true use the global Axis Aligned Bounding Box (AABB), else use a Minimum Bounding Box MBB only based on transformed AABB of occurrences)
     \return affine Affine transformation of the cylinder
   */
   static GeomI::Affine getFittingCylinder(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & useAABB = true);

   //! Returns the fitting sphere of a set of occurrences
   /*!
     \param occurrences Occurrences to fit
     \param useAABB If true use the global Axis Aligned Bounding Box (AABB), else use a Minimum Bounding Box (MBB only based on transformed AABB of occurrences)
     \return affine Affine transformation of the sphere
   */
   static GeomI::Affine getFittingSphere(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & useAABB = true);

   /**@}*/

   /**
    * \defgroup map_generation Map Generation functions
    * @{
    */
   //! Bake texture maps on meshes from self or other meshes
   /*!
     \param destinationOccurrences Occurrences of the meshes where to store the baked map
     \param sourceOccurrences Occurrences of components from which to bake maps (if empty use destination)
     \param mapsToBake List of map to generate (Normal, Diffuse, ...)
     \param channel UV channel of destOccurrence to use for the map generation
     \param resolution Map resolution
     \param padding Add padding to the map
     \param shareMaps If true, all the destinationOccurrences will share the same maps
     \param mapSuffix Add a suffix to the map names
     \param additionalCustomMaps Additional custom maps to bake
     \param tolerance Tolerance of projection for baking from source to destination
     \param method Method to find source color if source occurrences are different than destination occurrences (Prefer ProjOnly for point clouds and RayOnly for meshes)
     \param opacityThreshold If the opacity is under this threshold, considers as fully transparent and store the color behind the intersection
     \param useCurrentPosition Use the current position instead of the T-Pose of the input occurrence
     \param offset Offset from mesh
     \param callbackList Callbacks that returns a color
     \return bakedMaps Baked map list
   */
   static MaterialI::ImageList bakeMaps(const SceneI::OccurrenceList & destinationOccurrences, const SceneI::OccurrenceList & sourceOccurrences, const BakeMapList & mapsToBake, const CoreI::Int & channel = 0, const CoreI::Int & resolution = 1024, const CoreI::Int & padding = 1, const CoreI::Boolean & shareMaps = true, const CoreI::String & mapSuffix = "", const CustomBakeMapList & additionalCustomMaps = CustomBakeMapList(0), const GeomI::Distance & tolerance = -1, const BakingMethod & method = BakingMethod::RayOnly, const CoreI::Coeff & opacityThreshold = 0.1, const CoreI::Boolean & useCurrentPosition = false, const GeomI::Distance & offset = 0, const getPixelValueList & callbackList = getPixelValueList(0));

   //! Convert an existing normal map between Object-space and Tangent-space
   /*!
     \param occurrences Occurrences of components using the given map
     \param normalMap Source normal map to convert
     \param uvChannel UV channel used on the given map
     \param sourceIsObjectSpace If True, consider the given normalMap in Object-space representation, else Tangent-space
     \param destinationIsObjectSpace If True, convert the given normalMap to Object-space representation, else Tangent-space
     \param sourceIsRightHanded Considers source normal map as part of a right-handed coordinates system
     \param destinationIsRightHanded Generate destination normal map as part of a right-handed coordinates system
     \param replaceMap If true, the given normalMap will be replaced by the converted one
     \param resolution New map resolution (if replaceMap=false), if resolution=-1, the input resolution will be used
     \param padding Number of pixels to add for padding
     \return convertedNormalMap Converted normal map (equals normalMap if replaceMap=true)
   */
   static MaterialI::Image convertNormalMap(const SceneI::OccurrenceList & occurrences, const MaterialI::Image & normalMap, const CoreI::Int & uvChannel = 0, const CoreI::Boolean & sourceIsObjectSpace = true, const CoreI::Boolean & destinationIsObjectSpace = false, const CoreI::Boolean & sourceIsRightHanded = true, const CoreI::Boolean & destinationIsRightHanded = true, const CoreI::Boolean & replaceMap = true, const CoreI::Int & resolution = -1, const CoreI::Int & padding = 1);

   //! Create a billboard imposter
   /*!
     \param occurrences Occurrences to bake in the billboard
     \param resolution Total resolution of the billboard (contains all wanted faces)
     \param XPositive Bake face facing X+
     \param XNegative Bake face facing X-
     \param YPositive Bake face facing Y+
     \param YNegative Bake face facing Y-
     \param ZPositive Bake face facing Z+
     \param ZNegative Bake face facing Z-
     \param moveFacesToCenter If true, all face are moved to the center of the AABB of the occurrences, else it will shape an AABB
     \param leftHandedNormalMap If true, a left handed normal map will be generated
     \return billboard Resulting billboard
   */
   static SceneI::Occurrence createBillboard(const SceneI::OccurrenceList & occurrences, const CoreI::Int & resolution = 1024, const CoreI::Bool & XPositive = true, const CoreI::Bool & XNegative = true, const CoreI::Bool & YPositive = true, const CoreI::Bool & YNegative = true, const CoreI::Bool & ZPositive = true, const CoreI::Bool & ZNegative = true, const CoreI::Bool & moveFacesToCenter = true, const CoreI::Bool & leftHandedNormalMap = false);

   //! Orient a tangent space normal map (all Z positive)
   /*!
     \param normalMap Normal map to orient
   */
   static void orientNormalMap(const MaterialI::Image & normalMap);

   /**@}*/

   /**
    * \defgroup repair Polygonal repair functions
    * @{
    */
   //! Smooth the tessellations by moving the vertices to the barycenter of their neighbors
   /*!
     \param occurrences Occurrences of components to process
     \param iteration Number of iterations
   */
   static void barySmooth(const SceneI::OccurrenceList & occurrences, const CoreI::Int & iteration);

   //! Remove moebius strip by topologically cracking them (make it orientable)
   /*!
     \param occurrences Occurrences of components to repair
     \param maxEdgeCount Maximum number of edges to crack to remove one moebius strip
   */
   static void crackMoebiusStrips(const SceneI::OccurrenceList & occurrences, const CoreI::Int & maxEdgeCount = 3);

   //! Splits non-manifold vertices
   /*!
     \param occurrences Occurrences of components to repair
   */
   static void crackNonManifoldVertices(const SceneI::OccurrenceList & occurrences);

   //! Identify cavities and create occurrences to show them
   /*!
     \param occurrences Occurrences set to identify cavities
     \param voxelSize Size of the voxels in mm
     \param minimumCavityVolume Minimum volume of a cavity in cubic meter
     \param mode Select where to place camera (all cavities, only outer or only inner cavities)
     \param parent The create occurrence root will be added under the parent if given, else it will be added under the deeper parent of given occurrences
     \return root Parent occurrence of the cavity occurrences
   */
   static SceneI::Occurrence createCavityOccurrences(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize, const GeomI::Volume & minimumCavityVolume, const SmartHiddenType & mode = SmartHiddenType::All, const SceneI::Occurrence & parent = SceneI::Occurrence());

   //! Invert the orientation of tessellation elements
   /*!
     \param occurrences Occurrences of components to process
   */
   static void invertOrientation(const SceneI::OccurrenceList & occurrences);

   //! Splits moebius ring
   /*!
     \param occurrences Occurrences of components to repair
   */
   static void moebiusCracker(const SceneI::OccurrenceList & occurrences);

   //! Orient tessellation elements
   /*!
     \param occurrences Occurrences of components to process
     \param makeOrientable Crack moebius strips to make the model orientable
     \param useArea Use the area instead of counting the number of triangle
     \param orientStrategy Strategy to adopt with this algorithm
   */
   static void orient(const SceneI::OccurrenceList & occurrences, const CoreI::Boolean & makeOrientable = true, const CoreI::Boolean & useArea = false, const OrientStrategy & orientStrategy = OrientStrategy::ExteriorOnly);

   //! Properly orient all polygons in the same direction, using a specified viewpoint
   /*!
     \param occurrences Occurrences to orient
     \param cameraPosition Camera position
     \param cameraDirection Camera direction
     \param cameraUp Camera up vector
     \param resolution Resolution of the visibility viewer
     \param fovX Horizontal field of view (in degree)
   */
   static void orientFromCamera(const SceneI::OccurrenceList & occurrences, const GeomI::Point3 & cameraPosition, const GeomI::Point3 & cameraDirection, const GeomI::Point3 & cameraUp, const CoreI::Int & resolution, const CoreI::Double & fovX = 90);

   //! Orient all connect polygones in the same orientation of the polygon selectionned
   static void orientFromFace();

   //! Orient existing normal according to the polygons clockwise
   /*!
     \param occurrences Occurrences of components to orient normals
   */
   static void orientNormals(const SceneI::OccurrenceList & occurrences);

   //! Resmesh surfacic holes of tessellations
   /*!
     \param occurrences Occurrences of components to process
     \param maxDiameter Maximum surfacic holes diameters
   */
   static void remeshSurfacicHoles(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxDiameter);

   //! Remove some kinds of degenerated polygons
   /*!
     \param occurrences Occurrences of components to process
     \param tolerance Degenerated tolerance
   */
   static void removeDegeneratedPolygons(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & tolerance);

   //! Remove multiple polygon
   /*!
     \param occurrences Occurrences of components to repair
   */
   static void removeMultiplePolygon(const SceneI::OccurrenceList & occurrences);

   //! Remove Z-fighting (surfaces overlaping) by slightly shrinking the selected parts' surfaces
   /*!
     \param occurrences Occurrences to process
     \return offset Offset value used by the algorithm
   */
   static GeomI::Distance removeZFighting(const SceneI::OccurrenceList & occurrences);

   //! Launch the repair process to repair a disconnected or not clean tessellation
   /*!
     \param occurrences Occurrences of components to process
     \param tolerance Connection tolerance
     \param crackNonManifold At the end of the repair process, crack resulting non-manifold edges
     \param orient If true reorient the model
   */
   static void repairMesh(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & tolerance, const CoreI::Bool & crackNonManifold = true, const CoreI::Boolean & orient = true);

   //! Create normal on an existing normal set when normal is null (polygons appears black)
   /*!
     \param occurrences Occurrences of components to repair null normals
   */
   static void repairNullNormals(const SceneI::OccurrenceList & occurrences);

   //! Remove non manifold edges and try to reconnect manifold groups of triangles
   /*!
     \param occurrences Occurrences of components to process
   */
   static void separateToManifold(const SceneI::OccurrenceList & occurrences);

   //! Sew boundaries between them
   /*!
     \param occurrences Occurrences of components to repair
     \param maxDistance Maximum distance between bundaries
   */
   static void sewBoundary(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & maxDistance);

   //! Properly orient all polygons in the same direction, using visibility attributes
   /*!
     \param occurrences Occurrences to orient
     \param voxelSize Size of the voxels in mm (smaller it is, more viewpoints there are)
     \param minimumCavityVolume Minimum volume of a cavity in cubic meter (smaller it is, more viewpoints there are)
     \param resolution Resolution of the visibility viewer
     \param mode Select where to place camera (all cavities, only outer or only inner cavities)
     \param considerTransparentOpaque If True, Parts, Patches or Polygons with a transparent appearance are considered as opaque
     \param orientStrategy Strategy to adopt with this algorithm
   */
   static void smartOrient(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & voxelSize, const GeomI::Volume & minimumCavityVolume, const CoreI::Int & resolution, const SmartHiddenType & mode = SmartHiddenType::All, const CoreI::Boolean & considerTransparentOpaque = true, const SmartOrientStrategy & orientStrategy = SmartOrientStrategy::VisibilityByConnected);

   //! Move the vertices by the offsset along their normal
   /*!
     \param occurrences Occurrences to process
     \param offset Displacement
   */
   static void vertexOffset(const SceneI::OccurrenceList & occurrences, const GeomI::Distance & offset);

   /**@}*/

   /**
    * \defgroup tessellation conversion Polygonal conversion related functions
    * @{
    */
   //! Sswap edges to make triangles more equilateral
   /*!
     \param occurrences Occurrences of components to process
     \param maxIterations Maximum number of swapping iteration
   */
   static void equilateralize(const SceneI::OccurrenceList & occurrences, const CoreI::Int & maxIterations = 1);

   //! Merge all triangle polygons in the meshes to quadrangles
   /*!
     \param occurrences Occurrences of components to process
   */
   static void quadify(const SceneI::OccurrenceList & occurrences);

   //! Advanced function to requadify a triangle tessellation coming from full quad mesh
   /*!
     \param occurrences Occurrences of components to process
     \param forceFullQuad Force the results to be only full quad. It it's impossible, nothing is done
   */
   static void requadify(const SceneI::OccurrenceList & occurrences, const CoreI::Bool & forceFullQuad = true);

   //! Convert all static mesh to editable mesh
   /*!
     \param occurrences Occurrences to convert to editable mesh
   */
   static void toEditableMesh(const SceneI::OccurrenceList & occurrences);

   //! Convert all editable mesh to static mesh
   /*!
     \param occurrences Occurrences to convert to static mesh
   */
   static void toStaticMesh(const SceneI::OccurrenceList & occurrences);

   //! Split all non-triangle polygons in the meshes to triangles
   /*!
     \param occurrences Occurrences of components to process
   */
   static void triangularize(const SceneI::OccurrenceList & occurrences);

   /**@}*/

   /**
    * \defgroup vertex weights 
    * @{
    */
   //! Use vertex colors attributes on meshes of the given occurrence to create vertex weights attributes used by the decimation functions, the finals weights will be computed with w = offset + (red - blue) * scale
   /*!
     \param occurrences Occurrences of components to process
     \param offset Offset value for weight computation
     \param scale Scale value for weight computation
   */
   static void createVertexWeightsFromVertexColors(const SceneI::OccurrenceList & occurrences, const CoreI::Double & offset = 0, const CoreI::Double & scale = 1);

   //! Use visibility attributes on meshes of the given occurrence to create vertex weights attributes used by the decimation functions. The finals weights will be computed with w = offset + (visibility/maxVisibility) * scale
   /*!
     \param occurrences Occurrences of components to process
     \param offset Offset value for weight computation
     \param scale Scale value for weight computation
   */
   static void createVertexWeightsFromVisibilityAttributes(const SceneI::OccurrenceList & occurrences, const CoreI::Double & offset = 0, const CoreI::Double & scale = 1);

   /**@}*/

   /**
    * \defgroup visibility 
    * @{
    */
   //! Create visibility attributes on tessellations
   /*!
     \param occurrences Occurrences of components to create attributes
   */
   static void createVisibilityAttributes(const SceneI::OccurrenceList & occurrences);

   //! Delete visibility attributes on tessellations
   /*!
     \param occurrences Occurrences of components to delete attributes
   */
   static void deleteVisibilityAttributes(const SceneI::OccurrenceList & occurrences);

   //! Add one count to all visiblility attributes (poly and patch) on transparent patches
   /*!
     \param occurrences Occurrences of components to create attributes
   */
   static void flagVisibilityAttributesOnTransparents(const SceneI::OccurrenceList & occurrences);

   /**@}*/

};

PXZ_MODULE_END



#endif
