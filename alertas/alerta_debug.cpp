#include "../alerta.hpp"

// Construtor de alerta_debug.
// Repassa a origem e a mensagem para a classe pai alerta_info, e inicializa o contexto_tecnico_.
alerta_debug::alerta_debug(std::string origem, std::string mensagem, std::string contexto)
    : alerta_info(std::move(origem), std::move(mensagem)), contexto_tecnico_(std::move(contexto)) {}

// Sobrescreve o método formatar().
// Obtém a mensagem formatada da classe pai alerta_info e concatena o contexto técnico entre parênteses.
std::string alerta_debug::formatar() const {
    return alerta_info::formatar() + " (" + contexto_tecnico_ + ")";
}
