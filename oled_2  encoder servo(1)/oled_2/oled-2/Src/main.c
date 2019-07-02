
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* INC*/
#include "ssd1306.h"
#include "i2c-lcd.h"
#include "string.h"
#include "main.h"
#define RX_BUFFER_SIZE 4
/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart3;



/*DEGISKENLER*/
uint8_t encoderCount=0;
uint8_t encoderDirection=0;
char strBuffer[32];
char strBuffer1[32];
uint8_t check;
int katla;
const char *msg = "\n LED'in durumunu belirle (\"led1\" veya \"led0\"):\n";
char rxBuffer[RX_BUFFER_SIZE];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

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
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
	char USARTBUFFER[16];
	int intValue = 1925;
	double realValue = -1912.5553;
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
	
	lcd_init ();
	check = SSD1306_Init ();
	SSD1306_Fill (0);
	SSD1306_UpdateScreen(); //display
sprintf(strBuffer, "%d\n", intValue);
	HAL_UART_Transmit(&huart3, (uint8_t *)USARTBUFFER, strlen(USARTBUFFER), 1);
	
	sprintf(strBuffer, "0x%X\n", intValue);
	HAL_UART_Transmit(&huart3, (uint8_t *)USARTBUFFER, strlen(USARTBUFFER), 1);
	
	sprintf(strBuffer, "%.2f\n", realValue);
	HAL_UART_Transmit(&huart3, (uint8_t *)USARTBUFFER, strlen(USARTBUFFER), 1);

  while (1)
  {

		
if (encoderCount<5){	
	SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,15,65,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=8250; }
if (encoderCount>5&&encoderCount<10){
	SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,15,57,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=8000;}
if (encoderCount>10&&encoderCount<15){
		SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,15,53,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=7750;}
if (encoderCount>15&&encoderCount<20){
	SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,15,47,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=7500;}
if (encoderCount>20&&encoderCount<25){
		SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,20,40,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=7250;}
if (encoderCount>25&&encoderCount<30){
		SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,23,32,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=7000;}
if (encoderCount>35&&encoderCount<40){
			SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,35,25,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=6750;}
if (encoderCount>40&&encoderCount<45){
			SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,43,18,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=6500;}
if (encoderCount>45&&encoderCount<50){
			SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,50,11,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=6250;}
if (encoderCount>50&&encoderCount<55){
			SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,55,8,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=6000;}
if (encoderCount>55&&encoderCount<60){
				SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,55,2,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=5750;}
if (encoderCount>60&&encoderCount<65){
					SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,60,2,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=5500;}
if (encoderCount>65&&encoderCount<70){
					SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,62,2,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=5250;}
if (encoderCount>70&&encoderCount<75){
	SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,64,2,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=5000;}
if (encoderCount>75&&encoderCount<80){
		SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,69,6,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=4750;}
if (encoderCount>80&&encoderCount<85){
		SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,75,6,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=4500;}
if (encoderCount>85&&encoderCount<90){
			SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,83,8,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=4250;}
if (encoderCount>90&&encoderCount<95){
				SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,90,16,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=4000;}
if (encoderCount>95&&encoderCount<100){
					SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,95,19,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=3750;}
if (encoderCount>100&&encoderCount<105){
					SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,100,22,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=3500;}
if (encoderCount>105&&encoderCount<110){
					SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,104,30,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=3250;}
if (encoderCount>110&&encoderCount<115){
					SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,110,38,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=3000;}
if (encoderCount>115&&encoderCount<120){
						SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,113,44,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=2750;}
if (encoderCount>120&&encoderCount<125){
						SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,115,47,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=2500;}
if (encoderCount>125&&encoderCount<130){
						SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,115,55,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=2250;}
if (encoderCount>135&&encoderCount<140){
							SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,120,59,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=2000;}
if (encoderCount>140&&encoderCount<145){
							SSD1306_Fill (0);
	SSD1306_DrawCircle(65,63,53,1);
	SSD1306_DrawLine(67,90,118,64,1);
	SSD1306_GotoXY (1,0);
	SSD1306_Puts (strBuffer, &Font_7x10, 1);


	SSD1306_UpdateScreen();
katla=1750;	}		
	
	

																							

encoderCount = __HAL_TIM_GET_COUNTER(&htim1);
		encoderDirection = __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim1);
sprintf(strBuffer, "Encoder Durum=%d", encoderCount);
		sprintf(strBuffer1, "katla=%d",katla);


		
		
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, katla);

		encoderCount = __HAL_TIM_GET_COUNTER(&htim1);
		encoderDirection = __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim1);


  }
		
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enables the Clock Security System 
  */
  HAL_RCC_EnableCSS();
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 5000;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
	
  if (HAL_TIM_Encoder_Init(&htim1, &sConfig) != HAL_OK)
		
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 22-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_ENABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
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
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, step_Pin|dir_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : led1_Pin */
  GPIO_InitStruct.Pin = led1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(led1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : step_Pin dir_Pin */
  GPIO_InitStruct.Pin = step_Pin|dir_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
