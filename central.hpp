#ifndef CENTRAL_HPP
#define CENTRAL_HPP

#include <vector>
#include <memory>

// Forward declaration (declaração antecipada) da classe alerta.
// Isso evita dependências circulares de cabeçalho, pois a central só precisa saber
// que a classe 'alerta' existe para declarar os ponteiros inteligentes.
class alerta;

/**
 * @brief Gerencia o vetor de alertas usando polimorfismo dinâmico.
 */
class central {
private:
    // Vetor contendo ponteiros exclusivos (unique_ptr) para a classe base alerta.
    // Garante o gerenciamento automático de memória (Resource Acquisition Is Initialization - RAII).
    std::vector<std::unique_ptr<alerta>> alertas_;

public:
    // Registra um alerta. Recebe por valor para forçar a transferência de propriedade
    // do unique_ptr usando std::move no código de chamada.
    void registrar(std::unique_ptr<alerta> a);

    // Itera pelo vetor de alertas e chama exibir() para cada um deles.
    void exibir_todos() const;

    // Retorna a quantidade de alertas cadastrados (garante que não lança exceções: noexcept).
    int total() const noexcept;
};

#endif // CENTRAL_HPP
