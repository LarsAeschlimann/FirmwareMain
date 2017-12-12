/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim6;

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
char buffertx[50];
char bufferrx[8];

volatile char  buttonstring[48];
char encoderstring[] = "Aa05XXXXXXXXXXXX";

char ringbuffer[BUFFERSIZE][STRINGLENGTH];//FIFO Ringbuffer
struct Buffer{
	char write;
	char read;
} buffer={0,0};



char stringbyte1[8];
char stringbyte2[8];
char stringbyte3[8];
char stringbyte4[8];
char singlestrings[BUFFERSIZE];

volatile unsigned int timecount;
volatile unsigned int cnt;
unsigned int testcount = 0;
volatile unsigned int i;
volatile char flag; 
volatile char sendflag = 0;

enum select sel = HUE;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_UART4_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_TIM6_Init(void);
static void MX_TIM3_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void ledpwm(void);
void ledtest(void);
void select(void);
void sendfunction(void);
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
void ledpwm(void){//evt Division entfernen --> weniger Rechenaufwand
	
	if((timecount<=R_green)&&(R_green!=0)){LED_R_green_set;}else{LED_R_green_reset;}
	if((timecount<=G_green)&&(G_green!=0)){LED_G_green_set;}else{LED_G_green_reset;}
	if((timecount<=B_green)&&(B_green!=0)){LED_B_green_set;}else{LED_B_green_reset;}
		
	if((timecount<=R_yellow)&&(R_yellow!=0)){LED_R_yellow_set;}else{LED_R_yellow_reset;}
	if((timecount<=G_yellow)&&(G_yellow!=0)){LED_G_yellow_set;}else{LED_G_yellow_reset;}
	if((timecount<=B_yellow)&&(B_yellow!=0)){LED_B_yellow_set;}else{LED_B_yellow_reset;}
	
	if((timecount<=R_violett)&&(R_violett!=0)){LED_R_violett_set;}else{LED_R_violett_reset;}
	if((timecount<=G_violett)&&(G_violett!=0)){LED_G_violett_set;}else{LED_G_violett_reset;}
	if((timecount<=B_violett)&&(B_violett!=0)){LED_B_violett_set;}else{LED_B_violett_reset;}
	
	if((timecount<=R_blue)&&(R_blue!=0)){LED_R_blue_set;}else{LED_R_blue_reset;}
	if((timecount<=G_blue)&&(G_blue!=0)){LED_G_blue_set;}else{LED_G_blue_reset;}
	if((timecount<=B_blue)&&(B_blue!=0)){LED_B_blue_set;}else{LED_B_blue_reset;}
	
	if((timecount<=R_magenta)&&(R_magenta!=0)){LED_R_magenta_set;}else{LED_R_magenta_reset;}
//	if((timecount<=G_magenta)&&(G_magenta!=0)){LED_G_magenta_set;}else{LED_G_magenta_reset;}
//	if((timecount<=B_magenta)&&(B_magenta!=0)){LED_B_magenta_set;}else{LED_B_magenta_reset;}//Fehler wenn dieser Pin HIGH ist. Interrupt funktioniert nicht mehr!
	
	if((timecount<=R_red)&&(R_red!=0)){LED_R_red_set;}else{LED_R_red_reset;}
	if((timecount<=G_red)&&(G_red!=0)){LED_G_red_set;}else{LED_G_red_reset;}
	if((timecount<=B_red)&&(B_red!=0)){LED_B_red_set;}else{LED_B_red_reset;}
	
	if((timecount<=R_aquamarin)&&(R_aquamarin!=0)){LED_R_aquamarin_set;}else{LED_R_aquamarin_reset;}
	if((timecount<=G_aquamarin)&&(G_aquamarin!=0)){LED_G_aquamarin_set;}else{LED_G_aquamarin_reset;}
	if((timecount<=B_aquamarin)&&(B_aquamarin!=0)){LED_B_aquamarin_set;}else{LED_B_aquamarin_reset;}
	
	if((timecount<=R_orange)&&(R_orange!=0)){LED_R_orange_set;}else{LED_R_orange_reset;}
	if((timecount<=G_orange)&&(G_orange!=0)){LED_G_orange_set;}else{LED_G_orange_reset;}
	if((timecount<=B_orange)&&(B_orange!=0)){LED_B_orange_set;}else{LED_B_orange_reset;}
}

void ledtest(void){
	
	testcount++;
	for(unsigned int i=0; i<400000; i++){
			LED_R_red_set; 				
			LED_R_orange_set; 		
			LED_R_yellow_set;		
			LED_R_green_set;	
			LED_R_blue_set;	  
			LED_R_aquamarin_set; 
			LED_R_magenta_set; 	
			LED_R_violett_set;
			LED_W_down_set;
	}
	
	for(unsigned int i=0; i<400000; i++){
			LED_G_red_set;				
			LED_G_orange_set; 		
			LED_G_yellow_set;		
			LED_G_green_set;	
			LED_G_blue_set;	  
			LED_G_aquamarin_set; 
			LED_G_magenta_set; 	
			LED_G_violett_set; 	
			LED_W_middle_set;
	}
	
	for(unsigned int i=0; i<400000; i++){
			LED_B_red_set; 				
			LED_B_orange_set; 		
			LED_B_yellow_set;	
			LED_B_green_set;	
			LED_B_blue_set;	  
			LED_B_aquamarin_set; 
			LED_B_magenta_set;
			LED_B_violett_set;
			LED_W_up_set;
	}
	LED_CLEAR_reset;
}

void select(void){//Funktion fuer die weissen Select LEDs
	switch(sel){
		case HUE:
			if((buttonstring[BUTTON_SEL_LUM])&&(!buttonstring[BUTTON_SEL_HUE])&&(!buttonstring[BUTTON_SEL_SAT]))sel = LUM;
			if((buttonstring[BUTTON_SEL_SAT])&&(!buttonstring[BUTTON_SEL_HUE])&&(!buttonstring[BUTTON_SEL_LUM]))sel = SAT;
			LED_W_up_set;
			LED_W_middle_reset;
			LED_W_down_reset;
	//		buffertx = "Hallo";
		break;
		
		case SAT:
			if((buttonstring[BUTTON_SEL_HUE])&&(!buttonstring[BUTTON_SEL_LUM])&&(!buttonstring[BUTTON_SEL_SAT]))sel = HUE;
			if((buttonstring[BUTTON_SEL_LUM])&&(!buttonstring[BUTTON_SEL_HUE])&&(!buttonstring[BUTTON_SEL_SAT]))sel = LUM;
			LED_W_up_reset;
			LED_W_middle_set;
			LED_W_down_reset;
	//		buffertx = "duda";
		break;
		
		case LUM:
			if((buttonstring[BUTTON_SEL_HUE])&&(!buttonstring[BUTTON_SEL_LUM])&&(!buttonstring[BUTTON_SEL_SAT]))sel = HUE;
			if((buttonstring[BUTTON_SEL_SAT])&&(!buttonstring[BUTTON_SEL_HUE])&&(!buttonstring[BUTTON_SEL_LUM]))sel = SAT;
			LED_W_up_reset;
			LED_W_middle_reset;
			LED_W_down_set;
		//	buffertx = "FUCK";
		break;
	}
}

char fifoput(char* inputencode){
	
	if ((buffer.write + 1 == buffer.read)||(buffer.read == 0 && buffer.write + 1 == BUFFERSIZE))return 0;
	if(buffer.write >= BUFFERSIZE)buffer.write = 0;
	
	ringbuffer[buffer.write][0] = inputencode[0];
	ringbuffer[buffer.write][1] = inputencode[1];
	ringbuffer[buffer.write][2] = inputencode[2];
	ringbuffer[buffer.write][3] = inputencode[3];
	buffer.write++;

	return 1;
}

char fifoget(char* fifoout){//0 invalid, 1 valid
	
	if (buffer.read == buffer.write)return 0;
	
	fifoout[0] = ringbuffer[buffer.read][0];
	fifoout[1] = ringbuffer[buffer.read][1];
	fifoout[2] = ringbuffer[buffer.read][2];
	fifoout[3] = ringbuffer[buffer.read][3];
	buffer.read++;
	if(buffer.read >= BUFFERSIZE)buffer.read = 0;
	
	return 1;
}

void sendfunction(void){
	
//	fifoget();
	sendflag = 0;
		//sendstring[2][4] = "ta04";
	strcpy(stringbyte1,"Hallo");
	if(!sendflag){
		strcpy(buffertx, stringbyte1);
		HAL_UART_Transmit_IT(&huart4, (uint8_t *)buffertx, 8);
		sendflag = 1;
	}

}


/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
	
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

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
  MX_UART4_Init();
  MX_USART3_UART_Init();
  MX_TIM6_Init();
  MX_TIM3_Init();

  /* USER CODE BEGIN 2 */
	//__HAL_UART_ENABLE_IT(&huart4, UART_IT_TC);
//	__HAL_UART_ENABLE_IT(&huart4, UART_IT_RXNE);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim6);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)//===========================================WHILE========================================================
  {
		LED_CLEAR_set;
		ledpwm();
		select();
		sendfunction();
		
		
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* TIM3 init function */
static void MX_TIM3_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 23;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 49;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM6 init function */
static void MX_TIM6_Init(void)
{

  TIM_MasterConfigTypeDef sMasterConfig;

  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 23;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 49;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* UART4 init function */
static void MX_UART4_Init(void)
{

  huart4.Instance = UART4;
  huart4.Init.BaudRate = 115200;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART3 init function */
static void MX_USART3_UART_Init(void)
{

  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0 
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 PC0 
                           PC1 PC2 PC3 PC4 
                           PC5 PC6 PC7 PC8 
                           PC9 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0 
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 
                           PA4 PA5 PA7 PA8 
                           PA9 PA10 PA11 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB13 PB14 
                           PB15 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
