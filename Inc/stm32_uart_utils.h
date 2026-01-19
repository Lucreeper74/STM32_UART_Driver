#ifndef __STM32_UART_UTILS_H__
#define __STM32_UART_UTILS_H__

#include <string.h>
#include <stdlib.h>
#include <sys/_intsup.h>

#if defined(STM32F3xx)
#include <stm32f3xx_hal.h>
#elif defined(STM32L0xx)
#include <stm32l0xx_hal.h>
#endif

#endif // __STM32_UART_UTILS_H__