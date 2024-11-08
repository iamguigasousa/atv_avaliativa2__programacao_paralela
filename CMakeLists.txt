cmake_minimum_required(VERSION 3.29)
project(atividade_avaliativa_2 C)

set(CMAKE_C_STANDARD 11)

# Inclua os arquivos .c adicionais para compilar todos os conceitos
add_executable(atividade_avaliativa_2 main.c leitores_escritores.c barreiras.c sinais.c deadlock.c
        leitores_escritores.c)
