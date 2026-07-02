#ifndef ALERTA_DEBUG_HPP
#define ALERTA_DEBUG_HPP

#include "alerta_info.hpp"
#include <string>

/**
 * @brief Classe alerta_debug : public alerta_info
 * Representa alertas de depuração com contexto técnico adicional.
 * Demonstra herança multinível em C++ (alerta_debug -> alerta_info -> alerta -> formatavel).
 */
class alerta_debug : public alerta_info {
private:
    std::string contexto_tecnico_; // Atributo privado para armazenar o contexto de depuração

public:
    // Construtor: recebe origem, mensagem base e o contexto técnico.
    // Passa origem e mensagem base para a classe alerta_info.
    alerta_debug(std::string origem, std::string mensagem, std::string contexto);

    // Sobrescreve formatar() para retornar a mensagem base de alerta_info
    // adicionada do contexto técnico (exemplo: "mensagem (contexto)").
    std::string formatar() const override;
};

#endif // ALERTA_DEBUG_HPP
