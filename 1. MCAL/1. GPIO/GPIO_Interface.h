/*
 ============================================================================
 Name        : GPIO_Interface.h
 Author      : Ahmed Shawky
 Description : Interface Header File for TM4C123GH6PM GPIO Driver.
 Date        : 22/03/2024
 ============================================================================
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/****************************************************************************
 * 				Include                                     *
 ****************************************************************************/
#include "../../Includes/Std_Types.h"

/****************************************************************************
 * 			       Definitions				    *
 ****************************************************************************/
#define PORTA_ID                0
#define PORTB_ID                1
#define PORTC_ID                2
#define PORTD_ID                3
#define PORTE_ID                4
#define PORTF_ID                5

#define PIN0_ID                 0   
#define PIN1_ID                 1 
#define PIN2_ID                 2 
#define PIN3_ID                 3
#define PIN4_ID                 4   
#define PIN5_ID                 5 
#define PIN6_ID                 6 
#define PIN7_ID                 7

#define PIN_INPUT               0
#define PIN_OUTPUT              1

#define PIN_DIGITAL_DISABLE     0
#define PIN_DIGITAL_ENABLE      1

#define PIN_LOW                 0
#define PIN_HIGH                1

#define PIN_PULL_DOWN           0
#define PIN_PULL_UP             1
#define PIN_NO_RESISTOR         2

/****************************************************************************
 * 			     Types Declaration				    *
 ****************************************************************************/

typedef struct
{
    u8 Port_Num ;
    u8 Pin_Num ;
    u8 Pin_Direction ;
    u8 Pin_Digital ;
    u8 Pin_Data ;
    u8 Pin_Internal_Resistor ;
}GPIO_ConfigType;


/****************************************************************************
 * 			    Functions Prototypes			    *
 ****************************************************************************/
void M_GPIO_Void_Init(GPIO_ConfigType* Config_Ptr);
void M_GPIO_Void_SetPinDirection(u8 Copy_u8_Port, u8 Copy_u8_Pin, u8 Copy_u8_Direction);
void M_GPIO_Void_SetPinPullup(u8 Copy_u8_Port , u8 Copy_u8_Pin, u8 Copy_u8_Enable);
u8 M_GPIO_Void_ReadPin(u8 Copy_u8_Port, u8 Copy_u8_Pin);
void M_GPIO_Void_WritePin(u8 Copy_u8_Port, u8 Copy_u8_Pin, u8 Copy_u8_Value);
void M_GPIO_Void_TogglePin(u8 Copy_u8_Port, u8 Copy_u8_Pin);

#endif /* GPIO_INTERFACE_H_ */