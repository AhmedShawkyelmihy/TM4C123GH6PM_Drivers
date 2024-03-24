/*
 ============================================================================
 Name        : GPIO_Private.h
 Author      : Ahmed Shawky
 Description : Private Header File for TM4C123GH6PM GPIO Driver.
 Date        : 22/03/2024
 ============================================================================
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/****************************************************************************
 * 				Include                                     *
 ****************************************************************************/
#include "../../Includes/Std_Types.h"

/****************************************************************************
 * 			       Definitions				    *
 ****************************************************************************/
#define SYSCTL_BASE             0x400FE000
#define RCGCGPIO_OFFSET         0x608

#define GPIO_PORTA_BASE         0x40004000
#define GPIO_PORTB_BASE         0x40005000
#define GPIO_PORTC_BASE         0x40006000
#define GPIO_PORTD_BASE         0x40007000
#define GPIO_PORTE_BASE         0x40024000
#define GPIO_PORTF_BASE         0x40025000



#define GPIO_DATA_OFFSET        0x3FC
#define GPIO_DIR_OFFSET         0x400
#define GPIO_AFSEL_OFFSET       0x420
#define GPIO_DEN_OFFSET         0x51C
#define GPIO_AMSEL_OFFSET       0x528
#define GPIO_PUR_OFFSET         0x510

#endif /* GPIO_PRIVATE_H_ */
