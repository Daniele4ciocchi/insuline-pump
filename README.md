POSSIBILI IDEE DI SVILUPPO

Per affrontare il progetto della pompa per insulina, seguiremo una serie di passaggi sistematici che includono la modellazione del paziente virtuale, la modellazione dell'alimentazione e dell'esercizio fisico, la strategia di controllo della pompa e la definizione dei monitor per le proprietà funzionali e non-funzionali. Di seguito è riportato un piano dettagliato per ciascun componente richiesto.
1. Modello del Paziente Virtuale

Il modello del paziente virtuale sarà basato su un modello glicemico-insulina che lega i livelli di glucosio nel sangue all'insulina iniettata, all'esercizio fisico e all'alimentazione. Un modello comunemente usato in letteratura è il modello di Bergman, noto anche come "Minimal Model" di Bergman.

    Equazioni del Modello di Bergman:
    dG(t)/dt=−k1⋅G(t)−X(t)⋅G(t)+D(t)
    dX(t)/dt=−k2⋅X(t)+k3⋅(I(t)−Ib)
    Dove:
        G(t) è il livello di glucosio nel sangue.
        X(t) è l'attività dell'insulina.
        I(t) è la concentrazione di insulina.
        D(t) è l'apporto di glucosio dalla dieta.
        IbI è la concentrazione basale di insulina.
        k1,k2,k3 sono parametri del modello.

2. Modello per l'Alimentazione

Il modello dell'alimentazione descrive come e quando il paziente assume i pasti, influenzando l'apporto di glucosio nel sangue.

    Approccio:
    Utilizzeremo una funzione D(t) per rappresentare l'apporto di glucosio nel sangue dovuto all'alimentazione. Questa funzione può essere modellata come un impulso o una serie di impulsi nel tempo, ciascuno rappresentante un pasto:
    D(t)=∑(i=1)(N) di⋅δ(t−ti)
    Dove:
        di​ è la quantità di glucosio apportata dal pasto i.
        ti​ è il tempo del pasto i.
        δ(t) è la funzione delta di Dirac, che rappresenta un impulso al tempo t.

3. Modello per l'Esercizio Fisico

Il modello dell'esercizio fisico descrive l'impatto dell'attività fisica sui livelli di glucosio e insulina nel sangue.

    Approccio:
    L'esercizio fisico aumenta l'utilizzo del glucosio e può essere modellato come una funzione che riduce il livello di glucosio nel sangue:
    E(t)=−∑(j=1)(M) ej⋅δ(t−tj)
    Dove:
        ej​ è l'intensità dell'esercizio al tempo tj.
        tj è il tempo dell'esercizio J.

4. Modello per la Strategia di Controllo della Pompa dell'Insulina

La strategia di controllo della pompa dell'insulina determina quanto insulina iniettare in risposta ai livelli di glucosio nel sangue.

    Approccio PID (Proporzionale-Integrale-Derivativo):
    I(t)=Kp⋅e(t)+Ki⋅∫(0)(t) e(τ)dτ +Kd⋅de(t)/dt
    Dove:
        e(t)=G(t)−Gtarget​ è l'errore tra il livello di glucosio attuale e il livello target.
        Kp,Ki,Kd sono i guadagni proporzionali, integrali e derivativi rispettivamente.

5. Monitor per Proprietà Funzionali

I monitor per le proprietà funzionali verificheranno il corretto funzionamento della pompa in termini di regolazione dei livelli di glucosio.

    Proprietà Funzionali:
        Mantenimento del Livello di Glucosio: Monitorare che il livello di glucosio rimanga entro un intervallo target (ad es., 70-130 mg/dL).
        Risposta ai Pasti: Verificare che la pompa aumenti l'iniezione di insulina in risposta all'apporto di glucosio dai pasti.
        Risposta all'Esercizio: Verificare che la pompa riduca l'iniezione di insulina durante e dopo l'esercizio fisico per evitare l'ipoglicemia.

6. Monitor per Proprietà Non-Funzionali

I monitor per le proprietà non-funzionali verificheranno altri aspetti del sistema come la stabilità e la reattività.

    Proprietà Non-Funzionali:
        Stabilità del Sistema: Assicurare che il sistema non mostri oscillazioni significative e che converga a un livello di glucosio stabile.
        Reattività della Pompa: Misurare il tempo di risposta della pompa ai cambiamenti nei livelli di glucosio.
