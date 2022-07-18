/**
 *
 * \file SWC_InclineSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineSensor.h"


/**
 *
 * Runnable RE_InclineSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineSensor_Opr_GetPosition
 *
 */

void RE_InclineSensor_GetPosition (Impl_SensorPositionType* Arg_Position)
{
	Impl_IoPositionSensorReadingType Arg_position;
	(void)Rte_Call_rpIOGetIncline_Opr_IOGet(&Arg_position);
		if(Arg_position == 0)
	{
		Arg_Position = SENSOR_POSITION_STEP_0;
	}
	else if(Arg_position > 0 && Arg_position <= 64)
	{
		Arg_Position = SENSOR_POSITION_STEP_1;
	}
	else if(Arg_position > 64 && Arg_position <= 192)
	{
		Arg_Position = SENSOR_POSITION_STEP_2;
	}
	else
	{
		Arg_Position = SENSOR_POSITION_STEP_3;
	}
	
}

