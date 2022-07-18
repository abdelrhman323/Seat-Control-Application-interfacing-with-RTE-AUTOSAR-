/**
 *
 * \file SWC_SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 06:25 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatManager.h"


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
	Std_ReturnType status;
	Impl_StepMotorStepType Arg_Step;
	Impl_SensorPositionType Arg_position;
	Impl_SensorWeightType Arg_Weight;

	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Opr_HeightMotor_Move(Arg_Step);
	status = Rte_Call_rpHeightSensor_Opr_GetPosition(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
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
	Std_ReturnType status;
	Impl_MultiStateBtnType Arg_Step;
	Impl_SensorPositionType Arg_position;
	Impl_SensorWeightType Arg_Weight;

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_InclineMotor_Move(Arg_Step);
	status = Rte_Call_rpInclineSensor_Opr_GetPosition(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
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
	Std_ReturnType status;
	Impl_StepMotorStepType Arg_Step;
	Impl_SensorPositionType Arg_position;
	Impl_SensorWeightType Arg_Weight;

	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Opr_SlideMotor_Move(Arg_Step);
	status = Rte_Call_rpSlideSensor_Opr_GetPosition(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
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
	Impl_StepMotorStepType Arg_Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Opr_HeightMotor_Move(Arg_Step);
	
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
	Impl_MultiStateBtnType Arg_Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_InclineMotor_Move(Arg_Step);
	
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
	Impl_StepMotorStepType Arg_Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Opr_SlideMotor_Move(Arg_Step);
	
}

