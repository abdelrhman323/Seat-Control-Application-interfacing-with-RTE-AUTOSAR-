/**
 *
 * \file SWC_HeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightSensor.h"


/**
 *
 * Runnable RE_HeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightSensor_Opr_GetPosition
 *
 */

void RE_HeightSensor_GetPosition (Impl_SensorPositionType* Arg_position)
{
	Std_ReturnType status;
	Impl_IoPositionSensorReadingType Arg_position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetHeight_Opr_IOGet(&Arg_position);
	
}

