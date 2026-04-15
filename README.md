# Smart Garden

## Sobre o Projeto

**Projeto:** Smart Garden

**Problema que resolve:** Automatizar a irrigação de plantas evitando desperdício de água ao considerar a umidade do solo e a previsão de chuva.

## Arquitetura
```mermaid
flowchart TD
    A[Sensor de umidade\nLeitura do solo] -->|dados de umidade| C
    B[Previsão de chuva\nAPI meteorológica] -->|probabilidade de chuva| C
    C[Módulo de IA\nAnalisa e decide] --> D{Irrigar?}
    D -->|Sim - solo seco + sem chuva| E[Irrigar agora\nAciona bomba]
    D -->|Não - solo ok ou chuva esperada| F[Aguardar\nSolo ok ou chuva a caminho]
    E --> G[Log + Notificação\nRegistra e alerta]
    F --> H[Reagendar ciclo\nPróxima verificação em Xh]
    G --> I[Dashboard / App\nHistórico e controle]
    H --> I
``` 

## Integrantes

| Nome                             | GitHub             |
| -------------------------------- | ------------------ |
| Maximus Daniel Nascimento        | [@maximusdn]       |
| Jonathan Ribeiro                 | [@JonathanRbo-puc]    |
| Gabriel Henrique Rodrigues Rocha | [@RickRocha022] |
