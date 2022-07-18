/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineMotor.h"


/**
 *
 * Runnable RE_InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Opr_InclineMotor_Move
 *
 */

void RE_InclineMotor_Move (Impl_MultiStateBtnType Arg_Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	status = Rte_Call_rpIOSetIncline_Opr_IOSetForward();
	status = Rte_Call_rpIOSetIncline_Opr_IOSetReverse();
	
}

