/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint8_t buffer[20];
uint16_t drivingspeed = 100;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
  HAL_UART_Init(&huart1);
  __HAL_UART_DISABLE(&huart1);
  __HAL_UART_ENABLE(&huart1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin)==1){
		  Drive_Sequence();
	  }

	    HAL_UART_Transmit(&huart1, (uint8_t *)"Hello\r\n", 7, 100);
	    HAL_Delay(1000);

	    buffer[0] = 0;
	    HAL_UART_Receive(&huart1, buffer, 20, 100);
	    if(buffer[0]=='w'){HAL_UART_Transmit(&huart1, "W", 6, 100);}
	    if(buffer[0]=='s'){HAL_UART_Transmit(&huart1, "S", 6, 100);}
	    if(buffer[0]=='a'){HAL_UART_Transmit(&huart1, "A", 6, 100);}
	    if(buffer[0]=='d'){HAL_UART_Transmit(&huart1, "D", 6, 100);}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 79;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, IN4_PA4_Pin|IN3_PA5_Pin|IN2_PA6_Pin|IN1_PA7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED2_Pin|LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : BTN_Pin */
  GPIO_InitStruct.Pin = BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BTN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : IN4_PA4_Pin IN3_PA5_Pin IN2_PA6_Pin IN1_PA7_Pin */
  GPIO_InitStruct.Pin = IN4_PA4_Pin|IN3_PA5_Pin|IN2_PA6_Pin|IN1_PA7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED2_Pin LED1_Pin */
  GPIO_InitStruct.Pin = LED2_Pin|LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void Drive_Sequence(void){
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, 1);
	Set_Speed(100);
	HAL_Delay(2000);

	Go_Forward(); //1
	HAL_Delay(1000);
	Stop();
	HAL_Delay(500);

	Go_Left(); //2
	HAL_Delay(350);
	Stop();
	HAL_Delay(500);

	Go_Forward(); //3
	HAL_Delay(1000);
	Stop();
	HAL_Delay(500);

	Go_Left(); //4
	HAL_Delay(350);
	Stop();
	HAL_Delay(500);

	Go_Forward(); //5
	HAL_Delay(1000);
	Stop();
	HAL_Delay(500);

	Go_Right(); //6
	HAL_Delay(700);
	Stop();
	HAL_Delay(500);

	Go_Forward(); //7
	HAL_Delay(500);
	Stop();
	HAL_Delay(500);

	Go_Backward(); //8
	HAL_Delay(500);
	Stop();
	HAL_Delay(500);

	Go_Left(); //9
	HAL_Delay(350);
	Stop();
	HAL_Delay(500);

	Go_Forward(); //10
	HAL_Delay(500);
	Stop();
	HAL_Delay(500);

	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, 0);
}

void Set_Speed(uint16_t speed){
	drivingspeed = speed; // zmienna ustalajaca predkosc (PWM)
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, drivingspeed);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, drivingspeed);
}
void Go_Forward(void){
	Set_Speed(drivingspeed);
	HAL_GPIO_WritePin(IN1_PA7_GPIO_Port, IN1_PA7_Pin, 1); // oba kola do przodu
	HAL_GPIO_WritePin(IN2_PA6_GPIO_Port, IN2_PA6_Pin, 0);

	HAL_GPIO_WritePin(IN3_PA5_GPIO_Port, IN3_PA5_Pin, 1);
	HAL_GPIO_WritePin(IN4_PA4_GPIO_Port, IN4_PA4_Pin, 0);
}
void Go_Left(void){
	Set_Speed(drivingspeed);
	HAL_GPIO_WritePin(IN1_PA7_GPIO_Port, IN1_PA7_Pin, 1); // prawe do przodu
	HAL_GPIO_WritePin(IN2_PA6_GPIO_Port, IN2_PA6_Pin, 0);

	HAL_GPIO_WritePin(IN3_PA5_GPIO_Port, IN3_PA5_Pin, 0); // lewe do tylu
	HAL_GPIO_WritePin(IN4_PA4_GPIO_Port, IN4_PA4_Pin, 1);
}
void Go_Right(void){
	Set_Speed(drivingspeed);
	HAL_GPIO_WritePin(IN1_PA7_GPIO_Port, IN1_PA7_Pin, 0); // prawe do tylu
	HAL_GPIO_WritePin(IN2_PA6_GPIO_Port, IN2_PA6_Pin, 1);

	HAL_GPIO_WritePin(IN3_PA5_GPIO_Port, IN3_PA5_Pin, 1); // lewe do przodu
	HAL_GPIO_WritePin(IN4_PA4_GPIO_Port, IN4_PA4_Pin, 0);
}
void Go_Backward(void){
	Set_Speed(drivingspeed);
	HAL_GPIO_WritePin(IN1_PA7_GPIO_Port, IN1_PA7_Pin, 0); // oba kola do tylu
	HAL_GPIO_WritePin(IN2_PA6_GPIO_Port, IN2_PA6_Pin, 1);

	HAL_GPIO_WritePin(IN3_PA5_GPIO_Port, IN3_PA5_Pin, 0);
	HAL_GPIO_WritePin(IN4_PA4_GPIO_Port, IN4_PA4_Pin, 1);
}
void Stop(void){
	HAL_GPIO_WritePin(IN1_PA7_GPIO_Port, IN1_PA7_Pin, 0); // oba kola stop
	HAL_GPIO_WritePin(IN2_PA6_GPIO_Port, IN2_PA6_Pin, 0);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);

	HAL_GPIO_WritePin(IN3_PA5_GPIO_Port, IN3_PA5_Pin, 0);
	HAL_GPIO_WritePin(IN4_PA4_GPIO_Port, IN4_PA4_Pin, 0);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0);

	Set_Speed(0);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
