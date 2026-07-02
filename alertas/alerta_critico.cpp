#include "../alerta.hpp"

// Construtor da classe alerta_critico.
// Delega a inicialização de origem_ e a severidade fixa 3 (crítico) para a classe base alerta.
alerta_critico::alerta_critico(std::string origem, std::string mensagem)
    : alerta(std::move(origem), 3), mensagem_(std::move(mensagem)) {}

// Sobrescreve o método tipo() indicando o tipo de alerta.
std::string alerta_critico::tipo() const {
    return "CRITICO";
}

// Sobrescreve o método formatar() retornando o atributo mensagem_.
std::string alerta_critico::formatar() const {
    return mensagem_;
}
