

class SIBPolice_Door_1_1 extends CarDoor {};
class SIBPolice_Door_1_2 extends CarDoor {};
class SIBPolice_Door_2_1 extends CarDoor {};
class SIBPolice_Door_2_2 extends CarDoor {};


class HeliSIB_police_base extends HeliSIB_middle
{

	
	override void EEInit()
	{
		super.EEInit();
		c_startSound = "HelicopterStart_SoundSets_police";
		c_stopSound = "HelicopterStop_SoundSets_police";
		c_engineSound = "HelicopterEngine_SoundSets_polices";
		c_rotorSound = "HelicopterRotor_SoundSets_police";
		c_fuelDistance = 15;
	}
	
	
	override void creat_InInventory_heli()
	{
		
		if(IsKindOf("Helipolice_swat_SIB5"))
		{
			GetInventory().CreateInInventory( "SIBPolice_Door_1_1_swat" );
			GetInventory().CreateInInventory( "SIBPolice_Door_1_2_swat" );
			GetInventory().CreateInInventory( "SIBPolice_Door_2_1_swat" );
			GetInventory().CreateInInventory( "SIBPolice_Door_2_2_swat" );
			
			GetInventory().CreateInInventory( "CarBattery" );
			GetInventory().CreateInInventory( "HeadlightH7" );
			GetInventory().CreateInInventory( "HeadlightH7" );
			return;
		}
		if(IsKindOf("Helipolice_SIB4"))
		{
			GetInventory().CreateInInventory( "SIBPolice_Door_1_1" );
			GetInventory().CreateInInventory( "SIBPolice_Door_1_2" );
			GetInventory().CreateInInventory( "SIBPolice_Door_2_1" );
			GetInventory().CreateInInventory( "SIBPolice_Door_2_2" );

			GetInventory().CreateInInventory( "CarBattery" );
			GetInventory().CreateInInventory( "HeadlightH7" );
			GetInventory().CreateInInventory( "HeadlightH7" );
			return;
		}

		super.creat_InInventory_heli();
	};



	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "SIBPolice_Door_1_1";
			break;
		case 1:
			return "SIBPolice_Door_2_1";
			break;
		case 2:
			return "SIBPolice_Door_1_2";
			break;
		case 3:
			return "SIBPolice_Door_2_2";
			break;
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}
	


	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor )return CarDoorState.DOORS_MISSING;
		
		switch( slotType )
		{
		case "SIBPolice_Door_1_1":
			if ( GetAnimationPhase("DoorsDriver") > 0.1 )
			return CarDoorState.DOORS_OPEN;
			else
			return CarDoorState.DOORS_CLOSED;

			break;
			
		case "SIBPolice_Door_2_1":
			if ( GetAnimationPhase("DoorsCoDriver") > 0.1 )
			return CarDoorState.DOORS_OPEN;
			else
			return CarDoorState.DOORS_CLOSED;

			break;
			
		case "SIBPolice_Door_1_2":
			if ( GetAnimationPhase("DoorsCargo1") > 0.1 )
			return CarDoorState.DOORS_OPEN;
			else
			return CarDoorState.DOORS_CLOSED;

			break;
			
		case "SIBPolice_Door_2_2":
			if ( GetAnimationPhase("DoorsCargo2") > 0.1 )
			return CarDoorState.DOORS_OPEN;
			else
			return CarDoorState.DOORS_CLOSED;
			break;
			
			
			
		}

		return CarDoorState.DOORS_MISSING;
	}
	

	

	override bool CrewCanGetThrough( int posIdx )
	{
		switch( posIdx )
		{
		case 0:// водитель
			if ( GetCarDoorsState( "SIBPolice_Door_1_1" ) == CarDoorState.DOORS_CLOSED )
			return false;

			return true;
			break;
			
		case 1:// ко водитель
			if ( GetCarDoorsState( "SIBPolice_Door_2_1" ) == CarDoorState.DOORS_CLOSED )
			return false;
			
			return true;
			break;
		case 2:  //  пассажир водителя
		case 4: // пассажир ко поссажира
		case 6:
		case 8:
			if ( GetCarDoorsState( "SIBPolice_Door_1_2" ) == CarDoorState.DOORS_CLOSED )
			return false;

			return true;
			break;
		case 3: //ко пассажир ко водителя
		case 5:
		case 7:
		case 9:
			if ( GetCarDoorsState( "SIBPolice_Door_2_2" ) == CarDoorState.DOORS_CLOSED )
			return false;

			return true;
			break;
		}

		return false;
	}
	
	override int GetSeatAnimationType( int posIdx )
	{
		switch( posIdx )
		{
		case 0: // водитель
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 1: // ко водитель
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		case 2: //  пассажир водителя
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 3: // ко пассажир ко водителя
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		case 4: // пассажир ко поссажира
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 5:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 6:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 7:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		case 8:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 9:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		}
		return 0;
	}
	override bool CanReachSeatFromSeat( int currentSeat, int nextSeat )
	{
		switch( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 || nextSeat == 2 || nextSeat == 3 || nextSeat == 4 || nextSeat == 5 || nextSeat == 6 || nextSeat == 7 || nextSeat == 8 || nextSeat == 9)
			return true;
			break;
		case 1:
			if ( nextSeat == 0 ||nextSeat == 2 || nextSeat == 3 || nextSeat == 4 || nextSeat == 5 || nextSeat == 6 || nextSeat == 7 || nextSeat == 8 || nextSeat == 9)
			return true;
			break;
		case 2:
			if ( nextSeat == 0 || nextSeat == 1 ||  nextSeat == 3 || nextSeat == 4 || nextSeat == 5 || nextSeat == 6 || nextSeat == 7 || nextSeat == 8 || nextSeat == 9)
			return true;
			break;
		case 3:
			if ( nextSeat == 0 || nextSeat == 1 || nextSeat == 2 ||  nextSeat == 4 || nextSeat == 5 || nextSeat == 6 || nextSeat == 7 || nextSeat == 8 || nextSeat == 9)
			return true;
			break;
		case 4:
			if ( nextSeat == 0 || nextSeat == 1 || nextSeat == 2 || nextSeat == 3 || nextSeat == 5 || nextSeat == 6 || nextSeat == 7 || nextSeat == 8 || nextSeat == 9)
			return true;
			break;
		case 5:
			if ( nextSeat == 0 || nextSeat == 1 || nextSeat == 2 || nextSeat == 3 || nextSeat == 4 ||  nextSeat == 6 || nextSeat == 7 || nextSeat == 8 || nextSeat == 9)
			return true;
			break;
		case 6:
			if ( nextSeat == 0 || nextSeat == 1 || nextSeat == 2 || nextSeat == 3 || nextSeat == 4 || nextSeat == 5 || nextSeat == 7 || nextSeat == 8 || nextSeat == 9)
			return true;
			break;
		case 7:
			if ( nextSeat == 0 || nextSeat == 1 || nextSeat == 2 || nextSeat == 3 || nextSeat == 4 || nextSeat == 5 || nextSeat == 6 || nextSeat == 8 || nextSeat == 9)
			return true;
			break;
		case 8:
			if ( nextSeat == 0 || nextSeat == 1 || nextSeat == 2 || nextSeat == 3 || nextSeat == 4 || nextSeat == 5 || nextSeat == 6 || nextSeat == 7 || nextSeat == 9)
			return true;
			break;
		case 9:
			if ( nextSeat == 0 || nextSeat == 1 || nextSeat == 2 || nextSeat == 3 || nextSeat == 4 || nextSeat == 5 || nextSeat == 6 || nextSeat == 7 || nextSeat == 8 )
			return true;
			break;
		}
		
		return false;
	}
	


	override string GetDoorConditionPointFromSelection( string selection )
	{
		switch( selection )
		{
		case "seat_driver":
			return "seat_con_1_1";
			break;
		case "seat_codriver":
			return "seat_con_2_1";
			break;

		case "seat_cargo1":
		case "seat_cargo3":
		case "seat_cargo5":
		case "seat_cargo7":
			return "seat_con_1_2";
			break;
		case "seat_cargo2":
		case "seat_cargo4":
		case "seat_cargo8":
		case "seat_cargo6":
			return "seat_con_2_2";
			break;

		}
		
		return "";
	}
	
	
	
	
	
	HeliLightPanel_police m_LightPanel_1_police;
	HeliLightPanel_police m_LightPanel_2_police;
	HeliLightPanel_police m_LightPanel_3_police;
	HeliLightPanel_police m_LightPanel_4_police;
	HeliLight_police m_Light_1_police;
	
	
	void SimulateLight(float dt)
	{
		float beam1 = GetAnimationPhase("beam1");
		if(beam1 == 1)
		{
			if(m_LightPanel_1_police == NULL)
			{
				m_LightPanel_1_police = HeliLightPanel_police.Cast( ScriptedLightBase.CreateLight( HeliLightPanel_police, "0 0 0") );
				m_LightPanel_1_police.AttachOnMemoryPoint(this, "beamStart10","beamEnd10");
			}
			if(m_LightPanel_2_police == NULL)
			{
				m_LightPanel_2_police = HeliLightPanel_police.Cast( ScriptedLightBase.CreateLight( HeliLightPanel_police, "0 0 0") );
				m_LightPanel_2_police.AttachOnMemoryPoint(this, "beamStart11","beamEnd11");
			}
			if(m_LightPanel_3_police == NULL)
			{
				m_LightPanel_3_police = HeliLightPanel_police.Cast( ScriptedLightBase.CreateLight( HeliLightPanel_police, "0 0 0") );
				m_LightPanel_3_police.AttachOnMemoryPoint(this, "beamStart12","beamEnd12");
			}
			if(m_LightPanel_4_police == NULL)
			{
				m_LightPanel_4_police = HeliLightPanel_police.Cast( ScriptedLightBase.CreateLight( HeliLightPanel_police, "0 0 0") );
				m_LightPanel_4_police.AttachOnMemoryPoint(this, "beamStart13","beamEnd13");
			}
		}else{
			if (m_LightPanel_1_police)m_LightPanel_1_police.FadeOut();
			if (m_LightPanel_2_police)m_LightPanel_2_police.FadeOut();
			if (m_LightPanel_3_police)m_LightPanel_3_police.FadeOut();
			if (m_LightPanel_4_police)m_LightPanel_4_police.FadeOut();
		}

		float beam2 = GetAnimationPhase("beam2");
		if(beam2 == 1)
		{
			if(m_Light_1_police == NULL)
			{
				m_Light_1_police = HeliLight_police.Cast( ScriptedLightBase.CreateLight( HeliLight_police, "0 0 0") );
				m_Light_1_police.AttachOnMemoryPoint(this, "beamStart2","beamEnd2");
			}
		}else{
			if (m_Light_1_police)m_Light_1_police.FadeOut();
		}
	}
	override void SoundAnim_Simulate(float dt)
	{
		if ( GetGame().IsClient()  && m_enable)
		{
			SimulateLight(dt);
		}
		super.SoundAnim_Simulate(dt);
	}


	override bool CanDisplayAttachmentCategory( string category_name )
	{
		category_name.ToLower();
		if(category_name == "chassis")return false;
		return true;
	}
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		string attType = attachment.GetType();
		if(attType=="HeadlightH7" )return true;
		if( attType == "HatchbackWheel" )return false;
		return true;
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached( item, slot_name );
		if(slot_name == "CarBattery" || slot_name == "Reflector_1_1" || slot_name == "Reflector_2_1")
		{
			SetAnimationPhase("beam1", 0.0);
			SetAnimationPhase("beam2", 0.0);
		}
	}
	override void OnAttachmentRuined(EntityAI attachment)
	{
		super.OnAttachmentRuined( attachment );
		if(attachment && attachment.IsRuined())
		{
			if(attachment.GetType()=="HeadlightH7")
			{
				SetAnimationPhase("beam2", 0.0);
			}
		}
	}


};



modded class ActionHeliStartEngineSIB
{
	override void StartEngineSIB(HeliTest_SIB heli)
	{
		if(heli.IsKindOf("HeliSIB_police_base"))
		{
			EntityAI Battery_police = heli.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CarBattery"));
			if ( !Battery_police || Battery_police && Battery_police.IsRuined() )
			{
				return;
			}
		}
		super.StartEngineSIB(heli);
	}
};


class Helipolice_SIB4 extends HeliSIB_police_base{};
class Helipolice_swat_SIB5 extends HeliSIB_police_base{};
