#include "central.hpp"
#include "alerta.hpp" // Necessário aqui para podermos interagir com os métodos da classe alerta

// Registra o alerta na central. Recebe o unique_ptr por valor e faz o move para o vetor.
void central::registrar(std::unique_ptr<alerta> a) {
    alertas_.push_back(std::move(a));
}

// Itera e exibe todos os alertas usando referências constantes para evitar cópia.
// A chamada a->exibir() fará o despacho dinâmico para os métodos virtuais das subclasses.
void central::exibir_todos() const {
    for (const auto& a : alertas_) {
        a->exibir();
    }
}

// Retorna o tamanho do vetor de alertas convertido para int.
int central::total() const noexcept {
    return static_cast<int>(alertas_.size());
}
