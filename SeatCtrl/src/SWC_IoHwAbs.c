/**
 *
 * \file SWC_IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_IoHwAbs.h"
#include "Adc.h"
#include "Spi.h"
#incline "Dio.h"

/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHight_Opr_IOGet
 *
 */
static Adc_ValueGroupType IoHwAb_PositionSensorsReadings[ADC_GR0_NUM_CHANNELS] = {0,0,0};
void RE_IoHwAbs_ECUGet_Height (Impl_IoPositionSensorReadingType* Arg_position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorsReadings);
	if(status == E_OK)
	{
		position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[0];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}


/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_Opr_IOGet
 *
 */

void RE_IoHwAbs_ECUGet_Incline (Impl_IoPositionSensorReadingType* Arg_position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorsReadings);
	if(status == E_OK)
	{
		position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[1];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}


/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_Opr_IOGet
 *
 */

void RE_IoHwAbs_ECUGet_Slide (Impl_IoPositionSensorReadingType* Arg_position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorsReadings);
	if(status == E_OK)
	{
		position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[2];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_Opr_IOGet
 *
 */

void RE_IoHwAbs_ECUGet_Weight (Impl_IoWeightSensorReadingType* Arg_weight)
{
	Std_ReturnType status;
	Spi_DataType spiData;
	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor, &spiData);
	if(status == E_OK)
	{

		Arg_weight= (Impl_IoWeightSensorReadingType)spiData;
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_HIGH); 
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_HIGH); 
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_HIGH); 
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_LOW); 
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_LOW); 
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_LOW); 
}

