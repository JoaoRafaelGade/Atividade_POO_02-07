#ifndef ALERTA_INFO_HPP
#define ALERTA_INFO_HPP

#include "../alerta.hpp"
#include <string>

/**
 * @brief Classe alerta_info : public alerta
 * Representa alertas de severidade informativa.
 * NÃO é marcada como final para permitir a especialização (como solicitado no desafio).
 */
class alerta_info : public alerta {
private:
    std::string mensagem_; // Mensagem específica do alerta de informação

public:
    // Construtor: delega severidade fixa 1 (info) para a classe base.
    alerta_info(std::string origem, std::string mensagem);

    // Sobrescreve tipo() para retornar "INFO".
    std::string tipo() const override;

    // Sobrescreve formatar() para retornar a mensagem do alerta.
    std::string formatar() const override;
};

#endif // ALERTA_INFO_HPP
