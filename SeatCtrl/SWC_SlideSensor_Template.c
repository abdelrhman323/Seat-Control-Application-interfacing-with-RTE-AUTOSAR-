/**
 *
 * \file SWC_SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideSensor.h"


/**
 *
 * Runnable RE_SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_Opr_GetPosition
 *
 */

void RE_SlideSensor_GetPosition (Impl_SensorPositionType* Arg_position)
{
	Std_ReturnType status;
	Impl_IoPositionSensorReadingType Arg_position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetSlide_Opr_IOGet(&Arg_position);
	
}

