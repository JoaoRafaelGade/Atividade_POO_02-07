#ifndef ALERTA_CRITICO_HPP
#define ALERTA_CRITICO_HPP

#include "../alerta.hpp"
#include <string>

/**
 * @brief Classe alerta_critico final : public alerta
 * Representa alertas de severidade crítica.
 * Marcada como 'final', indicando que esta classe não pode ser herdada.
 */
class alerta_critico final : public alerta {
private:
    std::string mensagem_; // Atributo privado adicional para armazenar a mensagem específica

public:
    // Construtor: recebe a origem e a mensagem, e delega para o construtor da classe base
    // com severidade 3 (crítico).
    alerta_critico(std::string origem, std::string mensagem);

    // Sobrescreve tipo() para retornar "CRITICO".
    std::string tipo() const override;

    // Sobrescreve formatar() para retornar a mensagem do alerta crítico.
    std::string formatar() const override;
};

#endif // ALERTA_CRITICO_HPP
