#include "../alerta.hpp"

// Construtor de alerta_aviso.
// Delega severidade fixa 2 para a classe base alerta.
alerta_aviso::alerta_aviso(std::string origem, std::string mensagem)
    : alerta(std::move(origem), 2), mensagem_(std::move(mensagem)) {}

// Retorna "AVISO".
std::string alerta_aviso::tipo() const {
    return "AVISO";
}

// Retorna a mensagem associada ao aviso.
std::string alerta_aviso::formatar() const {
    return mensagem_;
}
