# Atividade POO 02/07

Este repositório contém a implementação de um sistema de alertas em C++ usando herança, polimorfismo e gerenciamento automático de memória.

## Objetivo

Documentar e executar a atividade de Programação Orientada a Objetos com um projeto organizado em C++.

## Estrutura do código

- `main.cpp`: ponto de entrada do programa.
- `alerta.hpp` / `alerta.cpp`: define a hierarquia base de alertas e o método Template Method `exibir()`.
- `central.hpp` / `central.cpp`: implementa a classe `central`, que gerencia múltiplos alertas via `std::unique_ptr<alerta>`.
- `alertas/alerta_critico.hpp`, `alerta_aviso.hpp`, `alerta_info.hpp`, `alerta_debug.hpp`: classes concretas de alertas com comportamentos específicos.

## Classes principais

### `formatavel`
- Interface abstrata que define o contrato `formatar()`.
- Usada como base para garantir que todas as classes de alerta possam formatar sua mensagem.

### `alerta`
- Classe abstrata que herda de `formatavel`.
- Possui atributos comuns: `origem` e `severidade`.
- Define o método não virtual `exibir()`, que implementa o padrão Template Method.
- Delega a parte variável para os métodos virtuais puros `tipo()` e `formatar()`.

### `alerta_critico`, `alerta_aviso`, `alerta_info`
- Subclasses concretas de `alerta`.
- Cada classe define um tipo específico de alerta (`CRITICO`, `AVISO`, `INFO`).
- A classe `alerta_info` armazena uma mensagem e a formata para exibição.

### `alerta_debug`
- Herda de `alerta_info`.
- Adiciona um contexto técnico adicional à mensagem de depuração.
- Demonstra herança multinível e especialização de comportamento.

### `central`
- Armazena alertas em um vetor de `std::unique_ptr<alerta>`.
- Fornece `registrar()` para adicionar novos alertas.
- Fornece `exibir_todos()` para iterar e exibir todos os alertas via despacho polimórfico.
- Fornece `total()` para recuperar o número de alertas registrados.

## Fluxo de execução

1. `main.cpp` cria uma instância de `central`.
2. Registra alertas específicos usando `std::make_unique<...>()`.
3. Chama `central::total()` para mostrar quantos alertas foram adicionados.
4. Chama `central::exibir_todos()` para exibir cada alerta.
5. Cada `alerta` usa `exibir()`, que chama `tipo()` e `formatar()` de forma polimórfica.

## Compilação e execução

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
./central_alertas
```

## Observações

- O projeto usa C++17.
- O gerenciamento de memória é feito com `std::unique_ptr`.
- O padrão Template Method garante que o fluxo de exibição seja comum a todos os tipos de alerta.
