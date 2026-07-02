#include "alerta.hpp"
#include <stdexcept>

// Construtor da classe abstrata alerta.
// Inicializa a origem e a severidade. Caso a severidade esteja fora de [1, 3],
// lança uma exceção do tipo std::invalid_argument.
alerta::alerta(std::string origem, int sev)
    : origem_(std::move(origem)), severidade_(sev) {
    if (sev < 1 || sev > 3) {
        throw std::invalid_argument("Severidade inválida! Deve ser entre 1 e 3.");
    }
}

// Implementação do Template Method exibir().
// Observe que ele não é virtual, mas o seu comportamento interno delega
// para os métodos virtuais puros tipo() e formatar() definidos pelas subclasses.
void alerta::exibir() const {
    std::cout << "[" << tipo() // Chamada polimórfica para obter o tipo
              << "] " << origem_ << ": "
              << formatar() // Chamada polimórfica para obter a mensagem formatada
              << "\n";
}
