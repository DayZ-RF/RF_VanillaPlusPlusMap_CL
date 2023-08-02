class RF_VanillaPlusPlusMap_CL_Global: Managed {

	// MARK: - Static Properties

	static ref RF_VanillaPlusPlusMap_CL_RPCInstance rpc;

	static ref RF_VanillaPlusPlusMap_CL_RPCData data;

	// MARK: - Static

	static void InitializeUnits() {
		rpc = new RF_VanillaPlusPlusMap_CL_RPCInstance();
		data = new RF_VanillaPlusPlusMap_CL_RPCData();
	}
}