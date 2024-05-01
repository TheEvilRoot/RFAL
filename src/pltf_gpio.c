/******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2020 STMicroelectronics</center></h2>
  *
  * Licensed under ST MYLIBERTY SOFTWARE LICENSE AGREEMENT (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/myliberty
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied,
  * AND SPECIFICALLY DISCLAIMING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
******************************************************************************/

/*! \file pltf_gpio.c
 *
 *  \author
 *
 *  \brief Implementation of GPIO specific functions and its helper functions.
 *  
 */

/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include <Arduino.h>
#include "pltf_gpio.h"
#include "rfal_platform.h"

/* Extern semaphore to signal once an interrupt occurs */
/*
 ******************************************************************************
 * DEFINES
 ******************************************************************************
 */
/* Max size of file path to access */


stError rfal_gpio_init(void)
{
  pinMode(ST25R_INT_PIN, INPUT);
  pinMode(ST25R_SS_PIN, OUTPUT);
}

GPIO_PinState gpio_readpin(int port, int pin_no)
{
    return digitalRead(pin_no) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

stError interrupt_init(void)
{
}

void gpio_set_value(int port, int pin_no, uint8_t value)
{
   digitalWrite(pin_no, value ? HIGH : LOW);
}


void gpio_set(int port, int pin_no)
{
    digitalWrite(pin_no, HIGH);
}

void gpio_clear(int port, int pin_no)
{
  digitalWrite(pin_no, LOW);
}

void pltf_protect_interrupt_status(void)
{
}

void pltf_unprotect_interrupt_status(void)
{
}

void pltf_protect_worker(void)
{
}

void pltf_unprotect_worker(void)
{
}
