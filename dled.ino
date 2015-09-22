const int a = 2;                 //segmentos del display
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int botonIncremento = 9;   //pin del boton incrementa
const int botonDisminuye = 10;   //pin del boton disminuye

const int tiempoAntirebote = 10;
int cuenta = 0;
int estadoBotonIncremento;
int estadoBotonAnteriorIncremento;
int estadoBotonDisminuye;
int estadoBotonAnteriorDisminuye;

boolean antiRebote(int pin) {  //funcion de tipo boleano
  int contador = 0;
  boolean estado;              //guarda el estado del boton
  boolean estadoAnterior;      //guarda el estado anterior del boton 
  
  do {                             //la funcion "do" contiene una serie de instrucciones 
                                   //que se repiten en base a una condicion
    estado = digitalRead(pin);     
    if(estado != estadoAnterior) {  //comparamos el estado actual con el anterior
      contador = 0;                 //reiniciamos el contador
      estadoAnterior = estado;
    }
    else {
      contador = contador + 1;     //aumentamos el contador en 1
    }
    delay(1);
  } while(contador < tiempoAntirebote); //condicion que se debe de dar para que
                                        //la funcion "do" ejecute sus instrucciones
  return estado;
}

void actualizarNumero() {
  switch(cuenta) {        //funcion "switch" sirve´para preguntar el valor de una variable
                          //en este caso la variable "cuenta"   
   case 0:                //casos para cada valor de cuenta
   digitalWrite(a, LOW);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
   break;                //corta o detiene a la funcion switch
   case 1:
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   break;
   case 2:
   digitalWrite(a, LOW);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, LOW);
   break;
   case 3:
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,HIGH);
   digitalWrite(7,HIGH);
   digitalWrite(8,LOW);

   break;
   case 4:
   digitalWrite(2,HIGH);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
   digitalWrite(6,HIGH);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);

   break;
   case 5:
   digitalWrite(2,LOW);
   digitalWrite(3,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,HIGH);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);

   break;
   case 6:
   digitalWrite(2,LOW);
   digitalWrite(3,HIGH);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);

   break;
   case 7:
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
   digitalWrite(6,HIGH);
   digitalWrite(7,HIGH);
   digitalWrite(8,HIGH);

   break;
   case 8:
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);

   break;
   case 9:
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
   digitalWrite(6,HIGH);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);

   break;
  }
  
}

void setup() {
  pinMode(a, OUTPUT);  //Declaramos los pines del display como salida
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(botonIncremento, INPUT); //declaramos los pines de los botones como entrada
  pinMode(botonDisminuye, INPUT);
  
}

void loop() {
  
  estadoBotonIncremento = digitalRead(botonIncremento);     //leemos el estado del boton
  
  if(estadoBotonIncremento != estadoBotonAnteriorIncremento) {  //si hay cambio con respecto al estado anterior
    if(antiRebote(botonIncremento)) {                //checamos si esta presionado el boton, y si lo estas 
    cuenta++;                               //aumentamos la cuenta
    if(cuenta > 9){                      //en caso de que cuanta sea mayor que 9
      cuenta = 9;                           //se detiene en 9
    }
  }
}

 estadoBotonAnteriorIncremento = estadoBotonIncremento; //guardamos el estado del boton
 
 estadoBotonDisminuye = digitalRead(botonDisminuye);     //leemos el estado del boton
  
  if(estadoBotonDisminuye != estadoBotonAnteriorDisminuye) {  //si hay cambio con respecto al estado anterior
    if(antiRebote(botonDisminuye)) {                //checamos si esta presionado el boton, y si lo estas 
    cuenta--;                               //restamos la cuenta
    if(cuenta < 0) {                        //en caso de que cuenta sea menor que 0
      cuenta = 0;                           //se detiene en 0  
    }
  }
}

 estadoBotonAnteriorDisminuye = estadoBotonDisminuye; //guardamos el estado del boton
 
 actualizarNumero();
 }  
