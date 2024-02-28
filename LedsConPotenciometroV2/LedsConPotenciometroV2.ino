//Declaración de variables.

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

/* 
   Realizamos una función en donde recibe un valor para prender
   y apagar el led en un segundo.
*/

void OnOff(int pin)
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
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
    
    
    /*
      Se crea un arreglo en donde contendrá los pines de salida de los 
      leds verdes.
    */
    int LedsBien[] = {LedB1,LedB2,LedB3};
    
    //Creamos una variable en donde obtendrá el número de elementos del arreglo. 
    int NumLedsB = sizeof(LedsBien) / sizeof(LedsBien[0]);
    
    /*
      Realizamos un ciclo for en donde si "i" es menor a NumLedsB, se enviara
      el valor de "i", a la función "OnOff" y una vez termine la función, el
      valor de "i" se incrementará a uno. Luego, se repetirá nuevamente el 
      proceso, hasta que "i"sea mayor a NumLedsB, se detendrá. 
    */
    
    for(int i = 0; i < NumLedsB; i++)
    {
      OnOff(LedsBien[i]);
    }
    
    //Imprimirá en el monitor el siguiente texto.
    Serial.print("El estado es idoneo.");
    Serial.println("");
    delay(500);
    
  }else if(potenciometro < 450){
 
    /*
      Se crea un arreglo en donde contendrá los pines de salida de los 
      leds rojos.
    */
    
    int ledsMal[] = {LedM1,LedM2,LedM3};
    
    //Creamos una variable en donde obtendrá el número de elementos del arreglo. 
    int NumLedsM = sizeof(ledsMal) / sizeof(ledsMal[0]);
    
    /*
      Realizamos un ciclo for en donde si "i" es menor a NumLedsM, se enviara
      el valor de "i", a la función "OnOff" y una vez termine la función, el
      valor de "i" se incrementará a uno. Luego, se repetirá nuevamente el 
      proceso, hasta que "i"sea mayor a NumLedsM, se detendrá. 
    */
    
    for(int i = 0; i < NumLedsM; i++)
    {
      OnOff(ledsMal[i]);
    }
    
    //Imprimirá en el monitor el siguiente texto.
    Serial.print("Urgente, Revisar.");
    Serial.println("");
    delay(500);
  }
  
}
