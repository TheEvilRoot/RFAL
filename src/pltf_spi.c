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

/*! \file pltf_spi.c
 *
 *  \author Shikha Singh 
 *
 *  \brief Implementation for SPI communication.
 *
 */

/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include <stdint.h>
#include "pltf_spi.h"
#include "rfal_platform.h"


/*
 ******************************************************************************
 * DEFINES
 ******************************************************************************
 */
#if defined(ST25R95)
#define SPI_MODE_CONFIG      SPI_MODE_0
#define SPI_MAX_FREQ         1500000
#else
#define SPI_MODE_CONFIG      SPI_MODE_1
#define SPI_MAX_FREQ         6000000    /* for VDD_IO = 3.3V */
#endif
#define SPI_BITS_PER_WORD    8

extern SpiInterface_t spiInterface;

/*
 ******************************************************************************
 * STATIC VARIABLES
 ******************************************************************************
 */
stError spi_init(void)
{
  return ERR_NONE;
}


HAL_statusTypeDef spiTxRx(const uint8_t *txData, uint8_t *rxData, uint8_t length)
{
    int ret = spiInterface.txRxFunc(txData, rxData, length);
    if (ret == 0) {
      return HAL_OK;
    }
    return HAL_ERROR;
}

void pltf_protect_com(void)
{
}

void pltf_unprotect_com(void)
{
}

