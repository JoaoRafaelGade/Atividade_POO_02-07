cmake_minimum_required(VERSION 3.12)
project(central_alertas CXX)

# Exigido pela especificação (compilar com C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configuração de flags de compilação
# "Compila sem warnings com -Wall -Wextra -std=c++17"
# "Nenhum erro reportado por -fsanitize=address,undefined"
if(NOT MSVC)
    add_compile_options(-Wall -Wextra -fsanitize=address,undefined)
    add_link_options(-fsanitize=address,undefined)
else()
    # Para compilador Visual Studio, habilita nível de warning 4
    add_compile_options(/W4)
endif()

# Lista de arquivos fonte do projeto
set(SOURCES
    alerta.cpp
    central.cpp
    alertas/alerta_critico.cpp
    alertas/alerta_aviso.cpp
    alertas/alerta_info.cpp
    alertas/alerta_debug.cpp
    main.cpp
)

# Criação do executável do projeto
add_executable(central_alertas ${SOURCES})
