const int ledPin = 13; //pin at which LED is connected

const int ldrPin = A0; //pin at which LDR is connected

int threshold = 600;

void setup() {

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT); //Make LED pin as output

  pinMode(ldrPin, INPUT); //Make LDR pin as input

}

void loop()
{

  int ldrStatus = analogRead(ldrPin); //saving the analog values received from LDR

  if (ldrStatus <= threshold) //set the threshold value below at which the LED will turn on
  {                     //you can check in the serial monior to get approprite value for your LDR

    digitalWrite(ledPin, HIGH);  //Turing LED ON

    Serial.print("NIGHT : "); 

    Serial.println(ldrStatus);

  }

  else

  {

    digitalWrite(ledPin, LOW); //Turing OFF the LED

    Serial.print("Morning : ");

    Serial.println(ldrStatus);

  }

}
