#include "../alerta.hpp"

// Construtor de alerta_info.
// Delega a severidade fixa 1 para a classe base alerta.
alerta_info::alerta_info(std::string origem, std::string mensagem)
    : alerta(std::move(origem), 1), mensagem_(std::move(mensagem)) {}

// Retorna "INFO".
std::string alerta_info::tipo() const {
    return "INFO";
}

// Retorna a mensagem associada à informação.
std::string alerta_info::formatar() const {
    return mensagem_;
}
