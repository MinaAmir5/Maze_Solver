#include<string.h>

String path;
void setup() {
  // put your setup code here, to run once:
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);


  Serial.begin(9600);

  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);

};
void movebackward(int speed)
{ analogWrite(2, speed);
  analogWrite(3, speed);
  analogWrite(4, speed);
  analogWrite(5, speed);
  digitalWrite(36, HIGH);
  digitalWrite(37, LOW);


  digitalWrite(38, HIGH);
  digitalWrite(39, LOW);

  digitalWrite(40, HIGH);
  digitalWrite(41, LOW);


  digitalWrite(42, HIGH);
  digitalWrite(43, LOW);


}
void moveforward(int speed)
{ analogWrite(2, speed); //back right
  analogWrite(3, speed); //back left
  analogWrite(4, speed); //front left
  analogWrite(5, speed); //front right

  digitalWrite(36, LOW);
  digitalWrite(37, HIGH);


  digitalWrite(38, LOW);
  digitalWrite(39, HIGH);


  digitalWrite(40, LOW);
  digitalWrite(41, HIGH);


  digitalWrite(42, LOW);
  digitalWrite(43, HIGH);

}
void moveforwardright(int speed)
{ analogWrite(2, speed - 50); //back right
  analogWrite(3, speed - 10); //back left
  analogWrite(4, speed - 10); //front left
  analogWrite(5, speed - 50); //front right

  digitalWrite(36, LOW);
  digitalWrite(37, HIGH);


  digitalWrite(38, LOW);
  digitalWrite(39, HIGH);


  digitalWrite(40, LOW);
  digitalWrite(41, HIGH);


  digitalWrite(42, LOW);
  digitalWrite(43, HIGH);

}
void moveforwardleft(int speed)
{
  analogWrite(2, speed - 10); //back right
  analogWrite(3, speed - 30); //back left
  analogWrite(4, speed - 30); //front left
  analogWrite(5, speed - 10); //front right

  digitalWrite(36, LOW);
  digitalWrite(37, HIGH);

  digitalWrite(38, LOW);
  digitalWrite(39, HIGH);


  digitalWrite(40, LOW);
  digitalWrite(41, HIGH);


  digitalWrite(42, LOW);
  digitalWrite(43, HIGH);

}
void uturn(int speed)
{
  analogWrite(2, speed);
  analogWrite(3, speed);
  analogWrite(4, speed);
  analogWrite(5, speed);
  digitalWrite(36, LOW);//shemalodam
  digitalWrite(37, HIGH);


  digitalWrite(38, HIGH);//yemenodam
  digitalWrite(39, LOW);

  digitalWrite(40, HIGH);//yemenwara
  digitalWrite(41, LOW);


  digitalWrite(42, LOW);//shemalwara
  digitalWrite(43, HIGH);

}

void sharpyemen(int speed)
{

  analogWrite(2, speed);
  analogWrite(3, speed);
  analogWrite(4, speed);
  analogWrite(5, speed);
  digitalWrite(36, LOW);//shemalodam
  digitalWrite(37, HIGH);


  digitalWrite(38, HIGH);//yemenodam
  digitalWrite(39, LOW);

  digitalWrite(40, HIGH);//yemenwara
  digitalWrite(41, LOW);


  digitalWrite(42, LOW); //shemalwara
  digitalWrite(43, HIGH);


}
void sharpshemal(int speed)
{
  analogWrite(2, speed-30);//back right
  analogWrite(3, 0);//back left
  analogWrite(4, speed+40);//front left
  analogWrite(5, speed-30);//front right

  digitalWrite(36, HIGH);//shemalodam
  digitalWrite(37, LOW);


  digitalWrite(38, LOW);//yemenodam
  digitalWrite(39, HIGH);

  digitalWrite(40, LOW);//yemenwara
  digitalWrite(41, HIGH);


  digitalWrite(42, HIGH);//shemalwara
  digitalWrite(43, LOW);


}
void stoprobot(int speed)
{
  analogWrite(2, speed);
  analogWrite(3, speed);
  analogWrite(4, speed);
  analogWrite(5, speed);
  digitalWrite(36, LOW);//shemalodam
  digitalWrite(37, LOW);


  digitalWrite(38, LOW);//yemenodam
  digitalWrite(39, LOW);

  digitalWrite(40, LOW);//yemenwara
  digitalWrite(41, LOW);


  digitalWrite(42, LOW);//shemalwara
  digitalWrite(43, LOW);

}

void loop() {
 //sharpyemen(75);

  // put your main code here, to run repeatedly:
  //                33
  //  30     31             34      35
  //                32

  if ( digitalRead(30) && digitalRead(31) )
  {
    Serial.println("Check Left T &/ Move Left");
    Serial.println("Move Left");
    path += 'L';
    while ( (digitalRead(30) && digitalRead(31)) || (!digitalRead(30) && digitalRead(31)) || (digitalRead(30) && !digitalRead(31)))
    {
      sharpshemal(200);
    }
    
    while (  digitalRead(34) || digitalRead(31) || (digitalRead(31) && digitalRead(34) && digitalRead(33)))              //== digitalRead(33) ) &&  (digitalRead(32) ==0) )
    {
      sharpshemal(200);
    }
    
  }

  /////////Forward Condition////////////
  else if ( !digitalRead(30) && !digitalRead(31) && digitalRead(32) && digitalRead(33) )
  {
    Serial.println("Move Forward");
    path += 'S';
    moveforward(50
    );
  }
  else if ( ( !digitalRead(30) && digitalRead(31) && digitalRead(32) && !digitalRead(34) && !digitalRead(35) )
            || (  !digitalRead(30) && digitalRead(31) && !digitalRead(32) && !digitalRead(33) && !digitalRead(34) && !digitalRead(35) )
            || digitalRead(31))  {

    Serial.println("!!!!!!!! drifting right ");

    moveforwardleft(75);

  }
  else if ( !digitalRead(30) && !digitalRead(31) && digitalRead(32)  && digitalRead(34) && !digitalRead(35)
            || (  !digitalRead(30) && !digitalRead(31) && !digitalRead(32) && !digitalRead(33) && digitalRead(34) && !digitalRead(35) )
            )
  {
    Serial.println("!!!!! drifting left");
    moveforwardright(75);
  }


  /////////Reverse Condition//////////
 /* else if (!digitalRead(30) && !digitalRead(33) && !digitalRead(35) && !digitalRead(31) && !digitalRead(34))
  {
    Serial.println("Move Back");
    path += 'B';

    uturn(85);
  }
*/
  // put your main code here, to run repeatedly:
  //                33
  //  30     31               34      35
  //                32
  //// Right/Right-T Condition/////////////
  else if ( !digitalRead(30) && !digitalRead(33) && !digitalRead(31) && (digitalRead(35) || (digitalRead(35) && digitalRead(34))))
  {
    Serial.println("Check Right T &/ Move Right");
    path += 'R';
    while ( digitalRead(31) == 0 )              //== digitalRead(33) ) &&  (digitalRead(32) ==0) )
    {
      sharpyemen(100);
    }
   

  }
  else if ( digitalRead(31) && digitalRead(34) && !digitalRead(33) )
  {
    stoprobot(0);

  }
}