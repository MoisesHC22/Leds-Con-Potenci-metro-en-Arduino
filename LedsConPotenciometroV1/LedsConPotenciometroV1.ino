
//Declaración de las variables.
int potenciometro = 0;

//Leds Verdes.
int LedB1 = 2;
int LedB2 = 3;
int LedB3 = 4;

//Leds Rojos.
int LedM1 = 8;
int LedM2 = 9;
int LedM3 = 10;

void setup()
{
  
//Configuramos los pines de salida.  
  pinMode(A0, INPUT);
  pinMode(LedB1, OUTPUT);
  pinMode(LedB2, OUTPUT);
  pinMode(LedB3, OUTPUT);
  pinMode(LedM1, OUTPUT);
  pinMode(LedM2, OUTPUT);
  pinMode(LedM3, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  
//Obtiene el valor del potenciómetro conectado al pin analógico "A0".
potenciometro = analogRead(A0);

 /*
    Se realiza una condición en donde si el potenciómetro es mayor a
    "450" entra a hacer la función para los leds verdes, si no lo 
    cumple entra en la otra condición en donde el valor análogo es 
    menor a "450" y por lo tanto hace la función de los leds rojos.
 */
 
  if(potenciometro > 450){

//Encendido y apagado de leds.   
    digitalWrite(LedB1, HIGH);
    delay(300);
    digitalWrite(LedB2, HIGH);
    delay(300);
    digitalWrite(LedB3, HIGH);
    delay(300);
    digitalWrite(LedM1, LOW);
    delay(300);
    digitalWrite(LedM2, LOW);
    delay(300);
    digitalWrite(LedM3, LOW);
    delay(300);

    //Imprimirá en el monitor el siguiente texto.    
    Serial.print("El estado es idoneo.");
    Serial.println("");
    
  }else if(potenciometro < 450){

//Encendido y apagado de leds.    
  digitalWrite(LedM1, HIGH);
    delay(300);
    digitalWrite(LedM2, HIGH);
    delay(300);
    digitalWrite(LedM3, HIGH);
    delay(300);
    digitalWrite(LedB1, LOW);
    delay(300);
    digitalWrite(LedB2, LOW);
    delay(300);
    digitalWrite(LedB3, LOW);
    delay(300);

    //Imprimirá en el monitor el siguiente texto.
    Serial.print("Urgente, Revisar.");
    Serial.println("");
  }
  
}
