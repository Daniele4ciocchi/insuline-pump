//
// Created by daniele on 21/05/24.
//

#include "Paziente.h"

// Implementazione del costruttore
Paziente::Paziente(double glucosioIniziale, double insulinaIniziale) {
    glucosio = glucosioIniziale;
    insulina = insulinaIniziale;
}

// Implementazione dei metodi getter
double Paziente::getGlucosio() const {
    return glucosio;
}

double Paziente::getInsulina() const {
    return insulina;
}

// Implementazione dei metodi per simulare l'assunzione di cibo e l'iniezione di insulina
void Paziente::assumeCibo(double quantita) {
    // implementazione...
}

void Paziente::iniettaInsulina(double dose) {
    // implementazione...
}

// Implementazione del metodo per aggiornare lo stato del paziente
void Paziente::aggiornaStato() {
    // implementazione...
}