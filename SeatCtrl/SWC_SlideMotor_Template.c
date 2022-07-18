/**
 *
 * \file SWC_SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideMotor.h"


/**
 *
 * Runnable RE_SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Opr_SlideMotor_Move
 *
 */

void RE_SlideMotor_Move (Impl_StepMotorStepType Arg_Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	status = Rte_Call_rpIOSetSlide_Opr_IOSetForward();
	status = Rte_Call_rpIOSetSlide_Opr_IOSetReverse();
	
}

