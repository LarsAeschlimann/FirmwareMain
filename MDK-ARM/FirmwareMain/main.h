/**
  ******************************************************************************
  * File Name          : main.hpp
  * Description        : This file contains the common defines of the application
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

extern volatile unsigned int timecount;
extern volatile unsigned int cnt;
extern volatile char flag;
extern volatile char buttonstring[];
extern volatile unsigned int i;
extern volatile char sendflag;

#define NUMBEROFSTRINGS 20
#define STRINGLENGTH 4


#define R_red				100
#define G_red				0
#define B_red				0

#define R_orange		100
#define G_orange		1
#define B_orange		0

#define R_yellow		90
#define G_yellow		10
#define B_yellow		0

#define R_green			0
#define G_green			100
#define B_green			0

#define R_blue			0
#define G_blue			0
#define B_blue			50

#define R_aquamarin 30
#define G_aquamarin	80
#define B_aquamarin	100

#define R_magenta 	100
#define G_magenta 	100
#define B_magenta		100

#define R_violett		100
#define G_violett		0
#define B_violett		10

#define LED_CLEAR_set					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
#define LED_CLEAR_reset				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
#define LED_CLK_set						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
#define LED_CLK_reset					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

#define LED_W_up_set					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
#define LED_W_middle_set			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
#define LED_W_down_set				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);

#define LED_W_up_reset				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
#define LED_W_middle_reset		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
#define LED_W_down_reset			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);

#define LED_R_red_set 				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
#define LED_R_orange_set 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
#define LED_R_yellow_set 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
#define LED_R_green_set 			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
#define LED_R_blue_set		  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
#define LED_R_aquamarin_set 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
#define LED_R_magenta_set 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET);
#define LED_R_violett_set 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);

#define LED_R_red_reset 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
#define LED_R_orange_reset 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
#define LED_R_yellow_reset 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
#define LED_R_green_reset 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
#define LED_R_blue_reset		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
#define LED_R_aquamarin_reset HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
#define LED_R_magenta_reset 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET);
#define LED_R_violett_reset 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);

#define LED_G_red_set 				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
#define LED_G_orange_set 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
#define LED_G_yellow_set 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
#define LED_G_green_set 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
#define LED_G_blue_set		  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
#define LED_G_aquamarin_set 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
#define LED_G_magenta_set 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
#define LED_G_violett_set 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
            
#define LED_G_red_reset 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
#define LED_G_orange_reset 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
#define LED_G_yellow_reset 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
#define LED_G_green_reset 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
#define LED_G_blue_reset		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
#define LED_G_aquamarin_reset HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
#define LED_G_magenta_reset 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
#define LED_G_violett_reset 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);

#define LED_B_red_set 				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
#define LED_B_orange_set 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
#define LED_B_yellow_set 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
#define LED_B_green_set 			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
#define LED_B_blue_set		  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
#define LED_B_aquamarin_set 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
#define LED_B_magenta_set 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);
#define LED_B_violett_set 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);
            
#define LED_B_red_reset 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
#define LED_B_orange_reset 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
#define LED_B_yellow_reset 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
#define LED_B_green_reset 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
#define LED_B_blue_reset		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
#define LED_B_aquamarin_reset HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
#define LED_B_magenta_reset 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
#define LED_B_violett_reset 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);

#define SHIFT_CLK_set 				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
#define SHIFT_CLK_reset 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

#define SHIFT_DATA 						HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);

#define SHIFT_ENABLE 					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#define SHIFT_DISABLE 				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

#define BUTTON_LEFT       	3
#define BUTTON_RIGHT				0
#define BUTTON_UP						2
#define BUTTON_DOWN					1
#define BUTTON_UNDO					22
#define BUTTON_REDO					21
#define BUTTON_FULL					23
#define BUTTON_COLOR_BW			16
#define BUTTON_SEL_HUE			17
#define BUTTON_SEL_SAT			18
#define BUTTON_SEL_LUM			19
#define BUTTON_STAR_1				44
#define BUTTON_STAR_2				45
#define BUTTON_STAR_3				46
#define BUTTON_STAR_4				47
#define BUTTON_STAR_5				12
#define BUTTON_COPY					43
#define BUTTON_PASTE				42
#define BUTTON_FN						11
#define BUTTON_PICK					41
#define BUTTON_ZOOM					40
#define BUTTON_BEFOREAFTER	35
#define BUTTON_DEVELOP			36

#define BUTTON_RED				15
#define BUTTON_ORANGE			8
#define BUTTON_YELLOW			27
#define BUTTON_GREEN			26
#define BUTTON_AQUA				25
#define BUTTON_BLUE				30
#define BUTTON_PURPLE			29
#define BUTTON_MAGENTA		28
#define BUTTON_CONTRAST		14
#define BUTTON_SHADOW			9
#define BUTTON_BLACK			34
#define BUTTON_WHITE			37
#define BUTTON_CLARITY		24
#define BUTTON_DYNAMIC		31
#define BUTTON_PROG				7
#define BUTTON_ENCSAT			6
#define BUTTON_EXPOSURE		13
#define BUTTON_LIGHTS			10
#define BUTTON_CROP				20


/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
