/**
 * Test interrupt (su arduino UNO solo pin 2 e 3)
 * 
 * collegare un tasto al pin 3
 * collegare un led al pin 13
 */

void setup() {
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), cambia, FALLING);
}

volatile int stato = LOW; //volatile non può essere cambiata da altre parti di codice

void loop() {
  digitalWrite(13, stato);  
}

/*
 * Funzione di gestione dell'interrupt: non riceve parametri e non 
 * restituisce nulla.
 * Deve essere rapida e può usare solo variabili volatili e globali
 */
void cambia() {
  stato = !stato;  
}
