/**
 *
 * \file SWC_HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightMotor.h"


/**
 *
 * Runnable RE_HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHighthMotor_Opr_HeightMotor_Move
 *
 */

void RE_HeightMotor_Move (Impl_StepMotorStepType Arg_Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	status = Rte_Call_rpIOSetHeight_Opr_IOSetForward();
	status = Rte_Call_rpIOSetHeight_Opr_IOSetReverse();
	
}

