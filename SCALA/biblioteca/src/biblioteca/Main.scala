package biblioteca

object Main {
  def main(args:Array[String]): Unit = {
    val biblio = biblioteca
    biblioteca.popolaElementi()
    biblioteca.popolaUtenti()
    
    println("utente 1 prende in prestito 1")
    biblioteca.presta(0, 0)
    biblioteca.stampa()
      
    println("utente 2 prende in prestito 3")  
    biblioteca.presta(1, 2)
    biblioteca.stampa()
      
    println("utente 1 restituisce 1")
    biblioteca.restituisci(0, 0)
    biblioteca.stampa()
    
    println("utente 2 prende in prestito 1")
    biblioteca.presta(1, 0)
    biblioteca.stampa()
    
    println("utente 3 prova a prendere in prestito 1")
    biblioteca.presta(2, 0)
    biblioteca.stampa()
  }
}
