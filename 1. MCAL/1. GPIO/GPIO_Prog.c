/*
 ============================================================================
 Name        : GPIO_Prog.h
 Author      : Ahmed Shawky
 Description : Program Source File for TM4C123GH6PM GPIO Driver.
 Date        : 22/03/2024
 ============================================================================
 */

/****************************************************************************
 * 				Include                                     *
 ****************************************************************************/
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "../../Includes/Common_Macros.h"

/****************************************************************************
 * 			  Functions Definitions				    *
 ****************************************************************************/
void M_GPIO_Void_Init(GPIO_ConfigType* Config_Ptr)
{
    u32 Local_u32_Base = 0 ;

    switch(Config_Ptr->Port_Num)
    {
        case PORTA_ID :
        Local_u32_Base = GPIO_PORTA_BASE ;
        break;
        case PORTB_ID :
        Local_u32_Base = GPIO_PORTB_BASE ;
        break;
        case PORTC_ID :
        Local_u32_Base = GPIO_PORTC_BASE ;
        break;
        case PORTD_ID :
        Local_u32_Base = GPIO_PORTD_BASE ;
        break;
        case PORTE_ID :
        Local_u32_Base = GPIO_PORTE_BASE ;
        break;
        case PORTF_ID :
        Local_u32_Base = GPIO_PORTF_BASE ;
        break;
    }
    
    /* Write the clock gating bit for the spcified port. */
    SET_BIT((*((u32 *)(SYSCTL_BASE | RCGCGPIO_OFFSET))),(Config_Ptr->Port_Num));
    
    /* Enable/disable digital I/O pin. */
    switch(Config_Ptr->Pin_Digital)
    {
        case PIN_DIGITAL_DISABLE :
        CLR_BIT((*((u32 *)(Local_u32_Base | GPIO_DEN_OFFSET))),(Config_Ptr->Pin_Num));
        break;
        case PIN_DIGITAL_ENABLE :
        SET_BIT((*((u32 *)(Local_u32_Base | GPIO_DEN_OFFSET))),(Config_Ptr->Pin_Num));
        break;
    }

    /* Specifiy the direction input/output for the pin. */
    switch(Config_Ptr->Pin_Direction)
    {
        case PIN_INPUT :
        CLR_BIT((*((u32 *)(Local_u32_Base | GPIO_DIR_OFFSET))),(Config_Ptr->Pin_Num));
        break;
        case PIN_OUTPUT :
        SET_BIT((*((u32 *)(Local_u32_Base | GPIO_DIR_OFFSET))),(Config_Ptr->Pin_Num));
        break;
    }

    switch(Config_Ptr->Pin_Data)
    {
        case PIN_LOW :
        CLR_BIT((*((u32 *)(Local_u32_Base | GPIO_DATA_OFFSET))),(Config_Ptr->Pin_Num));
        break;
        case PIN_HIGH :
        SET_BIT((*((u32 *)(Local_u32_Base | GPIO_DATA_OFFSET))),(Config_Ptr->Pin_Num));
        break;
    }

    switch(Config_Ptr->Pin_Internal_Resistor)
    {
        case PIN_PULL_DOWN :

        break;
        case PIN_PULL_UP :
        SET_BIT((*((u32 *)(Local_u32_Base | GPIO_PUR_OFFSET))),(Config_Ptr->Pin_Num));
        break;
    }
}

void M_GPIO_Void_SetPinDirection(u8 Copy_u8_Port, u8 Copy_u8_Pin, u8 Copy_u8_Direction)
{
    u32 Local_u32_Base = 0 ;

    switch(Copy_u8_Port)
    {
        case PORTA_ID :
        Local_u32_Base = GPIO_PORTA_BASE ;
        break;
        case PORTB_ID :
        Local_u32_Base = GPIO_PORTB_BASE ;
        break;
        case PORTC_ID :
        Local_u32_Base = GPIO_PORTC_BASE ;
        break;
        case PORTD_ID :
        Local_u32_Base = GPIO_PORTD_BASE ;
        break;
        case PORTE_ID :
        Local_u32_Base = GPIO_PORTE_BASE ;
        break;
        case PORTF_ID :
        Local_u32_Base = GPIO_PORTF_BASE ;
        break;
    }

    switch(Copy_u8_Direction)
    {
        case PIN_INPUT :
        CLR_BIT((*((u32 *)(Local_u32_Base | GPIO_DIR_OFFSET))),Copy_u8_Pin);
        break;
        case PIN_OUTPUT :
        SET_BIT((*((u32 *)(Local_u32_Base | GPIO_DIR_OFFSET))),Copy_u8_Pin);
        break;
    }
}

void M_GPIO_Void_SetPinPullup(u8 Copy_u8_Port , u8 Copy_u8_Pin, u8 Copy_u8_Enable)
{
    u32 Local_u32_Base = 0 ;

    switch(Copy_u8_Port)
    {
        case PORTA_ID :
        Local_u32_Base = GPIO_PORTA_BASE ;
        break;
        case PORTB_ID :
        Local_u32_Base = GPIO_PORTB_BASE ;
        break;
        case PORTC_ID :
        Local_u32_Base = GPIO_PORTC_BASE ;
        break;
        case PORTD_ID :
        Local_u32_Base = GPIO_PORTD_BASE ;
        break;
        case PORTE_ID :
        Local_u32_Base = GPIO_PORTE_BASE ;
        break;
        case PORTF_ID :
        Local_u32_Base = GPIO_PORTF_BASE ;
        break;
    }

    switch(Copy_u8_Enable)
    {
        case PIN_PULL_DOWN :
        //CLR_BIT((*((u32 *)(Local_u32_Base | GPIO_PUR_OFFSET))),Copy_u8_Pin);
        break;
        case PIN_PULL_UP :
        SET_BIT((*((u32 *)(Local_u32_Base | GPIO_PUR_OFFSET))),Copy_u8_Pin);
        break;
    }
}

u8 M_GPIO_Void_ReadPin(u8 Copy_u8_Port, u8 Copy_u8_Pin)
{
    u32 Local_u32_Base = 0 ;
    u8 Local_u8_Value = 0 ;

    switch(Copy_u8_Port)
    {
        case PORTA_ID :
        Local_u32_Base = GPIO_PORTA_BASE ;
        break;
        case PORTB_ID :
        Local_u32_Base = GPIO_PORTB_BASE ;
        break;
        case PORTC_ID :
        Local_u32_Base = GPIO_PORTC_BASE ;
        break;
        case PORTD_ID :
        Local_u32_Base = GPIO_PORTD_BASE ;
        break;
        case PORTE_ID :
        Local_u32_Base = GPIO_PORTE_BASE ;
        break;
        case PORTF_ID :
        Local_u32_Base = GPIO_PORTF_BASE ;
        break;
    }

    Local_u8_Value = GET_BIT((*((u32 *)(Local_u32_Base | GPIO_DATA_OFFSET))),Copy_u8_Pin);

    return Local_u8_Value ;
}

void M_GPIO_Void_WritePin(u8 Copy_u8_Port, u8 Copy_u8_Pin, u8 Copy_u8_Value)
{
    u32 Local_u32_Base = 0 ;

    switch(Copy_u8_Port)
    {
        case PORTA_ID :
        Local_u32_Base = GPIO_PORTA_BASE ;
        break;
        case PORTB_ID :
        Local_u32_Base = GPIO_PORTB_BASE ;
        break;
        case PORTC_ID :
        Local_u32_Base = GPIO_PORTC_BASE ;
        break;
        case PORTD_ID :
        Local_u32_Base = GPIO_PORTD_BASE ;
        break;
        case PORTE_ID :
        Local_u32_Base = GPIO_PORTE_BASE ;
        break;
        case PORTF_ID :
        Local_u32_Base = GPIO_PORTF_BASE ;
        break;
    }

    switch(Copy_u8_Value)
    {
        case PIN_LOW :
        CLR_BIT((*((u32 *)(Local_u32_Base | GPIO_DATA_OFFSET))),Copy_u8_Pin);
        break;
        case PIN_HIGH :
        SET_BIT((*((u32 *)(Local_u32_Base | GPIO_DATA_OFFSET))),Copy_u8_Pin);
        break;
    }
}

void M_GPIO_Void_TogglePin(u8 Copy_u8_Port, u8 Copy_u8_Pin)
{
    u32 Local_u32_Base = 0 ;
    u8 Local_u8_Value = 0 ;

    switch(Copy_u8_Port)
    {
        case PORTA_ID :
        Local_u32_Base = GPIO_PORTA_BASE ;
        break;
        case PORTB_ID :
        Local_u32_Base = GPIO_PORTB_BASE ;
        break;
        case PORTC_ID :
        Local_u32_Base = GPIO_PORTC_BASE ;
        break;
        case PORTD_ID :
        Local_u32_Base = GPIO_PORTD_BASE ;
        break;
        case PORTE_ID :
        Local_u32_Base = GPIO_PORTE_BASE ;
        break;
        case PORTF_ID :
        Local_u32_Base = GPIO_PORTF_BASE ;
        break;
    }

    Local_u8_Value = GET_BIT((*((u32 *)(Local_u32_Base | GPIO_DATA_OFFSET))),Copy_u8_Pin); 

    switch(Local_u8_Value)
    {
        case PIN_LOW :
        SET_BIT((*((u32 *)(Local_u32_Base | GPIO_DATA_OFFSET))),Copy_u8_Pin);
        break;
        case PIN_HIGH :
        CLR_BIT((*((u32 *)(Local_u32_Base | GPIO_DATA_OFFSET))),Copy_u8_Pin);
        break;
    }
}
