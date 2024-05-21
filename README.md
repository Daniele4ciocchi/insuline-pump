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


## VERSIONE PIU' DETTAGLIATA
La descrizione fornita nella nuova traccia del progetto include dettagli aggiuntivi su come modellare e simulare i componenti della pompa per insulina utilizzando equazioni differenziali ordinarie (ODE) trasformate in sistemi discreti. A differenza del primo approccio più generale, questo outline fornisce specifiche più precise su come implementare ogni componente e dettaglia requisiti sia funzionali che non-funzionali. Di seguito viene presentata una nuova versione del piano del progetto in base alle specifiche indicate.
1. Modello del Sistema

Il sistema si compone dei seguenti elementi:

    Modello dell'ambiente.
    Modello del paziente.
    Modello della pompa.
    Monitor per i requisiti.

2. Simulazione di Modelli Definiti Tramite Equazioni Differenziali Ordinarie (ODE)

Per simulare il sistema in continuo, utilizzeremo la trasformazione delle ODE in un Sistema a Tempo Discreto (DTS) tramite integrazione numerica. La discretizzazione permette di approssimare la soluzione delle ODE utilizzando metodi come l'approssimazione di Eulero.
3. Modello dell'Ambiente

L'ambiente definisce l'assunzione di cibo del paziente:

    Input: Nessuno.
    Output: Variabile booleana che vale 1 quando il paziente assume zucchero e 0 altrimenti.

Esempio di Schema Alimentare

    Durata del pasto L=60 minuti.
    Periodo di digiuno F=480 minuti (8 ore).
    Funzione di assunzione del cibo:
    δ(t)=square(0,L,F,t)
    Dove:
    square(a,b,c,t)={ 1 se t mod  (a+b+c)∈[a,a+b)
                    { 0 altrimenti
    
4. Modello del Paziente

Il modello del paziente utilizza il modello del simulatore di diabete tipo 2 di Padova come base.

    Input: Dose di insulina dalla pompa, assunzione di cibo dall'ambiente.
    Output: Concentrazione di glucosio nel sangue.

Modifica del Modello

    Concentrazione di insulina nel plasma:
    I(t)=(Ip(t)+u(t))/V⋅I
    Massa di insulina nel plasma:
    Ip(t)=LHS+u(t)

5. Modello della Pompa

Il modello della pompa utilizza una strategia di controllo per regolare la dose di insulina basata sui livelli di glucosio nel sangue.

    Input: Concentrazione di glucosio G(t).
    Output: Dose di insulina u(t).

Strategia di Controllo

Utilizzeremo una strategia PID o una strategia basata su regole definite nel libro o presentate durante le lezioni, con un tempo di campionamento di 5 minuti.
6. Monitor

I monitor valutano se i requisiti funzionali e non-funzionali sono soddisfatti.
Requisiti Funzionali

    Sicurezza: Il glucosio non deve scendere sotto i 50 mg/dL (ipoglicemia).
    Vitalità: Il glucosio dovrebbe rimanere il più vicino possibile a 100 mg/dL.

Requisiti Non-Funzionali

    Minimizzazione dell'insulina iniettata: Valutare la quantità di insulina iniettata giornalmente.
    Massimizzazione del tempo di campionamento: Sperimentare diversi tempi di campionamento e riportare i risultati.
