#ifndef ALERTA_AVISO_HPP
#define ALERTA_AVISO_HPP

#include "../alerta.hpp"
#include <string>

/**
 * @brief Classe alerta_aviso : public alerta
 * Representa alertas de severidade de aviso.
 * Não é marcada como final (pode ser estendida, embora não exigido).
 */
class alerta_aviso : public alerta {
private:
    std::string mensagem_; // Mensagem específica do aviso

public:
    // Construtor: delega severidade fixa 2 (aviso) para a classe base.
    alerta_aviso(std::string origem, std::string mensagem);

    // Sobrescreve tipo() para retornar "AVISO".
    std::string tipo() const override;

    // Sobrescreve formatar() para retornar a mensagem do aviso.
    std::string formatar() const override;
};

#endif // ALERTA_AVISO_HPP
