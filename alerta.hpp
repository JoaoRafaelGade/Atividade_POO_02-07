#ifndef ALERTA_HPP
#define ALERTA_HPP

#include <string>
#include <iostream>
#include <memory>

/**
 * @brief Interface pura formatavel.
 * Define apenas o contrato para formatação, sem estado (sem atributos) e sem implementação.
 */
class formatavel {
public:
    // Destrutor virtual padrão. Essencial para garantir a destruição correta de subclasses.
    virtual ~formatavel() = default;

    // Método virtual puro: obriga as subclasses a implementarem a formatação da mensagem.
    virtual std::string formatar() const = 0;
};

/**
 * @brief Classe abstrata alerta (herda de formatavel).
 * Contém estado (atributos comuns) e implementa o padrão de projeto Template Method.
 */
class alerta : public formatavel {
private:
    std::string origem_; // Identificador da fonte do alerta (ex: "sensor1")
    int severidade_;     // Nível de severidade do alerta: 1 = info, 2 = aviso, 3 = crítico

public:
    // Construtor que inicializa a origem e severidade (valida se severidade está em [1, 3])
    alerta(std::string origem, int sev);

    // Destrutor virtual padrão.
    virtual ~alerta() = default;

    // Template Method: Define o esqueleto do algoritmo de exibição.
    // É NÃO-VIRTUAL, pois o fluxo de execução não deve ser alterado pelas subclasses.
    // O comportamento varia chamando os métodos virtuais puros tipo() e formatar().
    void exibir() const;

    // Método virtual puro que retorna o tipo do alerta como string ("CRITICO", "AVISO", "INFO").
    virtual std::string tipo() const = 0;

    // Método virtual puro (herdado de formatavel) que retorna a mensagem formatada.
    virtual std::string formatar() const override = 0;

    // Getters constantes
    std::string origem() const { return origem_; }
    int severidade() const { return severidade_; }
};

// Inclusão dos outros cabeçalhos para que o main.cpp precise incluir apenas "alerta.hpp"
#include "central.hpp"
#include "alertas/alerta_critico.hpp"
#include "alertas/alerta_aviso.hpp"
#include "alertas/alerta_info.hpp"
#include "alertas/alerta_debug.hpp"

#endif // ALERTA_HPP
