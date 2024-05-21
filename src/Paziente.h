//
// Created by daniele on 21/05/24.
//

#ifndef INSULINE_PUMP_PAZIENTE_H
#define INSULINE_PUMP_PAZIENTE_H


class Paziente {
private:
    double glucosio; // Concentrazione di glucosio nel sangue
    double insulina; // Dose di insulina

public:
    // Costruttore
    Paziente(double glucosioIniziale, double insulinaIniziale) : glucosio(glucosioIniziale), insulina(insulinaIniziale) {}

    // Metodi getter per ottenere i valori correnti di glucosio e insulina
    double getGlucosio() const { return glucosio; }
    double getInsulina() const { return insulina; }

    // Metodi per simulare l'assunzione di cibo e l'iniezione di insulina
    void assumeCibo(double quantita) { /* implementazione... */ }
    void iniettaInsulina(double dose) { /* implementazione... */ }

    // Metodo per aggiornare lo stato del paziente (es. calcolare il nuovo livello di glucosio)
    void aggiornaStato() { /* implementazione... */ }
};


#endif //INSULINE_PUMP_PAZIENTE_H
