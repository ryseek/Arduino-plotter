#include <Stepper.h>
#include <Servo.h> 
Servo myservo;
#define STEPS 1000 //Количество шагов
int inSize=0; // Переменная которая будет содержать размер буфера
char str[128]; // Так как типа string тут нет, будем использовать массив символов
Stepper stepper(STEPS, 2, 3, 4, 5);
Stepper stepper2(STEPS, 9,11,12,8);
String Shagi;
int oldposX=0;
int oldposY=0;
void setup()
{
stepper.setSpeed(15); 
stepper2.setSpeed(20); 
myservo.attach(6);
myservo.write(30);
Serial.begin(9600); // Открываем порт с скоростью передачи в 9600 бод(бит/с)
}
 
 
void fowardX(int shag)
{
  stepper2.step(-1*shag);
  delay(50);
}
void setservo(int position)
{
  if(position>9 &&position<60)
  {
  myservo.write(position);
     delay(00);
  }
 
}
void fowardY(int shag)
{
  stepper.step(-1*shag);
  delay(50);
}
void backX(int shag)
{
  stepper2.step(1*shag);
  delay(50);
}
void backY(int shag)
{
  stepper.step(1*shag);
  delay(50);
}
void posX(int X)
{
  if(X>-1 && X<251)
  { 
     
    int MOVE=X-oldposX;
    if(MOVE>0) {fowardX(MOVE);}
    if(MOVE<0) {backX(-MOVE);}
    if(MOVE=0){};
    oldposX=X;
    X=0;
      delay(0);
  }

}
void posY(int Y)
{
  if(Y>-1 && Y<301)
  { 
     
    int MOVE=Y-oldposY;
    if(MOVE>0) {fowardY(MOVE);}
    if(MOVE<0) {backY(-MOVE);}
    if(MOVE=0){};
    oldposY=Y;
    Y=0;
      delay(0);
 }
 
}
void loop()
{
   inSize=0; // Сбрасываем переменную
memset(str, '\0', 128); // Очищаем массив
 if(Serial.available() > 0)
 {
   delay(200); // Ждем, для того, чтобы пришли все данные
   inSize = Serial.available(); // Получаем длину строки и записываем ее в переменную
   for (int i = 0; i < inSize; i++)
   {
     str[i] = Serial.read(); // Читаем каждый символ, и пишем его в массив
    
   }
  
   
   if (str[inSize-1]== 'f') // Если было передано строку "foward" - вращаем вперед
  
   {
     for (int i = 0; i < inSize-1; i++)
   {
       Shagi+=str[i];
   }
     Serial.println("roll X foward"); // Отправляем сообщение компьютеру
     fowardX(Shagi.toInt());
     Shagi="";
  }
  else if (str[inSize-1]=='b') // Если было передано строку "back" - вращаем назад
  {
     for (int i = 0; i < inSize-1; i++)
   {
       Shagi+=str[i];
   }
     Serial.println("roll X back");
     backX(Shagi.toInt());
      Shagi="";
  }
  else if (str[inSize-1]=='x') // Если было передано строку "back" - вращаем назад
  {
     for (int i = 0; i < inSize-1; i++)
   {
       Shagi+=str[i];
   }
     Serial.println("MOVE X TO:");
     Serial.println(Shagi);
     posX(Shagi.toInt());
      Shagi="";
  }
  else if (str[inSize-1]=='y') // Если было передано строку "back" - вращаем назад
  {
     for (int i = 0; i < inSize-1; i++)
   {
       Shagi+=str[i];
   }
     Serial.println("MOVE Y TO:");
     Serial.println(Shagi);
     posY(Shagi.toInt());
      Shagi="";
  }
  
  else if (str[inSize-1]=='v') // Если было передано строку "back" - вращаем назад
  {
     for (int i = 0; i < inSize-1; i++)
   {
       Shagi+=str[i];
   }
     Serial.println("roll Y back");
     backY(Shagi.toInt());
      Shagi="";
  }
  else if (str[inSize-1]=='z') // Если было передано строку "back" - вращаем назад
  {
     for (int i = 0; i < inSize-1; i++)
   {
       Shagi+=str[i];
   }
   
     Serial.println("roll Y foward");
     fowardY(Shagi.toInt());
      Shagi="";
  }
  else if (str[inSize-1]=='s') // Если было передано строку "back" - вращаем назад
  {
     for (int i = 0; i < inSize-1; i++)
   {
       Shagi+=str[i];
   }
   
     Serial.println("Set servo");
     setservo(Shagi.toInt());
      Shagi="";
  }
    else
  {
     Serial.println("Error command!");
  }
 }
}
