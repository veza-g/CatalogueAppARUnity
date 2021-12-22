﻿using Pixyz.OptimizeSDK.Runtime;
using UnityEngine;

namespace Pixyz.LODTools
{
    public class LODRule : ScriptableObject
    {
        /// <summary>
        /// Should this rule apply a repair or only a WeldVertices ?
        /// </summary>
        public bool isRepairActivated = false;

        /// <summary>
        /// Should this rule apply a decimation by quality. (Both decimation type can't be active at the same time)
        /// </summary>
        public bool isDecimateToQualityActivated = false;

        /// <summary>
        /// Should this rule apply a decimation by vertex target count/ratio. (Both decimation type can't be active at the same time)
        /// </summary>
        public bool isDecimateToTargetActivated = false;

        /// <summary>
        /// Should this rule apply an occlusion optimisation ? (removing non-visible triangles, automaticly disabled if a remesh operation is active)
        /// </summary>
        public bool isOcclusionActivated = false;

        /// <summary>
        /// Should this rule apply a remesh of the source mesh ? (Both remesh type can't be active at the same time)
        /// </summary>
        public bool isRemeshActivated = false;
        
        /// <summary>
        /// Should this rule apply a remesh field aligned of the source mesh ? (Both remesh type can't be active at the same time)
        /// </summary>
        public bool isRemeshFieldAlignedActivated= false;

        /// <summary>
        /// Should this rule apply a merge or combine ?
        /// </summary>
        public bool isCombineActivated = false;

        /// <summary>
        /// Should this rule combine source mesh to obtain 1 material and 1 mesh as output ?
        /// </summary>
        public bool isCombineMaterialsActivated = false;

        /// <summary>
        /// Should this rule combine source mesh submesh by materials to obtain many submesh as unique materials there is on the source mesh ?
        /// </summary>
        public bool isCombineMeshesByMaterialsActivated = false;

        /// <summary>
        /// Should this rule create a billboard, all other optimization can't be activate (vice-versa)
        /// </summary>
        public bool isBillboardActivated = false;

        /// <summary>
        /// Should this rule decimate a point cloud (not available in UI for now), all other optimization can't be activated
        /// </summary>
        public bool isDecimatePointCloudActivated = false;

        /// <summary>
        /// Should this rule create an imposter
        /// </summary>
        public bool isImpostorActivated = false;

        public RepairMeshesParameters repairParameters = new RepairMeshesParameters();
        public DecimateToQualityParameters decimateToQualityParam = new DecimateToQualityParameters();
        public DecimateToTargetParameters decimateToTarget = new DecimateToTargetParameters();
        public OcclusionCullingParameters occlusionParameters = new OcclusionCullingParameters();
        public RemeshFieldAlignedParameters remeshFieldAlignedParameters = new RemeshFieldAlignedParameters();
        public RemeshParameters remeshParameters = new RemeshParameters();
        public CombineMeshesParameters combineMeshesParameters = new CombineMeshesParameters();
        public BilloardParamters billoardParamters = new BilloardParamters();
        public ImpostorParameters impostorParameters = new ImpostorParameters();

        /// <summary>
        /// Create a rule, can be set with default values of a LOD level by providing the target LOD level
        /// </summary>
        /// <param name="defaultLevel"></param>
        /// <returns></returns>
        public static LODRule CreateInstance(int defaultLevel = -1)
        {
            LODRule rule = ScriptableObject.CreateInstance<LODRule>();

            switch (defaultLevel)
            {
                case 0:
                default:
                    break;
                case 1:
                    rule.isDecimateToTargetActivated = true;
                    rule.decimateToTarget.ratio = 75f;
                    rule.decimateToTarget.isTargetCount = false;
                    break;
                case 2:
                    rule.isOcclusionActivated = true;
                    rule.occlusionParameters.mode = OcclusionMode.Standard;
                    rule.isDecimateToTargetActivated = true;
                    rule.decimateToTarget.ratio = 50f;
                    rule.decimateToTarget.isTargetCount = false;
                    break;
                case 3:
                    rule.isCombineMaterialsActivated = true;
                    rule.combineMeshesParameters.padding = 1;
                    rule.combineMeshesParameters.resolution = 1024;
                    rule.isOcclusionActivated = true;
                    rule.occlusionParameters.mode = OcclusionMode.Standard;
                    rule.isDecimateToTargetActivated = true;
                    rule.decimateToTarget.ratio = 25f;
                    rule.decimateToTarget.isTargetCount = false;
                    break;
                case 4:
                    rule.isCombineMaterialsActivated = true;
                    rule.combineMeshesParameters.padding = 1;
                    rule.combineMeshesParameters.resolution = 512;
                    rule.isOcclusionActivated = true;
                    rule.occlusionParameters.mode = OcclusionMode.Standard;
                    rule.isDecimateToTargetActivated = true;
                    rule.decimateToTarget.ratio = 10f;
                    rule.decimateToTarget.isTargetCount = false;
                    break;
            }

            return rule;
        }

        /// <summary>
        /// Compute a hash of the current state of this rule
        /// </summary>
        /// <returns></returns>
        public long ComputeHash()
        {
            long hash = 1;
            hash ^= repairParameters.ComputeHash();
            hash ^= decimateToQualityParam.ComputeHash() ^ 73;
            hash ^= decimateToTarget.ComputeHash();
            hash ^= occlusionParameters.ComputeHash() ^ 47;
            hash ^= remeshFieldAlignedParameters.ComputeHash();
            hash ^= remeshParameters.ComputeHash() ^ 11783;
            hash ^= combineMeshesParameters.ComputeHash();
            hash ^= billoardParamters.ComputeHash();
            hash ^= impostorParameters.ComputeHash();

            hash ^= isRepairActivated.GetHashCode() ^ isDecimateToQualityActivated.GetHashCode() ^ isDecimateToTargetActivated.GetHashCode() ^ 111 ^ isOcclusionActivated.GetHashCode() ^ isRemeshActivated.GetHashCode() ^ isRemeshFieldAlignedActivated.GetHashCode() ^ isCombineMaterialsActivated.GetHashCode() ^ 3 ^ isCombineMeshesByMaterialsActivated.GetHashCode() ^ isDecimatePointCloudActivated.GetHashCode();

            return hash; 
        }
    }
}