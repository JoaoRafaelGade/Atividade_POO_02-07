#include "alerta.hpp"
#include <iostream>

int main() {
    // Instancia o controlador central de alertas
    central c;

    // Registra os alertas padrão do enunciado
    c.registrar(std::make_unique<alerta_critico>(
        "sensor1", "temperatura 95.3 graus"));
    
    c.registrar(std::make_unique<alerta_aviso>(
        "sensor2", "umidade 78.5 pct"));
    
    c.registrar(std::make_unique<alerta_info>(
        "sistema", "reinicio agendado"));

    // Desafio: registramos um alerta_debug que herda de alerta_info
    c.registrar(std::make_unique<alerta_debug>(
        "banco_dados", "conexao perdida", "timeout apos 30s"));

    // Exibe a quantidade total de alertas na central
    std::cout << "Total: " << c.total() << " alertas\n\n";

    // Exibe todos os alertas usando polimorfismo dinâmico
    c.exibir_todos();

    return 0;
}
