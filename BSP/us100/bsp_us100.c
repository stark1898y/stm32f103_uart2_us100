#include "bsp_us100.h"
#include "bsp_uart.h"

// uint16_t us100_current_mm;

void BSP_US100_Init(void)
{
    #if (US100_USED_UART_MODE == 1)
    //
    #elif
    //
    #endif
}

void BSP_US100_Start(void)
{
#if (US100_USED_UART_MODE == 1)
    uint8_t us100_start_sign = 0x55;
    HAL_UART_Transmit(&US100_UART, &us100_start_sign, 1, 100);
#elif
//
#endif
}

// void BSP_US100_GetData(void)
// {

// }


uint16_t BSP_US100_Read(void)
{
    uint16_t us100_current_mm = 0;

    BSP_US100_Start();
    memset(uart2_rx_buffer, 0, 10);

    HAL_Delay(1000);
    // printf("uart2_rx_cnt = %d\r\n"
    //     , uart2_rx_cnt);
    // printf("uart2_rx_buffer = 0x%X 0x%X\r\n"
    //     , uart2_rx_buffer[0], uart2_rx_buffer[1]);
    if (uart2_rx_flag == 1)
    {
        us100_current_mm = uart2_rx_buffer[0] * 256
                    + uart2_rx_buffer[1];

        uart2_rx_flag = 0;
        memset(uart2_rx_buffer, 0, uart2_rx_cnt);
        uart2_rx_cnt = 0;
    }

    return us100_current_mm;
}


