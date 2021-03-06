// !!! This is a generated file, do not edit !!!
#ifndef _PXZ_ALGO_INTERFACE_ALGOTYPES_H_
#define _PXZ_ALGO_INTERFACE_ALGOTYPES_H_

#include <PiXYZCore/interface/InterfaceBase.h>
#include <PiXYZCore/interface/CoreTypes.h>
#include <PiXYZGeom/interface/GeomTypes.h>
#include <PiXYZMaterial/interface/MaterialTypes.h>
#include <PiXYZPolygonal/interface/PolygonalTypes.h>
#include <PiXYZScene/interface/SceneTypes.h>
#include <functional> 

PXZ_MODULE_BEGIN(AlgoI)

class AttributType {
public:
   typedef enum {
   Patches = 4020,
   PatchMaterials = 4021,
   PatchBoundaries = 4022,
   UVs = 4035,
   Normals = 4036,
   Tangents = 4037,
   Binormals = 4038
   } Type;
private:
   Type _value;
public:
   AttributType(Type val = Patches) : _value(val) {}
   AttributType & operator=(Type val) { _value = val; return *this; }
   AttributType(const CoreI::Int& val) : _value((Type)val) {}
   AttributType & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class MapType {
public:
   typedef enum {
   Diffuse = 0,
   Normal = 1,
   Opacity = 2,
   Roughness = 3,
   Specular = 4,
   Metallic = 5,
   AO = 6,
   Emissive = 7,
   PartId = 8,
   MaterialId = 9,
   ComputeAO = 10,
   Bent = 11,
   UV = 12,
   Displacement = 13,
   LocalPosition = 14,
   GlobalPosition = 15,
   Depth = 16
   } Type;
private:
   Type _value;
public:
   MapType(Type val = Diffuse) : _value(val) {}
   MapType & operator=(Type val) { _value = val; return *this; }
   MapType(const CoreI::Int& val) : _value((Type)val) {}
   MapType & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct BakeMap {
   MapType type;
   SceneI::PropertyValueList properties;
   BakeMap(MapType _type = MapType::Diffuse, SceneI::PropertyValueList _properties = SceneI::PropertyValueList()) : type(_type), properties(_properties) {}
};

typedef CoreI::List<BakeMap> BakeMapList;

struct BakeMaps {
   CoreI::Boolean diffuse;
   CoreI::Boolean normal;
   CoreI::Boolean roughness;
   CoreI::Boolean metallic;
   CoreI::Boolean opacity;
   CoreI::Boolean ambientOcclusion;
   CoreI::Boolean emissive;
   BakeMaps(CoreI::Boolean _diffuse = true, CoreI::Boolean _normal = true, CoreI::Boolean _roughness = true, CoreI::Boolean _metallic = true, CoreI::Boolean _opacity = true, CoreI::Boolean _ambientOcclusion = true, CoreI::Boolean _emissive = true) : diffuse(_diffuse), normal(_normal), roughness(_roughness), metallic(_metallic), opacity(_opacity), ambientOcclusion(_ambientOcclusion), emissive(_emissive) {}
};

class BakingMethod {
public:
   typedef enum {
   RayOnly = 0,
   ProjOnly = 1,
   RayAndProj = 2
   } Type;
private:
   Type _value;
public:
   BakingMethod(Type val = RayOnly) : _value(val) {}
   BakingMethod & operator=(Type val) { _value = val; return *this; }
   BakingMethod(const CoreI::Int& val) : _value((Type)val) {}
   BakingMethod & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct BakeOption {
   BakingMethod bakingMethod;
   CoreI::Int resolution;
   CoreI::Int padding;
   BakeMaps textures;
   BakeOption(BakingMethod _bakingMethod = BakingMethod::RayOnly, CoreI::Int _resolution = 1024, CoreI::Int _padding = 1, BakeMaps _textures = BakeMaps()) : bakingMethod(_bakingMethod), resolution(_resolution), padding(_padding), textures(_textures) {}
};

struct Box {
   GeomI::Affine position;
   CoreI::Double length;
   CoreI::Double height;
   CoreI::Double depth;
   Box(GeomI::Affine _position = GeomI::Affine(), CoreI::Double _length = 200, CoreI::Double _height = 200, CoreI::Double _depth = 200) : position(_position), length(_length), height(_height), depth(_depth) {}
};

struct BoxParameters {
   CoreI::Double SizeX;
   CoreI::Double SizeY;
   CoreI::Double SizeZ;
   CoreI::Int Subdivision;
   BoxParameters(CoreI::Double _SizeX = 1000, CoreI::Double _SizeY = 1000, CoreI::Double _SizeZ = 1000, CoreI::Int _Subdivision = 1) : SizeX(_SizeX), SizeY(_SizeY), SizeZ(_SizeZ), Subdivision(_Subdivision) {}
};

class ComputingQuality {
public:
   typedef enum {
   High = 0,
   Medium = 1,
   Low = 2
   } Type;
private:
   Type _value;
public:
   ComputingQuality(Type val = High) : _value(val) {}
   ComputingQuality & operator=(Type val) { _value = val; return *this; }
   ComputingQuality(const CoreI::Int& val) : _value((Type)val) {}
   ComputingQuality & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct ConeParameters {
   CoreI::Double BottomRadius;
   CoreI::Double Height;
   CoreI::Int Sides;
   ConeParameters(CoreI::Double _BottomRadius = 250, CoreI::Double _Height = 500, CoreI::Int _Sides = 16) : BottomRadius(_BottomRadius), Height(_Height), Sides(_Sides) {}
};

class ConvexityConstraint {
public:
   typedef enum {
   REMOVE_CONVEX_ONLY = 0,
   REMOVE_CONCAVE_ONLY = 1,
   REMOVE_BOTH = 2
   } Type;
private:
   Type _value;
public:
   ConvexityConstraint(Type val = REMOVE_CONVEX_ONLY) : _value(val) {}
   ConvexityConstraint & operator=(Type val) { _value = val; return *this; }
   ConvexityConstraint(const CoreI::Int& val) : _value((Type)val) {}
   ConvexityConstraint & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class CostEvaluation {
public:
   typedef enum {
   SumEvaluation = 0,
   MaxEvaluation = 1,
   AverageEvaluation = 2
   } Type;
private:
   Type _value;
public:
   CostEvaluation(Type val = SumEvaluation) : _value(val) {}
   CostEvaluation & operator=(Type val) { _value = val; return *this; }
   CostEvaluation(const CoreI::Int& val) : _value((Type)val) {}
   CostEvaluation & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class CreateOccluder {
public:
   typedef enum {
   Occludee = 0,
   Occluder = 1
   } Type;
private:
   Type _value;
public:
   CreateOccluder(Type val = Occludee) : _value(val) {}
   CreateOccluder & operator=(Type val) { _value = val; return *this; }
   CreateOccluder(const CoreI::Int& val) : _value((Type)val) {}
   CreateOccluder & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct CustomBakeMap {
   CoreI::String name;
   CoreI::Int component;
   CustomBakeMap(CoreI::String _name = "", CoreI::Int _component = 3) : name(_name), component(_component) {}
};

typedef CoreI::List<CustomBakeMap> CustomBakeMapList;

struct Cylinder {
   GeomI::Affine position;
   CoreI::Double radius;
   CoreI::Double length;
   Cylinder(GeomI::Affine _position = GeomI::Affine(), CoreI::Double _radius = 100, CoreI::Double _length = 200) : position(_position), radius(_radius), length(_length) {}
};

struct CylinderParameters {
   CoreI::Double Radius;
   CoreI::Double Height;
   CoreI::Int Sides;
   CylinderParameters(CoreI::Double _Radius = 250, CoreI::Double _Height = 1000, CoreI::Int _Sides = 16) : Radius(_Radius), Height(_Height), Sides(_Sides) {}
};

struct DecimateOptionsSelector {
   typedef enum {
      UNKNOWN=0,
      TRIANGLECOUNT,
      RATIO
   } Type;
   Type _type; 
   CoreI::Int triangleCount;
   CoreI::Percent ratio;
   DecimateOptionsSelector() : _type(UNKNOWN) {}
   DecimateOptionsSelector(const CoreI::Int & v) : _type(TRIANGLECOUNT), triangleCount(v) {}
   DecimateOptionsSelector(const CoreI::Percent & v) : _type(RATIO), ratio(v) {}
};
class ElementFilter {
public:
   typedef enum {
   Polygons = 0,
   Points = 1,
   Hybrid = 2
   } Type;
private:
   Type _value;
public:
   ElementFilter(Type val = Polygons) : _value(val) {}
   ElementFilter & operator=(Type val) { _value = val; return *this; }
   ElementFilter(const CoreI::Int& val) : _value((Type)val) {}
   ElementFilter & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class FeatureType {
public:
   typedef enum {
   Unknown = 0,
   ThroughHole = 1,
   BlindHole = 2
   } Type;
private:
   Type _value;
public:
   FeatureType(Type val = Unknown) : _value(val) {}
   FeatureType & operator=(Type val) { _value = val; return *this; }
   FeatureType(const CoreI::Int& val) : _value((Type)val) {}
   FeatureType & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct FeatureInput {
   GeomI::Point3 position;
   GeomI::Vector3 direction;
   GeomI::Distance diameter;
   FeatureInput(GeomI::Point3 _position = GeomI::Point3(), GeomI::Vector3 _direction = GeomI::Vector3(), GeomI::Distance _diameter = 0) : position(_position), direction(_direction), diameter(_diameter) {}
};

typedef CoreI::List<FeatureInput> FeatureInputList;

struct Feature {
   FeatureType type;
   FeatureInputList inputs;
   Feature(FeatureType _type = FeatureType::Unknown, FeatureInputList _inputs = FeatureInputList()) : type(_type), inputs(_inputs) {}
};

typedef CoreI::List<Feature> FeatureList;

class FlatteningStopCondition {
public:
   typedef enum {
   MEAN_DEFORMATION = 0,
   ABSOLUTE_DEFORMATION = 1
   } Type;
private:
   Type _value;
public:
   FlatteningStopCondition(Type val = MEAN_DEFORMATION) : _value(val) {}
   FlatteningStopCondition & operator=(Type val) { _value = val; return *this; }
   FlatteningStopCondition(const CoreI::Int& val) : _value((Type)val) {}
   FlatteningStopCondition & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct HexahedronParameters {
   CoreI::Double XLength;
   CoreI::Double YLength;
   CoreI::Double ZLength;
   HexahedronParameters(CoreI::Double _XLength = 1, CoreI::Double _YLength = 1, CoreI::Double _ZLength = 1) : XLength(_XLength), YLength(_YLength), ZLength(_ZLength) {}
};

typedef CoreI::List<MapType> MapTypeList;

struct OccurrenceFeatures {
   SceneI::Occurrence occurrence;
   FeatureList features;
   OccurrenceFeatures(SceneI::Occurrence _occurrence = 0, FeatureList _features = FeatureList()) : occurrence(_occurrence), features(_features) {}
};

typedef CoreI::List<OccurrenceFeatures> OccurrenceFeaturesList;

struct OctahedralImpostor {
   GeomI::Matrix4 OctaTransform;
   CoreI::Double Radius;
   MaterialI::Image NormalMap;
   MaterialI::Image DepthMap;
   MaterialI::Image DiffuseMap;
   MaterialI::Image MetallicMap;
   MaterialI::Image AOMap;
   MaterialI::Image RoughnessMap;
   OctahedralImpostor(GeomI::Matrix4 _OctaTransform = GeomI::Matrix4(), CoreI::Double _Radius = 1, MaterialI::Image _NormalMap = 0, MaterialI::Image _DepthMap = 0, MaterialI::Image _DiffuseMap = 0, MaterialI::Image _MetallicMap = 0, MaterialI::Image _AOMap = 0, MaterialI::Image _RoughnessMap = 0) : OctaTransform(_OctaTransform), Radius(_Radius), NormalMap(_NormalMap), DepthMap(_DepthMap), DiffuseMap(_DiffuseMap), MetallicMap(_MetallicMap), AOMap(_AOMap), RoughnessMap(_RoughnessMap) {}
};

class OrientStrategy {
public:
   typedef enum {
   ExteriorOnly = 0,
   VisibilityOrExterior = 1,
   VisibilityByConnected = 2,
   VisibilityByPolygon = 3,
   ConformToMajority = 4
   } Type;
private:
   Type _value;
public:
   OrientStrategy(Type val = ExteriorOnly) : _value(val) {}
   OrientStrategy & operator=(Type val) { _value = val; return *this; }
   OrientStrategy(const CoreI::Int& val) : _value((Type)val) {}
   OrientStrategy & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct Plane {
   GeomI::Affine position;
   CoreI::Double length;
   CoreI::Double height;
   Plane(GeomI::Affine _position = GeomI::Affine(), CoreI::Double _length = 200, CoreI::Double _height = 200) : position(_position), length(_length), height(_height) {}
};

struct PlaneParameters {
   CoreI::Double SizeX;
   CoreI::Double SizeY;
   CoreI::Int SubdivisionX;
   CoreI::Int SubdivisionY;
   PlaneParameters(CoreI::Double _SizeX = 1000, CoreI::Double _SizeY = 1000, CoreI::Int _SubdivisionX = 1, CoreI::Int _SubdivisionY = 1) : SizeX(_SizeX), SizeY(_SizeY), SubdivisionX(_SubdivisionX), SubdivisionY(_SubdivisionY) {}
};

struct SphereParameters {
   CoreI::Double Radius;
   CoreI::Int Latitude;
   CoreI::Int Longitude;
   SphereParameters(CoreI::Double _Radius = 500, CoreI::Int _Latitude = 16, CoreI::Int _Longitude = 16) : Radius(_Radius), Latitude(_Latitude), Longitude(_Longitude) {}
};

struct PrimitiveShapeParameters {
   typedef enum {
      UNKNOWN=0,
      BOX,
      PLANE,
      SPHERE,
      CYLINDER,
      CONE
   } Type;
   Type _type; 
   BoxParameters Box;
   PlaneParameters Plane;
   SphereParameters Sphere;
   CylinderParameters Cylinder;
   ConeParameters Cone;
   PrimitiveShapeParameters() : _type(UNKNOWN) {}
   PrimitiveShapeParameters(const BoxParameters & v) : _type(BOX), Box(v) {}
   PrimitiveShapeParameters(const PlaneParameters & v) : _type(PLANE), Plane(v) {}
   PrimitiveShapeParameters(const SphereParameters & v) : _type(SPHERE), Sphere(v) {}
   PrimitiveShapeParameters(const CylinderParameters & v) : _type(CYLINDER), Cylinder(v) {}
   PrimitiveShapeParameters(const ConeParameters & v) : _type(CONE), Cone(v) {}
};
class QualityMemoryTradeoff {
public:
   typedef enum {
   PreferQuality = 0,
   PreferMemory = 1
   } Type;
private:
   Type _value;
public:
   QualityMemoryTradeoff(Type val = PreferQuality) : _value(val) {}
   QualityMemoryTradeoff & operator=(Type val) { _value = val; return *this; }
   QualityMemoryTradeoff(const CoreI::Int& val) : _value((Type)val) {}
   QualityMemoryTradeoff & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class QualitySpeedTradeoff {
public:
   typedef enum {
   PreferQuality = 0,
   PreferSpeed = 1
   } Type;
private:
   Type _value;
public:
   QualitySpeedTradeoff(Type val = PreferQuality) : _value(val) {}
   QualitySpeedTradeoff & operator=(Type val) { _value = val; return *this; }
   QualitySpeedTradeoff(const CoreI::Int& val) : _value((Type)val) {}
   QualitySpeedTradeoff & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class RelaxUVMethod {
public:
   typedef enum {
   Angle = 0,
   Edge = 1
   } Type;
private:
   Type _value;
public:
   RelaxUVMethod(Type val = Angle) : _value(val) {}
   RelaxUVMethod & operator=(Type val) { _value = val; return *this; }
   RelaxUVMethod(const CoreI::Int& val) : _value((Type)val) {}
   RelaxUVMethod & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class ReplaceByBoxType {
public:
   typedef enum {
   Minimum = 0,
   LocallyAligned = 1
   } Type;
private:
   Type _value;
public:
   ReplaceByBoxType(Type val = Minimum) : _value(val) {}
   ReplaceByBoxType & operator=(Type val) { _value = val; return *this; }
   ReplaceByBoxType(const CoreI::Int& val) : _value((Type)val) {}
   ReplaceByBoxType & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class ReplaceByMode {
public:
   typedef enum {
   ByOccurrence = 0,
   All = 1
   } Type;
private:
   Type _value;
public:
   ReplaceByMode(Type val = ByOccurrence) : _value(val) {}
   ReplaceByMode & operator=(Type val) { _value = val; return *this; }
   ReplaceByMode(const CoreI::Int& val) : _value((Type)val) {}
   ReplaceByMode & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct ReplaceByOccurrenceOptions {
   SceneI::Occurrence Occurrence;
   CoreI::Boolean Aligned;
   ReplaceByOccurrenceOptions(SceneI::Occurrence _Occurrence = 0, CoreI::Boolean _Aligned = false) : Occurrence(_Occurrence), Aligned(_Aligned) {}
};

struct ReplaceByPrimitiveOptions {
   PrimitiveShapeParameters Type;
   CoreI::Boolean Aligned;
   CoreI::Boolean GenerateUV;
   ReplaceByPrimitiveOptions(PrimitiveShapeParameters _Type = PrimitiveShapeParameters(), CoreI::Boolean _Aligned = false, CoreI::Boolean _GenerateUV = true) : Type(_Type), Aligned(_Aligned), GenerateUV(_GenerateUV) {}
};

struct ReplaceByOption {
   typedef enum {
      UNKNOWN=0,
      OCCURRENCE,
      BOUNDINGBOX,
      CONVEXHULL,
      PRIMITIVE
   } Type;
   Type _type; 
   ReplaceByOccurrenceOptions Occurrence;
   ReplaceByBoxType BoundingBox;
   CoreI::None ConvexHull;
   ReplaceByPrimitiveOptions Primitive;
   ReplaceByOption() : _type(UNKNOWN) {}
   ReplaceByOption(const ReplaceByOccurrenceOptions & v) : _type(OCCURRENCE), Occurrence(v) {}
   ReplaceByOption(const ReplaceByBoxType & v) : _type(BOUNDINGBOX), BoundingBox(v) {}
   ReplaceByOption(const CoreI::None & v) : _type(CONVEXHULL), ConvexHull(v) {}
   ReplaceByOption(const ReplaceByPrimitiveOptions & v) : _type(PRIMITIVE), Primitive(v) {}
};
class SawingMode {
public:
   typedef enum {
   SawOnly = 0,
   SawAndSplit = 1,
   KeepInside = 2,
   KeepOutside = 3
   } Type;
private:
   Type _value;
public:
   SawingMode(Type val = SawOnly) : _value(val) {}
   SawingMode & operator=(Type val) { _value = val; return *this; }
   SawingMode(const CoreI::Int& val) : _value((Type)val) {}
   SawingMode & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class SelectionLevel {
public:
   typedef enum {
   Parts = 0,
   Patches = 1,
   Polygons = 2
   } Type;
private:
   Type _value;
public:
   SelectionLevel(Type val = Parts) : _value(val) {}
   SelectionLevel & operator=(Type val) { _value = val; return *this; }
   SelectionLevel(const CoreI::Int& val) : _value((Type)val) {}
   SelectionLevel & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class SmartHiddenType {
public:
   typedef enum {
   All = 0,
   OnlyOuter = 1,
   OnlyInners = 2
   } Type;
private:
   Type _value;
public:
   SmartHiddenType(Type val = All) : _value(val) {}
   SmartHiddenType & operator=(Type val) { _value = val; return *this; }
   SmartHiddenType(const CoreI::Int& val) : _value((Type)val) {}
   SmartHiddenType & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class SmartOrientStrategy {
public:
   typedef enum {
   VisibilityByConnected = 0,
   VisibilityByPolygon = 1
   } Type;
private:
   Type _value;
public:
   SmartOrientStrategy(Type val = VisibilityByConnected) : _value(val) {}
   SmartOrientStrategy & operator=(Type val) { _value = val; return *this; }
   SmartOrientStrategy(const CoreI::Int& val) : _value((Type)val) {}
   SmartOrientStrategy & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct Sphere {
   GeomI::Affine position;
   CoreI::Double radius;
   Sphere(GeomI::Affine _position = GeomI::Affine(), CoreI::Double _radius = 100) : position(_position), radius(_radius) {}
};

class UVGenerationMode {
public:
   typedef enum {
   NoUV = 0,
   IntrinsicUV = 1,
   ConformalScaledUV = 2
   } Type;
private:
   Type _value;
public:
   UVGenerationMode(Type val = NoUV) : _value(val) {}
   UVGenerationMode & operator=(Type val) { _value = val; return *this; }
   UVGenerationMode(const CoreI::Int& val) : _value((Type)val) {}
   UVGenerationMode & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
class UVImportanceEnum {
public:
   typedef enum {
   PreserveSeamsAndReduceDeformation = 0,
   PreserveSeams = 1,
   IgnoreUV = 2
   } Type;
private:
   Type _value;
public:
   UVImportanceEnum(Type val = PreserveSeamsAndReduceDeformation) : _value(val) {}
   UVImportanceEnum & operator=(Type val) { _value = val; return *this; }
   UVImportanceEnum(const CoreI::Int& val) : _value((Type)val) {}
   UVImportanceEnum & operator=(const CoreI::Int& val) { _value = (Type)val; return *this; }
   Type value() const { return _value; }
   operator Type() const { return _value; }
};
struct UseColorOption {
   typedef enum {
      UNKNOWN=0,
      USELINESCOLOR,
      CHOOSECOLOR
   } Type;
   Type _type; 
   CoreI::None UseLinesColor;
   CoreI::Color ChooseColor;
   UseColorOption() : _type(UNKNOWN) {}
   UseColorOption(const CoreI::None & v) : _type(USELINESCOLOR), UseLinesColor(v) {}
   UseColorOption(const CoreI::Color & v) : _type(CHOOSECOLOR), ChooseColor(v) {}
};
typedef std::function<CoreI::ColorAlpha(const GeomI::Point3 & fromPos, const GeomI::Point2 & param, const CoreI::ULong & polygonIndex, const SceneI::Occurrence & occurrence)> getPixelValue;

typedef CoreI::List<getPixelValue> getPixelValueList;

typedef struct {
   CoreI::Int visibleCountFront;
   CoreI::Int visibleCountBack;
} getVisibilityStatsReturn;


PXZ_MODULE_END

#endif
