


modded class ActionHeliEnableLightPanelSIB_police
{
	bool m_IsFinished;
	override void OnStartServer( ActionData action_data ){m_IsFinished = false;}
	override void OnFinishProgressServer( ActionData action_data ){m_IsFinished = true;}
	override void OnEndServer( ActionData action_data )
	{		
		if ( m_IsFinished )
		{
			HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
			if( vehCommand )
			{
				Transport trans = vehCommand.GetTransport();
				if ( trans )
				{
					HeliSIB_police_base heli;
					if ( Class.CastTo(heli, trans) )
					{
						EntityAI Battery_police = heli.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CarBattery"));
						if ( !Battery_police || Battery_police && Battery_police.IsRuined() )
						{
							return;
						}
						EntityAI Reflector_1_1_police = heli.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Reflector_1_1"));
						if ( !Reflector_1_1_police || Reflector_1_1_police && Reflector_1_1_police.IsRuined() )
						{
							return;
						}
						heli.SetAnimationPhase("beam1", 1.0);
					}
				}
			}	
		}
	}
	
};

modded class ActionHeliDisableLightPanelSIB_police
{
	bool m_IsFinished;
	override void OnStartServer( ActionData action_data ){m_IsFinished = false;}
	override void OnFinishProgressServer( ActionData action_data ){m_IsFinished = true;}
	override void OnEndServer( ActionData action_data )
	{
		if ( m_IsFinished )
		{
			HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
			if( vehCommand )
			{
				Transport trans = vehCommand.GetTransport();
				if ( trans )
				{
					HeliSIB_police_base heli;
					if ( Class.CastTo(heli, trans) )
					{
						heli.SetAnimationPhase("beam1", 0.0);
					}
				}
			}
		}
	}
};

modded class ActionHeliEnableLightSIB_police
{
	bool m_IsFinished;
	override void OnStartServer( ActionData action_data ){m_IsFinished = false;}
	override void OnFinishProgressServer( ActionData action_data ){m_IsFinished = true;}
	override void OnEndServer( ActionData action_data )
	{		
		if ( m_IsFinished )
		{
			HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
			if( vehCommand )
			{
				Transport trans = vehCommand.GetTransport();
				if ( trans )
				{
					HeliSIB_police_base heli;
					if ( Class.CastTo(heli, trans) )
					{
						EntityAI Battery_police = heli.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CarBattery"));
						if ( !Battery_police || Battery_police && Battery_police.IsRuined() )
						{
							return;
						}
						EntityAI Reflector_2_1_police = heli.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Reflector_2_1"));
						if ( !Reflector_2_1_police || Reflector_2_1_police && Reflector_2_1_police.IsRuined() )
						{
							return;
						}
						heli.SetAnimationPhase("beam2", 1.0);
					}
				}
			}	
		}
	}
	
};

modded class ActionHeliDisableLightSIB_police
{
	bool m_IsFinished;
	override void OnStartServer( ActionData action_data ){m_IsFinished = false;}
	override void OnFinishProgressServer( ActionData action_data ){m_IsFinished = true;}
	override void OnEndServer( ActionData action_data )
	{
		if ( m_IsFinished )
		{
			HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
			if( vehCommand )
			{
				Transport trans = vehCommand.GetTransport();
				if ( trans )
				{
					HeliSIB_police_base heli;
					if ( Class.CastTo(heli, trans) )
					{
						heli.SetAnimationPhase("beam2", 0.0);
					}
				}
			}
		}
	}
};

modded  class PlayerBase
{
	override void SetActions(out TInputActionMap InputActionMap)
	{
		//black_hawk 
		AddAction(ActionHeliEnableLightSIB_police, InputActionMap);
		AddAction(ActionHeliEnableLightPanelSIB_police, InputActionMap);
		AddAction(ActionHeliDisableLightSIB_police, InputActionMap);
		AddAction(ActionHeliDisableLightPanelSIB_police, InputActionMap);
		super.SetActions(InputActionMap);
	}
}
modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		actions.Insert(ActionHeliEnableLightSIB_police);
		actions.Insert(ActionHeliEnableLightPanelSIB_police);
		actions.Insert(ActionHeliDisableLightSIB_police);
		actions.Insert(ActionHeliDisableLightPanelSIB_police);
		super.RegisterActions(actions);
	}
}