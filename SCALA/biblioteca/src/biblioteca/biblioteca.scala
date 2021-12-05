//biblioteca che presta libri, CD, film
package biblioteca

import scala.collection.mutable.ListBuffer

trait lib_trait {
  var inPrestito : Option[Int] = None  //default value
		  //ID utente che l'ha noleggiato (None -> libero //  Some(IDUtente) -> in noleggio

  def presta (IDUtente: Int) : Boolean = {
    if (inPrestito == None) {
      inPrestito = Some(IDUtente)
      true
    }
    else
      false
  }
  
  def restituisci (IDUtente: Int) : Boolean = {
    if (inPrestito.get ==  IDUtente) {
      inPrestito = None
      true
    }
    else
      false
  }
      
  override def toString(): String 
}

abstract class lib_element (val ID : Int, 
                        		val titolo: String,
                        		val autore: String)   extends lib_trait {
                                  //val: non cambia - c'è solo il getter -- var: cambia - getter e setter
  override def toString(): String = {
    s"*ID*: $ID titolo: $titolo autore: $autore"  //non dovrebbe essere mai chiamato...   
  }
}

class CD (val i:Int, val t: String, val a: String, 
          val nTracce: Int, 
          val durata: Double) extends lib_element (i, t, a) {
  override def toString() : String = {
    s"ID_e: $ID  prestato_a: ${if (inPrestito != None) inPrestito.get else 0} 	tipo: CD	TITOLO: $titolo AUTORE: $autore NTRACCE: $nTracce DURATA: $durata" 
  }
}

class Libro (val i:Int, val t: String, val a: String, 
             val casaEd: String,
             val nPag: Int) extends lib_element (i, t, a) {
  override def toString() : String =  {
    s"ID_e: $ID  prestato_a: ${if (inPrestito != None) inPrestito.get else 0} 	tipo: Libro	TITOLO: $titolo AUTORE: $autore CASA_ED: $casaEd PAGINE: $nPag" 
  }
}

class Utente (val ID: Int, val nome: String) {
  var prestiti: ListBuffer[Int] = new ListBuffer()
  def restituisci (id: Int): Boolean = {
    if (prestiti.contains(id)) {
      prestiti -= id  //TODO test
      true
    }
    else false
  }
  
  def noleggia(id: Int): Boolean = { 
    if (!prestiti.contains(id)) {
      prestiti += id
      true
    }
    else false
  }
  
  override def toString(): String = {
    //prestiti.foreach(x => x + " ")
    var res = s"ID_u: $ID  nome: $nome  	ID_prestiti: "
    prestiti.foreach(f => res += f + " ")
    res
  }
}


object biblioteca {
  var elementi: ListBuffer[lib_element] = new ListBuffer()
  var utenti : ListBuffer[Utente] = new ListBuffer()
  
  def popolaElementi() = {
    elementi += new CD(1, "To Record Only Water for Ten Day", "John Frusciante", 15, 42.2)
    elementi += new Libro(2, "L'accalappiastreghe", "Walter Moers", "Salani", 413)
    elementi += new Libro(3, "Concepts in Programming Languages", "Mitchell", "Cambridge University Press", 540)
    elementi += new Libro(4, "Programming in Scala", "Odersky", "Artima inc", 845)
  }
  
  def popolaUtenti() = {
    utenti += new Utente(1, "Luca")
    utenti += new Utente(2, "Franco")
    utenti += new Utente(3, "Giada")
  }
  
  def presta (nUtente: Int, nElemento:Int): Boolean = {
    if (nUtente < utenti.size && nElemento < elementi.size) {      //controllo che gli id esistano          brutto ma funzionale
      if (utenti(nUtente).noleggia(elementi(nElemento).ID))        //provo a noleggiare all'utente - se poi scopro che l'elemento è già noleggiato lo tolgo poi
        if (elementi(nElemento).presta(utenti(nUtente).ID))        //provo a noleggiare all'elemento
          true
        else {
          utenti(nUtente).restituisci(elementi(nElemento).ID)      //l'elemento è già in prestito, lo tolgo dall'utente (lo tolgo perchè prima l'ho aggiunto)
          false
        }
      else
        false
          
    }
    else false
  }
    
  def restituisci (nUtente: Int, nElemento:Int): Boolean = {
    if (nUtente < utenti.size && nElemento < elementi.size) {      //controllo che gli id esistano          brutto ma funzionale
      utenti(nUtente).restituisci(elementi(nElemento).ID)
      elementi(nElemento).restituisci(utenti(nUtente).ID)
      true
    }
    else false
  }
  
  def stampa () = {
    elementi.foreach(e => println(e.toString()))
    utenti.foreach(f => println(f.toString()))
    println()
  }
}