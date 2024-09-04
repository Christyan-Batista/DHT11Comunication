# DHT11Communication
Programa em C para microcontrolador AVR ATMEGA328P que visa estabelecer a comunicação com o sensor de temperatura e umidade DHT11

# DHT11
O DHT11 é um sensor amplamente utilizado para medir temperatura e umidade relativa do ar. Ele é conhecido por sua simplicidade de uso, baixo custo e ampla aplicação em projetos de eletrônica e automação.

Características:
  * Temperatura: Mede na faixa de 0°C a 50°C, com precisão de ±2°C.
  * Umidade: Mede umidade relativa do ar entre 20% e 90%, com precisão de ±5%.
  * Saída Digital: O DHT11 fornece dados em formato digital, facilitando sua interface com microcontroladores como Arduino e Raspberry Pi.
  * Intervalo de Leitura: O sensor pode realizar leituras a cada 2 segundos, ideal para monitoramento constante.

Esquema de Conexão:
![image](https://github.com/user-attachments/assets/20939cbd-b81e-4bf8-9c2f-dbe53c582178)

O sensor DHT11 utiliza um formato de comunicação de barramento único para se comunicar e se sincronizar com o microcontrolador (MCU). Cada processo de comunicação dura cerca de 4 milissegundos.

Os dados transmitidos são compostos por partes inteiras e decimais, totalizando 40 bits. Durante a transmissão, o sensor envia primeiro os bits mais significativos.

A estrutura dos dados é a seguinte:

8 bits para a parte inteira da umidade relativa (RH).
8 bits para a parte decimal da umidade relativa (RH).
8 bits para a parte inteira da temperatura (T).
8 bits para a parte decimal da temperatura (T).
8 bits de soma de verificação (check sum).

A soma de verificação serve para garantir que a transmissão foi bem-sucedida. Ela é calculada somando os 8 bits da umidade relativa (parte inteira e decimal) com os 8 bits da temperatura (parte inteira e decimal). Se a transmissão estiver correta, o valor da soma de verificação deve corresponder aos últimos 8 bits enviados.

Quando o MCU envia um sinal de início, o DHT11 muda do modo de baixo consumo de energia para o modo de operação, aguardando o MCU concluir o envio do sinal de início. Assim que esse sinal é concluído, o DHT11 envia um sinal de resposta contendo 40 bits de dados, que incluem informações sobre a umidade relativa e a temperatura.

![image](https://github.com/user-attachments/assets/d9e6697f-541a-422e-b5ac-d43e1612f787)

As demais informações sobre a comunicação com o DHT11 pode ser encontrada em seu datasheet: https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf

# Lógica do programa elaborado.
