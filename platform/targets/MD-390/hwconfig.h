/***************************************************************************
 *   Copyright (C) 2020 by Federico Amedeo Izzo IU2NUO,                    *
 *                         Niccolò Izzo IU2KIN                             *
 *                         Silvano Seva IU2KWO                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#ifndef HWCONFIG_H
#define HWCONFIG_H

#include <stm32f4xx.h>

#define PLATFORM_MD390

/* Screen dimensions */
#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 128

/* Display */
#define LCD_D0  GPIOD,14
#define LCD_D1  GPIOD,15
#define LCD_D2  GPIOD,0
#define LCD_D3  GPIOD,1
#define LCD_D4  GPIOE,7
#define LCD_D5  GPIOE,8
#define LCD_D6  GPIOE,9
#define LCD_D7  GPIOE,10
#define LCD_WR  GPIOD,5
#define LCD_RD  GPIOD,4
#define LCD_CS  GPIOD,6
#define LCD_RS  GPIOD,12
#define LCD_RST GPIOD,13
#define LCD_BKLIGHT GPIOC,6

/* Signalling LEDs */
#define GREEN_LED  GPIOE,0
#define RED_LED    GPIOE,1

/* Analog inputs */
#define AIN_VOLUME GPIOA,0
#define AIN_VBAT   GPIOA,1
#define AIN_MIC    GPIOA,3
#define AIN_RSSI   GPIOB,0

/* Channel selection rotary encoder */
#define CH_SELECTOR_0 GPIOE,14
#define CH_SELECTOR_1 GPIOE,15
#define CH_SELECTOR_2 GPIOB,10
#define CH_SELECTOR_3 GPIOB,11

/* Push-to-talk switch */
#define PTT_SW GPIOE,11

/*
 * Keyboard. Here we define only rows, since coloumn lines are the same as
 * LCD_Dx. See also: https://www.qsl.net/dl4yhf/RT3/md380_hw.html#keyboard
 *
 * "Monitor" and "Function" buttons, on the other hand, are connected to
 * keyboard row 3 and on LCD_D7 and LCD_D6. See also the schematic.
 */
#define KB_ROW1 GPIOA,6 /* K1 */
#define KB_ROW2 GPIOD,2 /* K2 */
#define KB_ROW3 GPIOD,3 /* K3 */
#define MONI_SW LCD_D7
#define FUNC_SW LCD_D6

/* Tone generator  */
#define CTCSS_OUT GPIOC,7   /* System "beep" */
#define BEEP_OUT  GPIOC,8   /* CTCSS tone    */

#endif
