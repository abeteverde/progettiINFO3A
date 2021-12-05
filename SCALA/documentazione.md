%progettino INFO 3A: SCALA
%Michele Dentella (1063244)
%nov 2021

\pagebreak

# 1. Introduzione

Sistema che gestisce i prestiti di una biblioteca.
Il sistema è composto da utenti e da elementi (CD o Libri).
I prestiti sono registrati sia negli elementi (che hanno un riferimento all'ID dell'utente che ha preso in prestito l'elemento) che negli utenti (che hanno una lista con gli ID degli elementi presi in prestito).
Un elemento preso in prestito da un utente non può essere preso in prestito da altri utenti.

# 2. Struttura delle Classi

È presente un trait che implementa un campo e delle funzioni.
Il trait è esteso da una classe astratta che a sua volta viene estesa dalle due classi concrete CD e Libro.
Nelle classi concrete sono stati usati i costruttori delle superclassi, si rimanda al codice sorgente per ulteriori dettagli.

![struttura classi elementi libreria](/home/michele/progettiINFO3A/SCALA/classi_scala.jpg)

\pagebreak

La biblioteca è un oggetto singleton con questa struttura:

![oggetto singleton biblioteca](/home/michele/progettiINFO3A/SCALA/biblioteca.jpg)

Gli utenti sono implementati con una classe standard.
Dettagli implementativi nel codice.

![classe utente](/home/michele/progettiINFO3A/SCALA/utente_scala.jpg)

\pagebreak

# 3. Esecuzione

Inizialmente la Libreria viene popolata con qualche utente e con qualche elemento
Vengono eseguiti alcuni prestiti e restituzioni, ad ogni passo è mostrato il risultato dell'operazione stampando lo stato globale del sistema (tramite metodo stampa di Libreria).

