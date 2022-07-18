/**
 *
 * \file SWC_SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/25/2022 03:21 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatManager.h"

static boolean IsMotorAdjustNeeded(SensorPositionType Position, SensorWeightType Weight, StepMotorStepType* Step)
{
	boolean adjustMotor = FALSE;
	
	switch(Position)
	{
		case SENSOR_POSITION_STEP_0:
			if(Weight > 60)
			{
				Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			break;
			
		case SENSOR_POSITION_STEP_1:
			if(Weight > 80)
			{
				Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			else if(Weight <= 80 && Weight >= 60)
			{
				/* Position OK */
			}
			else
			{
				Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;
			
		case SENSOR_POSITION_STEP_2:
			if(Weight > 100)
			{
				Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			else if(Weight <= 100 && Weight >= 80)
			{
				/* Position OK */
			}
			else
			{
				Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;
			
		case SENSOR_POSITION_STEP_3:
			if(Weight < 100)
			{
				Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;		
			
		default:
			break;
	}
	
	return adjustMotor;
}


/**
 *
 * Runnable RE_SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoHeight_200ms
 *
 */

void RE_SeatManager_AutoHeight (void)
{

	Impl_StepMotorStepType Arg_Step;
	Impl_SensorPositionType Arg_position;
	Impl_SensorWeightType Arg_Weight;
	boolean Isadjusted;	

	(void) Rte_Call_rpHeightSensor_Opr_GetPosition(&Arg_position);
	(void) Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);

	Isadjusted = IsMotorAdjustNeeded(Arg_position,Arg_Weight,&Arg_Step);
	
	if(Isadjusted)
	{
	  (void) Rte_Call_rpHeightMotor_Opr_HeightMotor_Move(Arg_Step);
	}	
}


/**
 *
 * Runnable RE_SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoIncline_200ms
 *
 */

void RE_SeatManager_AutoIncline (void)
{
	Impl_StepMotorStepType Arg_Step;
	Impl_SensorPositionType Arg_position;
	Impl_SensorWeightType Arg_Weight;
	boolean Isadjusted;	

	(void) Rte_Call_rpInclineSensor_Opr_GetPosition(&Arg_position);
	(void) Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);

	Isadjusted = IsMotorAdjustNeeded(Arg_position,Arg_Weight,&Arg_Step);
	
	if(Isadjusted)
	{
	  (void) Rte_Call_rpInclineMotor_Opr_InclineMotor_Move(Arg_Step);
	}		
}


/**
 *
 * Runnable RE_SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoSlide_200ms
 *
 */

void RE_SeatManager_AutoSlide (void)
{
	Impl_StepMotorStepType Arg_Step;
	Impl_SensorPositionType Arg_position;
	Impl_SensorWeightType Arg_Weight;
	boolean Isadjusted;	

	(void) Rte_Call_rpSlideSensor_Opr_GetPosition(&Arg_position);
	(void) Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);

	Isadjusted = IsMotorAdjustNeeded(Arg_position,Arg_Weight,&Arg_Step);
	
	if(Isadjusted)
	{
	  (void) Rte_Call_rpSlideMotor_Opr_SlideMotor_Move(Arg_Step);
	}			
}

/**
 *
 * Runnable RE_SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_HeightBtnState
 *
 */

void RE_SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_HeightBtnState;

	(void) Rte_Read_rpSeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);
	if(DE_HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
	 (void) Rte_Call_SWC_HightMotor_ppHightMotor_Move(MULTI_STATE_BTN_MINUS); 
	}
	else if (DE_HeightBtnState == MULTI_STATE_BTN_PLUS)	
	{
	  (void)Rte_Call_rpHightMotor_Move(MULTI_STATE_BTN_PLUS); 
	}
}


/**
 *
 * Runnable RE_SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_InclineBtnState
 *
 */

void RE_SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_InclineBtnState;

	(void) Rte_Read_rpSeatCtrlBtns_DE_Incline BtnState(&DE_InclineBtnState);
	if(DE_InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
	 (void) Rte_Call_SWC_Incline Motor_ppInclineMotor_Move(MULTI_STATE_BTN_MINUS); 
	}
	else if (DE_InclineBtnState == MULTI_STATE_BTN_PLUS)	
	{
	 (void)Rte_Call_rpInclineMotor_Move(MULTI_STATE_BTN_PLUS); 
	}	
}


/**
 *
 * Runnable RE_SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_SlideBtnState
 *
 */

void RE_SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_SlideBtnState;

	(void) Rte_Read_rpSeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
	if(DE_SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
	 (void)Rte_Call_rpSlideMotor_Move(MULTI_STATE_BTN_MINUS); 
	}
	else if (DE_SlideBtnState == MULTI_STATE_BTN_PLUS)	
	{
	 (void)Rte_Call_rpSlideMotor_Move(MULTI_STATE_BTN_PLUS); 
	}		
}

