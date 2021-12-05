asm Reader

import StandardLibrary

//simulatore degli stati logici di un eBook reader

signature:
//dichiarazione dei domini
	enum domain Stato = {MENU | LETTURA | IMPOSTAZIONI | OFF}
	enum domain Op = {ACCENDI | SPEGNI | SCEGLI | APRIMENU | AGGIORNAPAG | APRIIMPOSTAZIONI | LUMSU | LUMGIU }
	domain Lum subsetof Integer
	
//funzioni
	static maxLum : Integer
	static minLum : Integer 
	dynamic controlled luminosita : Lum
	dynamic controlled stato: Stato
	dynamic monitored input: Op

definitions:
	domain Lum = {0 : 5}
	function maxLum = 5
	function minLum = 0
	
	rule r_impostazioni = 
		let ($i = input) in
		switch ($i)
			case APRIMENU:
				stato := MENU
			case SPEGNI:
			par
				stato := OFF
				luminosita := 0
			endpar
			case LUMSU:
				if (luminosita < maxLum) then
					luminosita := luminosita + 1
				endif
			case LUMGIU:
				if (luminosita > minLum) then
					luminosita := luminosita - 1
				endif
			endswitch
		endlet	
	
	rule r_lettura =
		let ($i = input) in 
			switch ($i)
			case APRIMENU:
				stato := MENU
			case AGGIORNAPAG:
				skip
			case SPEGNI:
			par
				stato := OFF
				luminosita := 0
			endpar
			case LUMSU:
				if (luminosita < maxLum) then
					luminosita := luminosita + 1
				endif
			case LUMGIU:
				if (luminosita > minLum) then
					luminosita := luminosita - 1
				endif
			endswitch
		endlet

//
	rule r_menu =
		let ($i = input) in
			switch ($i)
			case SCEGLI:
				stato := LETTURA
			case APRIIMPOSTAZIONI:
				stato := IMPOSTAZIONI
			case SPEGNI:
			par
				stato := OFF
				luminosita := 0
			endpar
			case LUMSU:
				if (luminosita < maxLum) then
					luminosita := luminosita + 1
				endif
			case LUMGIU:
				if (luminosita > minLum) then
					luminosita := luminosita - 1
				endif
			endswitch
		endlet
		
	rule r_off =
		let ($i = input) in
			switch ($i)
			case ACCENDI:
				par
					stato := MENU
					luminosita := 1
				endpar
			endswitch
		endlet 
	
	main rule r_Main =
		switch (stato)
			case MENU:
				r_menu[]
			case LETTURA:
				r_lettura[]
			case IMPOSTAZIONI:
				r_impostazioni[]
			case OFF:
				r_off[]
		endswitch

default init s0:
	function stato = OFF
	function luminosita = 0
