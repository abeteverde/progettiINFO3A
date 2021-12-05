%progettino INFO 3A: ASM
%Michele Dentella (1063244)
%nov 2021

\pagebreak

# 1. Introduzione

Questo progetto implementa una macchina a stati astratta che simula gli stati di funzionamento di un generico lettore eBook.
Il lettore è dotato di retroilluminazione.

# 2. funzionamento

Il dispositivo è inizialmente spento con luminosità del pannello impostata a 0.

Gli stati sono:

- OFF
- MENU
- LETTURA
- IMPOSTAZIONI

Una volta acceso si passa allo stato di visualizzazione del menu (quello con i diversi libri caricati).
Da qui è possibile scegliere un libro da leggere (si passa quindi allo stato di lettura) oppure si può accedere alle impostazioni.
In lettura è disponibile il comando aggiornapagina (è presente per simulare le funzioni avanti/indietro/aggiorna).

Da tutti gli stati è possibile spegnere il dispositivo (stato OFF e luminosità a 0).  
Anche la luminosità è modificabile da tutti gli stati, da un minimo di 0 ad un massimo di 5.
I valori sono limitati in modo da non bloccare la macchina a stati.

# 3. Avalla

Sono presenti due scenari Avalla, uno con un utilizzo generico, l'altro che testa i limiti della luminosità.

\pagebreak

# 4. struttura

### 4.1 corpo centrale ASM:

![struttura ASM](/home/michele/progettiINFO3A/ASM/ASM.jpg)


### 4.2 stati per i valori di luminosità:

![luminosità ASM](/home/michele/progettiINFO3A/ASM/ASM_luminosita.jpg)
