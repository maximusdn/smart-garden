# 🌱 Smart Garden

Sistema inteligente de irrigação que utiliza **sensor de umidade do solo + previsão de chuva** para decidir automaticamente se deve irrigar ou agendar a irrigação.

## Descrição do Projeto

O **Smart Garden** é uma solução automatizada para controle de irrigação, que evita desperdício de água e melhora o cuidado com plantas.

O sistema combina:

* Dados em tempo real do solo
* Informações climáticas (previsão de chuva)
* Lógica inteligente (IA ou regras)

Com isso, ele toma decisões como:

* Irrigar imediatamente
* Adiar a irrigação
* Não irrigar

## Lógica do Sistema

A tomada de decisão segue este fluxo:

1. O sensor mede a umidade do solo
2. O sistema verifica a previsão de chuva
3. A IA analisa os dados
4. Uma decisão é tomada

| Condição                   | Ação            |
| -------------------------- | --------------- |
| Solo seco + sem chuva      | Irrigar         |
| Solo seco + chuva prevista | Adiar irrigação |
| Solo úmido                 | Não irrigar     |

## Tecnologias Utilizadas

* Sensor de umidade do solo
* Microcontrolador (ex: Arduino)
* Simulação no Wokwi
* Integração com API de clima (opcional)
* Lógica de decisão (IA ou regras condicionais)

## Simulação

O projeto pode ser executado via simulação no Wokwi, permitindo testar o funcionamento sem hardware físico.

## Objetivo

* Automatizar a irrigação
* Economizar água
* Melhorar o cuidado com plantas
* Utilizar tecnologia para soluções sustentáveis

## Possíveis Expansões

* Aplicativo para controle remoto
* Sistema de notificações
* Integração com IoT
* Aprendizado de máquina mais avançado

## Integrantes


* **Nome: Maximus Daniel Nascimento**
  **Email: maximus.dn@puccampinas.edu.br**

* **Nome: Jonathan Ribeiro**
  **Email: jonathan.r@puccampinas.edu.br**

* **Nome: Gabriel Henrique Rodrigues Rocha**
  **Email: gabriel.hrr@puccampinas.edu.br**
