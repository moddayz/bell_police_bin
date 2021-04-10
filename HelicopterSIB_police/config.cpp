class CfgPatches
{
	class HelicopterModSIB_police
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"HelicopterModScriptsSIB"};
	};
};
class CfgMods
{
	class HelicopterModSIB_police
	{
		dir="HelicopterSIB_police";
		hideName=0;
		hidePicture=0;
		name="HelicopterModSIB_police";
		credits="";
		author="SIBNIC";
		authorID="";
		version="version 4";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			
			
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"HelicopterSIB_police/4_World"
				};
			};
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"HelicopterSIB_police/3_Game"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"HelicopterSIB_police/5_Mission"
				};
			};
		};
	};
};

class CfgSoundShaders
{
	class Heli_police_crash_SoundShaders
	{
		samples[] = {{"HelicopterSIB_police\Sound\crash",1}};
		range = 250;
		volume = 1.0;
	};
	class Heli_police_warning_SoundShaders
	{
		samples[] = {{"HelicopterSIB_police\Sound\warning",1}};
		range = 250;
		volume = 1.0;
	};
	class Heli_police_engine_SoundShaders
	{
		samples[] = {{"HelicopterSIB_police\Sound\engine",1}};
		range = 700;
		volume = 1.5;
	};
	class Heli_police_rotor_SoundShaders
	{
		samples[] = {{"HelicopterSIB_police\Sound\rotor",1}};
		range = 700;
		volume = 1.5;
	};
	class Heli_police_start_SoundShaders
	{
		samples[] = {{"HelicopterSIB_police\Sound\start",1}};
		range = 500;
		volume = 1.5;
	};
	class Heli_police_stop_SoundShaders
	{
		samples[] = {{"HelicopterSIB_police\Sound\stop",1}};
		range = 500;
		volume = 1.5;
	};
};
class CfgSoundSets
{
	class Heli_base_SoundSet
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class HelicopterCrash_SoundSets_police: Heli_base_SoundSet
	{
		soundShaders[] = {"Heli_police_police_crash_SoundShaders"};
	};
	class HelicopterWarning_SoundSets_police: Heli_base_SoundSet
	{
		soundShaders[] = {"Heli_police_warning_SoundShaders"};
	};
	class HelicopterStart_SoundSets_police: Heli_base_SoundSet
	{
		soundShaders[] = {"Heli_police_start_SoundShaders"};
	};
	class HelicopterStop_SoundSets_police: Heli_base_SoundSet
	{
		soundShaders[] = {"Heli_police_stop_SoundShaders"};
	};
	class HelicopterEngine_SoundSets_police: Heli_base_SoundSet
	{
		soundShaders[] = {"Heli_police_engine_SoundShaders"};
		loop = 1;
	};
	class HelicopterRotor_SoundSets_police: Heli_base_SoundSet
	{
		soundShaders[] = {"Heli_police_rotor_SoundShaders"};
		loop = 1;
	};
};

class CfgVehicles
{
	
	
	class Crew;
	class AnimationSources;
	class CarDoor;
	
	class SIBPolice_Door_1_1: CarDoor
	{
		scope = 2;
		displayName = "doors_driver";
		descriptionShort = "doors_driverD";
		model = "\HelicopterSIB_police\SIBPolice_doors_driver.p3d";
		inventorySlot[] = {"SIBPolice_Door_1_1"};
		rotationFlags = 8;
		hiddenSelections[] = {"camo1_door"};
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib.rvmat"};
	};
	class SIBPolice_Door_1_1_swat: SIBPolice_Door_1_1
	{
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_SWAT_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib_swat.rvmat"};
	};
	class SIBPolice_Door_1_2: CarDoor
	{
		scope = 2;
		displayName = "$STR_doors_cargo1";
		descriptionShort = "$STR_doors_cargo1d";
		model = "\HelicopterSIB_police\SIBPolice_doors_cargo1.p3d";
		inventorySlot[] = {"SIBPolice_Door_1_2"};
		rotationFlags = 8;
		hiddenSelections[] = {"camo1_door"};
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib.rvmat"};
	};
	class SIBPolice_Door_1_2_swat: SIBPolice_Door_1_2
	{
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_SWAT_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib_swat.rvmat"};
	};
	class SIBPolice_Door_2_1: CarDoor
	{
		scope = 2;
		displayName = "$STR_SIBPolice_doors_codriver";
		descriptionShort = "$STR_SIBPolice_doors_codriverd";
		model = "\HelicopterSIB_police\SIBPolice_doors_codriver.p3d";
		inventorySlot[] = {"SIBPolice_Door_2_1"};
		rotationFlags = 8;
		hiddenSelections[] = {"camo1_door"};
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib.rvmat"};
	};
	class SIBPolice_Door_2_1_swat: SIBPolice_Door_2_1
	{
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_SWAT_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib_swat.rvmat"};
	};
	class SIBPolice_Door_2_2: CarDoor
	{
		scope = 2;
		displayName = "$STR_SIBPolice_doors_cargo2";
		descriptionShort = "$STR_SIBPolice_doors_cargo2d";
		model = "\HelicopterSIB_police\SIBPolice_doors_cargo2.p3d";
		inventorySlot[] = {"SIBPolice_Door_2_2"};
		rotationFlags = 8;
		hiddenSelections[] = {"camo1_door"};
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib.rvmat"};
	};
	class SIBPolice_Door_2_2_swat: SIBPolice_Door_2_2
	{
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_SWAT_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib_swat.rvmat"};
	};
	class HeliSIB_middle;
	class HeliSIB_police_base: HeliSIB_middle
	{
		scope=1;
		attachments[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","SIBPolice_Door_1_1","SIBPolice_Door_1_2","SIBPolice_Door_2_1","SIBPolice_Door_2_2","Reflector_1_1","Reflector_2_1","CarBattery"};
		model="\HelicopterSIB_police\police.p3d";
		class GUIInventoryAttachmentsProps
		{
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon="cat_vehicle_body";
				attachmentSlots[] = {"SIBPolice_Door_1_1","SIBPolice_Door_1_2","SIBPolice_Door_2_1","SIBPolice_Door_2_2","Reflector_1_1","Reflector_2_1"};
			};
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				attachmentSlots[] = {"CarBattery"};
				icon = "cat_vehicle_engine";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 6000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Body
				{
					fatalInjuryCoef = 0.001;
					memoryPoints[] = {"dmgzone_body"};
					componentNames[] = {"dmgzone_body"};
					class Health
					{
						hitpoints = 10000;
						transferToGlobalCoef = 0.001;
					};
					transferToZonesNames[] = {};
					inventorySlots[] = {};
				};
				class Chassis
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgzone_chassis"};
					componentNames[] = {"dmgzone_chassis"};
					class Health
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;

					};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class Engine
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgzone_engine"};
					componentNames[] = {"dmgzone_engine"};
					class Health
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0;

					};
					transferToZonesNames[] = {};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class Fuel
				{
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgzone_fuel"};
					memoryPoints[] = {"dmgzone_fuel"};
					class Health
					{
						hitpoints = 1700;
						transferToGlobalCoef = 0;

					};
					transferToZonesNames[] = {};
					inventorySlotsCoefs[] = {};
					inventorySlots[] = {};
				};
				class Rotor1
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgzone_rotor1"};
					componentNames[] = {"dmgzone_rotor1"};
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0;

					};
					transferToZonesNames[] = {};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class Rotor2
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgzone_rotor2"};
					componentNames[] = {"dmgzone_rotor2"};
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0;

					};
					transferToZonesNames[] = {};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				
			};
		};
		class AnimationSources:AnimationSources
		{
			class beam1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class beam2
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
		};
		class Crew: Crew
		{
			class Driver
			{
				actionSel = "seat_driver";
				proxyPos = "crewDriver";
				getInPos = "pos_driver";
				getInDir = "pos_driver_dir";
				isDriver = 0;	
			};
			class CoDriver
			{
				actionSel = "seat_coDriver";
				proxyPos = "crewCoDriver";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
				isDriver = 0;	
			};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewcargo1";
				getInPos = "pos_cargo1";
				getInDir = "pos_cargo1_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewcargo2";
				getInPos = "pos_cargo2";
				getInDir = "pos_cargo2_dir";
			};
			class Cargo3
			{
				actionSel = "seat_cargo3";
				proxyPos = "crewcargo3";
				getInPos = "pos_cargo3";
				getInDir = "pos_cargo3_dir";
			};
		};

	
	};
	class Helipolice_SIB4: HeliSIB_police_base
	{
		scope=2;
		displayName="Police";
		descriptionShort="Police";
	};
	class Helipolice_swat_SIB5: HeliSIB_police_base
	{
		
		scope=2;
		displayName="swat";
		descriptionShort="swat";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] ={"HelicopterSIB_police\data\Helicopter_Police_SWAT_D.paa"};
		hiddenSelectionsMaterials[] = {	"HelicopterSIB_police\data\heli_extsib_swat.rvmat"};
	};
};
	
class CfgSlots
{
	class Slot_SIBPolice_Door_1_1
	{
		name="SIBPolice_Door_1_1";
		displayName="Left Door";
		ghostIcon="doorfront";
	};
	class Slot_SIBPolice_Door_2_1
	{
		name="SIBPolice_Door_2_1";
		displayName="Right Door";
		ghostIcon="doorfront";
	};
	class Slot_SIBPolice_Door_1_2
	{
		name="SIBPolice_Door_1_2";
		displayName="Left Back Door";
		ghostIcon="doorrear";
	};
	class Slot_SIBPolice_Door_2_2
	{
		name="SIBPolice_Door_2_2";
		displayName="Right Back Door";
		ghostIcon="doorrear";
	};
};

class CfgNonAIVehicles
{
	class ProxyVehiclePart;
	class ProxySIBPolice_doors_driver: ProxyVehiclePart
	{
		model = "\HelicopterSIB_police\SIBPolice_doors_driver.p3d";
		inventorySlot = "SIBPolice_Door_1_1";
	};
	class ProxySIBPolice_doors_codriver: ProxyVehiclePart
	{
		model = "\HelicopterSIB_police\SIBPolice_doors_codriver.p3d";
		inventorySlot = "SIBPolice_Door_2_1";
	};
	class ProxySIBPolice_doors_cargo1: ProxyVehiclePart
	{
		model = "\HelicopterSIB_police\SIBPolice_doors_cargo1.p3d";
		inventorySlot = "SIBPolice_Door_1_2";
	};
	class ProxySIBPolice_doors_cargo2: ProxyVehiclePart
	{
		model = "\HelicopterSIB_police\SIBPolice_doors_cargo2.p3d";
		inventorySlot = "SIBPolice_Door_2_2";
	};
};