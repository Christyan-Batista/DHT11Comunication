#include <avr/io.h>
#include "config.h"
#include <util/delay.h>
#include <math.h>
#include "functions.h"
#include <stdio.h>
#include "UART.h"
//******************************************************************************

//******************************************************************************
char data[40];

//******************************************************************************

int main(void)
{
    int temperatura = 0, umidade = 0;
    char teste[] = "Iniciando Comunicacao";
    char tp[] = "temperatura:";
    char um[] = "umidade:";
    char valor[5];
    char quebra[] = "\n";
    UART_config();
    UART_enviaString(teste);
    UART_enviaString(quebra);
    
    void startdht11();
    void dht11();
    void ConvertData(char *info, int*temp, int *umidity);
    configuracao();
    PORTB = 0b00000100;
    
    while(1)
    {
        
        _delay_ms(1000);
        startdht11();
        dht11();
        ConvertData(data, &temperatura, &umidade);
        _delay_ms(5000);
        
        if(umidade < 60)
        {
            PORTD = 0b00000100; //PD2
        }
        else
        {
            PORTD = 0b00000000;
        }
    }
        
}
//******************************************************************************
/*
void init_lcd2L(void);
void clear_lcd2L(void);
*/

void startdht11()
{
    _delay_ms(2000);
    DDRB = 0b11111111;
    PORTB = 0b00000000;
    _delay_ms(18);
    PORTB = 0b00000100;
    _delay_us(1);
    DDRB = 0b11111011;
    //PORTB = 0b00000100;
    return;
}

void dht11()
{
    
    int continfo = 0;
    while(PINB & (1 << 2)); // PULLUP aguardando a resposta
    
    while(!(PINB & (1 << 2))); // DHT envia um sinal nivel baixo preparando a resposta
    while(PINB & (1 << 2));    // DHT envia um sinal alto em seguida preparando a resposta
    
    
    while(1)
    {
        while(!(PINB & (1 << 2))); // while esperando o delay de 50us entre cada bit enviado
        TCCR0B = 0b00000011; // definindo o prescaler do timer
        TCNT0 = 0;
        while((PINB & (1 << 2))); // espera até que o DHT11 envie 0 novamente enquanto o timer conta
        
        if(TCNT0 <= 8)
        {
            data[continfo] = '0';
            continfo++;
        }
        else
        {
            data[continfo] = '1';
            continfo++;
        }
        if(continfo == 40)
        {
            break;
        }
        
    }
    
    
    return;
}

void ConvertData(char *info, int*temp, int *umidity)
{
    int tempint = 0, tempdecimal = 0, umidityint = 0, umiditydecimal = 0, checksum = 0;
    int datainfo = 0; // 0 - umidityint, 1 - umiditydecimal, 2 - tempint, 3 - tempdecimal, 4 - checksum
    int i = 0;
    char buffer[5];
    
    while(*info != '\0')
    {
        for(i=0;i<8;++i)
        {
            switch(*info)
            {
                case '0':
                    break;
                case '1':
                    switch(datainfo)
                    {
                        case 0:
                            umidityint += (1 << (7-i));
                            break;
                        case 1:
                            umiditydecimal += (1 << (7-i));
                            break;
                        case 2:
                            tempint += (1 << (7-i));
                            break;
                        case 3:
                            tempdecimal += (1 << (7-i));
                            break;
                        case 4:
                            checksum += (1 << (7-i));
                            break;
                    }
                    
                    break;
            }
            ++info;
        }
        
        ++datainfo;
        
        if(datainfo == 5)
        {
            break;
        }
        
    }
    
    if((umidityint + umiditydecimal + tempint + tempdecimal) == checksum)
    {
        *temp = tempint;
        *umidity = umidityint;
    }
    
}
