class RF_VanillaPlusPlusMap_CL_RPCMarker: Managed {
    string uuid;
    string markerName;
    string iconPath;
    vector color;
    vector position;
    autoptr RF_VanillaPlusPlusMap_CL_RPCMarkerBool isActive = new RF_VanillaPlusPlusMap_CL_RPCMarkerBool();
    autoptr RF_VanillaPlusPlusMap_CL_RPCMarkerBool is3DActive = new RF_VanillaPlusPlusMap_CL_RPCMarkerBool();
}