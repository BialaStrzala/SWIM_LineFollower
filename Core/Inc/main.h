/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_Pin GPIO_PIN_0
#define BTN_GPIO_Port GPIOA
#define IN4_PA4_Pin GPIO_PIN_4
#define IN4_PA4_GPIO_Port GPIOA
#define IN3_PA5_Pin GPIO_PIN_5
#define IN3_PA5_GPIO_Port GPIOA
#define IN2_PA6_Pin GPIO_PIN_6
#define IN2_PA6_GPIO_Port GPIOA
#define IN1_PA7_Pin GPIO_PIN_7
#define IN1_PA7_GPIO_Port GPIOA
#define ENB_Pin GPIO_PIN_0
#define ENB_GPIO_Port GPIOB
#define ENA_Pin GPIO_PIN_7
#define ENA_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOC
#define SENSOR_FARLEFT_Pin GPIO_PIN_6
#define SENSOR_FARLEFT_GPIO_Port GPIOF
#define SENSOR_LEFT_Pin GPIO_PIN_7
#define SENSOR_LEFT_GPIO_Port GPIOF
#define SENSOR_MIDDLE_Pin GPIO_PIN_14
#define SENSOR_MIDDLE_GPIO_Port GPIOA
#define SENSOR_RIGHT_Pin GPIO_PIN_15
#define SENSOR_RIGHT_GPIO_Port GPIOA
#define SENSOR_FARRIGHT_Pin GPIO_PIN_10
#define SENSOR_FARRIGHT_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
