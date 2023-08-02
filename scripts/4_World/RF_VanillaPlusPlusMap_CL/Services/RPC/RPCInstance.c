class RF_VanillaPlusPlusMap_CL_RPCInstance: RF_RPCInstance {

    // MARK: - Override Properties

    override int GetRPCType() { return RF_VanillaPlusPlusMap_Constant.RPC_TYPE; }

    override string GetModName() { return RF_VanillaPlusPlusMap_Constant.MOD_NAME; }
	
	// MARK: - Override

    override void Handle(PlayerIdentity sender, string key, ParamsReadContext ctx) {
        super.Handle(sender, key, ctx);
        switch (key) {
            case "didReceiveRPCData": {
                handleDidReceiveRPCData(sender, ctx);
                break;
            }
        }
    }

    // MARK: - Handlers

    private void handleDidReceiveRPCData(PlayerIdentity sender, ParamsReadContext ctx) {
		RF_VanillaPlusPlusMap_CL_RPCData object;
		ctx.Read(object);
		if (!object) return;

        RF_VanillaPlusPlusMap_CL_Global.data = object;

        autoptr auto serverMarkers = GetDayZGame().GetServerMarkers();
		
		// Clear custom server markers on client
        for (int i = serverMarkers.Count() - 1; i >= 0; i--) {
			auto serverMarkerUUID = serverMarkers[i].uuid;
			// If it is custom server marker
			if (!serverMarkerUUID) continue;
			// If new data doesn't contain current marker
			if (object.markersMap[serverMarkerUUID]) continue;
			// Remove
            serverMarkers.RemoveOrdered(i);
		}

		// Put or update custom server markers
        foreach (auto uuid, auto rpcMarker : object.markersMap) {
			// Define template
            auto markerInfo = new MarkerInfo(rpcMarker.markerName, rpcMarker.iconPath, rpcMarker.color, rpcMarker.position, rpcMarker.isActive.isEnabled, rpcMarker.is3DActive.isEnabled);
            markerInfo.uuid = uuid;

			// Find existing custom server marker
            auto serverMarkerInfo = getServerMarkerInfo(rpcMarker.uuid);
            if (!serverMarkerInfo) {
                serverMarkers.Insert(markerInfo);
            } else {
                serverMarkerInfo.SetName(rpcMarker.markerName);
                serverMarkerInfo.SetIconPath(rpcMarker.iconPath);
                serverMarkerInfo.SetColor(rpcMarker.color);
                serverMarkerInfo.SetPosition(rpcMarker.position);
                if (rpcMarker.isActive.isForced) {
                    serverMarkerInfo.SetActive(rpcMarker.isActive.isEnabled);
                }
                if (rpcMarker.is3DActive.isForced) {
                    serverMarkerInfo.Set3DActive(rpcMarker.is3DActive.isEnabled);
                }
            }
        }
    }

    private MarkerInfo getServerMarkerInfo(string uuid) {
        autoptr auto serverMarkers = GetDayZGame().GetServerMarkers();
        foreach (auto serverMarker : serverMarkers) {
            if (serverMarker.uuid == uuid) {
                return serverMarker;
            }
        }
        return null;
    }
}