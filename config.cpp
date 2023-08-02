#define _ARMA_

class CfgPatches {
	class RF_VanillaPlusPlusMap_CL {
		author = "Dad Fedor & romabeorn";
		name = "RF_VanillaPlusPlusMap_CL";
		url = "https://discord.gg/d9kP7ezX3n";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"DZ_Data", "DZ_Sounds_Effects", "VanillaPlusPlus"};
		requiredVersion = 0.1;
	};

    class DZ_Gear_Camping {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods {
	class RF_VanillaPlusPlusMap_CL {
		type="mod";
		dir="RF_VanillaPlusPlusMap_CL";
		class defs {
			class gameScriptModule {
				value = "";
				files[] = { "RF_VanillaPlusPlusMap_CL/scripts/3_Game" };
			};
			class worldScriptModule {
				value = "";
				files[] = { "RF_VanillaPlusPlusMap_CL/scripts/4_World" };
			};
			class missionScriptModule {
				value = "";
				files[] = { "RF_VanillaPlusPlusMap_CL/scripts/5_Mission" };
			};
		};
	};
};
