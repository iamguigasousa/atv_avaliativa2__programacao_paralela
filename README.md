
# Atividade de Programação Paralela

Este repositório contém implementações em C que abordam conceitos essenciais de programação paralela: **Leitores e Escritores**, **Barreiras**, **Sinais** e **Deadlocks**, utilizando a biblioteca `pthread`. Esta atividade faz parte de um estudo sobre sincronização e coordenação de threads em ambientes multi-threaded.

## Autores

- **Guilherme Domingues de Sousa** - RA: 22013871
- **Felipe Sousa de Almeida** - RA: 22018160

## Objetivos

- Compreender e aplicar conceitos de programação paralela.
- Implementar soluções para controle de acesso a recursos compartilhados.
- Demonstrar o uso de técnicas de sincronização usando `pthread`.

## Conceitos Abordados

1. **Leitores e Escritores**: Controle de acesso para múltiplas threads leitoras e escritoras, garantindo que leitores possam acessar simultaneamente, enquanto escritores têm acesso exclusivo.
2. **Barreiras**: Sincronização de threads em um ponto específico da execução, permitindo que todas as threads esperem umas pelas outras em um ponto de barreira.
3. **Sinais**: Comunicação e notificação entre threads usando variáveis de condição para sinalizar quando um dado está disponível.
4. **Deadlocks**: Exemplo de uma situação de deadlock, demonstrando como impasses podem ocorrer quando duas ou mais threads bloqueiam recursos mutuamente.

## Estrutura do Projeto

O projeto está organizado em arquivos separados, cada um correspondendo a um dos conceitos:

- **Código Principal**:
  - `main.c`: Arquivo principal que permite escolher qual exemplo executar.

- **Implementações dos Conceitos**:
  - `leitores_escritores.c` e `leitores_escritores.h`: Código e cabeçalho para o problema dos Leitores e Escritores.
  - `barreiras.c` e `barreiras.h`: Código e cabeçalho para a implementação de Barreiras.
  - `sinais.c` e `sinais.h`: Código e cabeçalho para o exemplo de Sinais.
  - `deadlock.c` e `deadlock.h`: Código e cabeçalho para o exemplo de Deadlock.

## Compilação e Execução

Para compilar e executar o projeto, siga as instruções abaixo:

1. Clone o repositório:
   ```bash
   git clone https://github.com/seuprojeto/atividade_avaliativa_2.git
   ```
   
2. Navegue até o diretório do projeto:
   ```bash
   cd atividade_avaliativa_2
   ```

3. Compile o projeto usando CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Execute o programa:
   ```bash
   ./atividade_avaliativa_2
   ```

O programa solicitará que você escolha qual exemplo deseja executar.

