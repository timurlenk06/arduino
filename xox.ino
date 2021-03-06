#define Buton 5
int sayac=1, durum, oncekidurum;
boolean dokuz=0;
boolean sekiz=0;
boolean yedi=0;
boolean alti=0;
boolean bes=0;
boolean dort=0;
boolean uc=0;
boolean iki=0;
boolean bir=0;
int sira=1;
int ledciktix=14;
int ledciktiy=-1;
int xox[9];
int temizle=1;
int ilk=1;
int hamle=1;
int secim=0;
int hamleson=0;
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

void setup() 
{
  Serial.begin(9600);
  pinMode(Buton,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  oncekidurum=digitalRead(2);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 

  
  

}

void loop() 
{
  display.display();
  delay(20);
  display.clearDisplay();
  if (secim==0)
  {
      durum=digitalRead(2);
      if(durum!=oncekidurum)
      {
        if(digitalRead(3)!=durum)
        {
          sayac++;
          }
      delay(20);
      Serial.print("sayaç=");
      Serial.println(sayac);
      delay(10);
      }
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.display();
      display.setCursor(6,10);
      display.print("Bilgisayar");
      display.setCursor(46,40);
      display.print("1V1");
      int tikla=digitalRead(Buton);
      if(sayac%2==0)
      {  
          display.clearDisplay();
          
          display.setCursor(6,10);
          display.print("Bilgisayar");
          if(tikla==1)
          {
            secim=1;
            delay(30);
            sayac=1;
            }
          
        }
      else if(sayac%1==0)
      {
        display.clearDisplay();
        
        display.setCursor(46,40);
        display.print("1V1");
        if(tikla==1)
          {
            secim=2;
            delay(50);
            sayac=1;
            }
      
        }
    }
  else if(secim==1)
  {
  display.drawLine(127, 64, 127, 0, WHITE);
  display.drawLine(42, 64, 42, 0, WHITE);
  display.drawLine(84, 64, 84, 0, WHITE);
  display.drawLine(0, 64, 0, 0, WHITE);
  delay(20);
  //yatay çizgiler
  display.drawLine(0, 63, 128, 63, WHITE);
  display.drawLine(0, 42, 128, 42, WHITE);
  display.drawLine(0, 21, 128, 21, WHITE);
  display.drawLine(0, 0, 128, 0, WHITE);
  
  delay(20);
 
  display.setTextSize(3);
  display.setTextColor(WHITE);
  if(xox[0]!=0 or xox[1]!=0 or xox[2]!=0 or xox[3]!=0 or xox[4]!=0 or xox[5]!=0 or xox[6]!=0 or xox[7]!=0 or xox[8]!=0 or xox[9]!=0 )
  {
    if(xox[0]==1)
    {
      display.setCursor(14,-1);
      display.print("X");
    }
    else if(xox[0]==2)
    {
      display.setCursor(14,-1);
      display.print("O");
    }
    if(xox[1]==1)
    {
      display.setCursor(56,-1);
      display.print("X");
    }
    else if(xox[1]==2)
    {
      display.setCursor(56,-1);
      display.print("O");
    }
     if(xox[2]==1)
    {
      display.setCursor(98,-1);
      display.print("X");
    }
    else if(xox[2]==2)
    {
      display.setCursor(98,-1);
      display.print("O");
    }
     if(xox[3]==1)
    {
      display.setCursor(14,22);
      display.print("X");
    }
    else if(xox[3]==2)
    {
      display.setCursor(14,22);
      display.print("O");
    }
     if(xox[4]==1)
    {
      display.setCursor(56,22);
      display.print("X");
    }
    else if(xox[4]==2)
    {
      display.setCursor(56,22);
      display.print("O");
    }
     if(xox[5]==1)
    {
      display.setCursor(98,22);
      display.print("X");
    }
    else if(xox[5]==2)
    {
      display.setCursor(98,22);
      display.print("O");
    }
     if(xox[6]==1)
    {
      display.setCursor(14,44);
      display.print("X");
    }
    else if(xox[6]==2)
    {
      display.setCursor(14,44);
      display.print("O");
    }
     if(xox[7]==1)
    {
      display.setCursor(56,44);
      display.print("X");
    }
    else if(xox[7]==2)
    {
      display.setCursor(56,44);
      display.print("O");
    }
     if(xox[8]==1)
    {
      display.setCursor(98,44);
      display.print("X");
    }
    else if(xox[8]==2)
    {
      display.setCursor(98,44);
      display.print("O");
    }
  }
  
 
 
  durum=digitalRead(2);
  if(durum!=oncekidurum)
  {
    if(digitalRead(3)!=durum)
    {
      sayac++;
      }
      delay(20);
      Serial.print("sayaç=");
      Serial.println(sayac);
      delay(10);
  
       
    }
    
    int tikla=digitalRead(Buton);
    
    if (tikla == 1)
    {
      delay(40);
      display.clearDisplay();
      
      if(sayac%9==0 and dokuz==0)
      {

         xox[8]=1;
         dokuz=1;
         sira++;
        
        }
      else if(sayac%8==0 and sekiz==0)
       {
        xox[7]=1;
        sekiz=1;
        sira++;
        }
      else if(sayac%7==0 and yedi==0)
       {
        xox[6]=1;
        yedi=1;
        sira++;
        }
      else if(sayac%6==0 and alti==0)
       {
        xox[5]=1;
        alti=1;
        sira++;
        }
      else if(sayac%5==0 and bes==0)
       {

        xox[4]=1;
        bes=1;
        sira++;
        }
      else if(sayac%4==0 and dort==0)
       {
        xox[3]=1;
        dort=1;
        sira++;
        }
      else if(sayac%3==0 and uc==0)
       {
        xox[2]=1;
        uc=1;
        sira++;
        }
      else if(sayac%2==0 and iki==0)
       {
        xox[1]=1;
        iki=1;
        sira++;
        }
      else if(sayac%1==0 and bir==0)
       {
        xox[0]=1;
        bir=1;
        sira++;
        }
      delay(60);
      Serial.println(tikla);
      sayac=1;
      int a=1;
      if(hamle==1)
      {
         hamle++;
         int rasgelehamle=random(9);
         if(xox[rasgelehamle]!=1)
         {
            xox[rasgelehamle]=2;
          }
          else
          {
            int rasgelehamle=random(9);
            if(xox[rasgelehamle]!=1)
             {
                xox[rasgelehamle]=2;
              }
             else
             {
              int rasgelehamle=random(9);
              if(xox[rasgelehamle]!=1)
               {
                  xox[rasgelehamle]=2;
                }
              }
            }
         
      }
      else if(hamle==2)
      {
        hamle++;
        int i=0;
        while(i<9)
        {
          if(xox[i]==1)
          {
            if(xox[i+1]==1)
            {
                xox[i+2]=2;

              }
            else if(xox[i-1]==1)
            {
              xox[i-2]=2;
              }
            else if(xox[i+3]==1)
            {
              xox[i+6]=2;
              }
            else if(xox[i-3]==1)
            {
              xox[i-6]=2;
              }
            else if(xox[i+6]==1)
            {
              xox[i+3]=2;
              }
            else if(xox[i-6]==1)
            {
              xox[i-3]=2;
              }
             else if(xox[i+2]==1)
              {
              xox[i+1]=2;
              }
              else if(xox[i-2]==1)
              {
              xox[i-1]=2;
              }
            
            
            i=9;
            }
            i++;
          }
        }
      else if(hamle>=3)
      {
    
        int i=0;
        while(i<9)
        {
          if(xox[i]==2)
          {
            if(xox[i+1]==2)
            {
              if(xox[i+2]!=1)
              {xox[i+2]=2;
              hamleson=1;
              break;}
              }
            else if(xox[i-1]==2)
            {
              if(xox[i-2]!=1)
              {xox[i-2]=2;
              hamleson=1;
              break;}
              }
            else if(xox[i+3]==2)
            {
              if(xox[i+6]!=1)
              {xox[i+6]=2;
              hamleson=1;
              break;}
              }
            else if(xox[i-3]==2)
            {
              if(xox[i-6]!=1)
              {xox[i-6]=2;
              hamleson=1;
              break;}
              }
            else if(xox[i+6]==2)
            {
              if(xox[i+3]!=1)
              {xox[i+3]=2;
              hamleson=1;
              break;}
              }
            else if(xox[i-6]==2)
            {
              if(xox[i-3]!=1)
              {xox[i-3]=2;
              hamleson=1;
              break;}
              }
             else if(xox[i+2]==2)
              {
              if(xox[i+1]!=1)
              {xox[i+1]=2;
              hamleson=1;
              break;}
              }
              else if(xox[i-2]==2)
              {
              if(xox[i-1]!=1)
              {xox[i-1]=2;
              hamleson=1;
              break;}
              }
              else if(xox[i+2]==2)
              {
              if(xox[i+4]!=1)
              {xox[i+4]=2;
              hamleson=1;
               break;}
              }
               else if(xox[i+4]==2 and i!=4)
              {
              if(xox[i+2]!=1)
              {xox[i+2]=2;
              hamleson=1;
               break;}
              }
              else if(xox[i-4]==2 and i!=8)
              {
              if(xox[i-2]!=1)
              {xox[i-2]=2;
              hamleson=1;
               break;}
              }
            }
            i++;
          }
       int kontrol=0;
       if(hamleson!=1)
        {
          
        while(kontrol<9)
        {
          if(xox[kontrol]==1)
          {
            if(xox[kontrol+1]==1)
            {
              if(xox[kontrol-1]!=1 or xox[kontrol-1]!=2)
              {
                
                if(xox[kontrol-1]!=1 and xox[kontrol-1]!=2){
                  xox[kontrol-1]=2;
                  kontrol=20;
                }
                
                }
              else
              {
                if(xox[kontrol+2]!=1 and xox[kontrol+2]!=2)
                {
                xox[kontrol+2]=2;
                kontrol=20;
                }
                }
              
              }
            else if(xox[kontrol-1]==1)
            {
              
              if(xox[kontrol-2]!=1 and xox[kontrol-2]!=2)
              {
              xox[kontrol-2]=2;
              kontrol=20;
              }
             }
            else if(xox[kontrol+3]==1)
            {
              
              if(xox[kontrol+6]!=1 and xox[kontrol+6]!=2)
              {
              xox[kontrol+6]=2;
              kontrol=20;
              }
              
              }
            else if(xox[kontrol-3]==1)
            {
            
              if(xox[kontrol-6]!=1 and xox[kontrol-6]!=2)
              {
              xox[kontrol-6]=2;
              kontrol=20;
              }
            }
            else if(xox[kontrol+6]==1)
            {
            if(xox[kontrol+3]!=1 and xox[kontrol+3]!=2)
              {
              xox[kontrol+3]=2;
              kontrol=20;
              }
              
            }
            else if(xox[kontrol-6]==1)
            {
               if(xox[kontrol-3]!=1 and xox[kontrol-3]!=2)
              {
              xox[kontrol-3]=2;
              kontrol=20;
              }
             }
             else if(xox[kontrol+2]==1)
              {
                
              if(xox[kontrol+1]!=1 and xox[kontrol+1]!=2)
              {
              xox[kontrol+1]=2;
              kontrol=20;
              }
              
              }
              else if(xox[kontrol-2]==1)
              {
                if(xox[kontrol-1]!=1 and xox[kontrol-1]!=2)
                {
                xox[kontrol-1]=2;
                kontrol=20;
                }
              }
            
            }
            kontrol++;
        }
           
          }
          if(hamleson!=1 and kontrol==0)
          {
            int i=0;
            while(i<9)
            {
              if(xox[i]!=1 and xox[i]!=2)
              {
                xox[i]=2;
                break;
              }
            }
            }
          
        
          /**
          if(hamleson!=1)
          {
             int i=0;
              while(i<9)
              {
                if(xox[i]==1)
                {
                  if(xox[i+1]==1)
                  {
                    if(xox[i-1]!=1 or xox[i-1]!=2)
                    {
                      if(xox[i-1]!=1 and xox[i-1]!=2)
                      {xox[i-1]=2;
                      hamleson=1;
                      break;}
                      }
                    else
                    {
                      if(xox[i+2]!=1 and xox[i+2]!=2)
                      {xox[i+2]=2;
                      hamleson=1;
                      break;}
                      }
                    }
                  else if(xox[i-1]==1)
                  {
                    if(xox[i-2]!=1 and xox[i-2]!=2)
                      {xox[i-2]=2;
                      hamleson=1;
                      break;}
                    }
                  else if(xox[i+3]==1)
                  {
                    if(xox[i+6]!=1 and xox[i+6]!=2)
                      {xox[i+6]=2;
                      hamleson=1;
                      break;}
                    }
                  else if(xox[i-3]==1)
                  {
                    if(xox[i-6]!=1 and xox[i-6]!=2)
                      {xox[i-6]=2;
                      hamleson=1;
                      break;}
                    }
                  else if(xox[i+6]==1)
                  {
                    if(xox[i+3]!=1 and xox[i+3]!=2)
                      {xox[i+3]=2;
                      hamleson=1;
                      break;}
                    }
                  else if(xox[i-6]==1)
                  {
                    if(xox[i-3]!=1 and xox[i-3]!=2)
                      {xox[i-3]=2;
                      hamleson=1;
                      break;}
                    }
                   else if(xox[i+2]==1)
                    {
                      if(xox[i+1]!=1 and xox[i+1]!=2)
                      {xox[i+1]=2;
                      hamleson=1;
                      break;}
                    }
                    else if(xox[i-2]==1)
                    {
                      if(xox[i-1]!=1 and xox[i-1]!=2)
                      {xox[i-1]=2;
                      hamleson=1;
                      break;}
                    }
           
                  }
                  i++;
                }
           
            }
            if(hamleson!=0)
            {
              int i=0;
              while(i<9)
              {
                if(xox[i]!=1 and xox[i]!=2)
                {
                  xox[i]=2;
                  break;
                  }
                  i++;
                }
              
              }**/
            
            hamle++;     
        }
       
      }
      else
      {
        if(sayac%9==0 and dokuz==0)
      {
          display.setCursor(98,44);
          display.print("-");  
        }
      else if(sayac%8==0 and sekiz==0)
       {
          display.setCursor(56,44);
          display.print("-");
        }
      else if(sayac%7==0 and yedi==0)
       {
          display.setCursor(14,44);
          display.print("-");
        }
      else if(sayac%6==0 and alti==0)
       {
          display.setCursor(98,22);
          display.print("-");
        }
      else if(sayac%5==0 and bes==0 and sayac%10!=0)
       {
          display.setCursor(56,22);
          display.print("-");
        }
      else if(sayac%4==0 and dort==0 and sayac%10!=0)
       {
          display.setCursor(14,22);
          display.print("-");    
        }
      else if(sayac%3==0 and uc==0 )
       {         
          display.setCursor(98,-1);
          display.print("-");
        }
      else if(sayac%2==0 and iki==0 and sayac%10!=0 or sayac==11 )
       {
          display.setCursor(56,-1);
          display.print("-");
        }
      else if(sayac%1==0 and bir==0)
       {
          display.setCursor(14,-1);
          display.print("-");  
        }
        
        }
      
     
    
    oncekidurum=durum;
    /**
    if( (xox[2]!=0 and xox[2]==xox[5] and xox[2]==xox[8]) or (xox[1]!=0 and xox[1]==xox[4] and xox[1]==xox[7]) or (xox[0]!=0 and xox[0]==xox[3] and xox[0]==xox[6]) or (xox[0]!=0 and xox[0]==xox[1] and xox[0]==xox[2])or (xox[3]!=0 and xox[3]==xox[4] and xox[3]==xox[5]) or (xox[6]!=0 and xox[6]==xox[7] and xox[6]==xox[8]) or (xox[2]!=0 and xox[2]==xox[4] and xox[2]==xox[6]) or (xox[0]!=0 and xox[0]==xox[4] and xox[0]==xox[8]))
    {
      delay(5000);
      secim=3;
      }**/
     
    
    }
  else if(secim==2)
  {
  if( (xox[2]!=0 and xox[2]==xox[5] and xox[2]==xox[8]) or (xox[1]!=0 and xox[1]==xox[4] and xox[1]==xox[7]) or (xox[0]!=0 and xox[0]==xox[3] and xox[0]==xox[6]) or (xox[0]!=0 and xox[0]==xox[1] and xox[0]==xox[2])or (xox[3]!=0 and xox[3]==xox[4] and xox[3]==xox[5]) or (xox[6]!=0 and xox[6]==xox[7] and xox[6]==xox[8]) or (xox[2]!=0 and xox[2]==xox[4] and xox[2]==xox[6]) or (xox[0]!=0 and xox[0]==xox[4] and xox[0]==xox[8]))
    {
      secim=3;
      }
  display.drawLine(127, 64, 127, 0, WHITE);
  display.drawLine(42, 64, 42, 0, WHITE);
  display.drawLine(84, 64, 84, 0, WHITE);
  display.drawLine(0, 64, 0, 0, WHITE);
  delay(20);
  //yatay çizgiler
  display.drawLine(0, 63, 128, 63, WHITE);
  display.drawLine(0, 42, 128, 42, WHITE);
  display.drawLine(0, 21, 128, 21, WHITE);
  display.drawLine(0, 0, 128, 0, WHITE);
  
  delay(20);
 
  display.setTextSize(3);
  display.setTextColor(WHITE);
  if(xox[0]!=0 or xox[1]!=0 or xox[2]!=0 or xox[3]!=0 or xox[4]!=0 or xox[5]!=0 or xox[6]!=0 or xox[7]!=0 or xox[8]!=0 or xox[9]!=0 )
  {
    if(xox[0]==1)
    {
      display.setCursor(14,-1);
      display.print("X");
    }
    else if(xox[0]==2)
    {
      display.setCursor(14,-1);
      display.print("O");
    }
    if(xox[1]==1)
    {
      display.setCursor(56,-1);
      display.print("X");
    }
    else if(xox[1]==2)
    {
      display.setCursor(56,-1);
      display.print("O");
    }
     if(xox[2]==1)
    {
      display.setCursor(98,-1);
      display.print("X");
    }
    else if(xox[2]==2)
    {
      display.setCursor(98,-1);
      display.print("O");
    }
     if(xox[3]==1)
    {
      display.setCursor(14,22);
      display.print("X");
    }
    else if(xox[3]==2)
    {
      display.setCursor(14,22);
      display.print("O");
    }
     if(xox[4]==1)
    {
      display.setCursor(56,22);
      display.print("X");
    }
    else if(xox[4]==2)
    {
      display.setCursor(56,22);
      display.print("O");
    }
     if(xox[5]==1)
    {
      display.setCursor(98,22);
      display.print("X");
    }
    else if(xox[5]==2)
    {
      display.setCursor(98,22);
      display.print("O");
    }
     if(xox[6]==1)
    {
      display.setCursor(14,44);
      display.print("X");
    }
    else if(xox[6]==2)
    {
      display.setCursor(14,44);
      display.print("O");
    }
     if(xox[7]==1)
    {
      display.setCursor(56,44);
      display.print("X");
    }
    else if(xox[7]==2)
    {
      display.setCursor(56,44);
      display.print("O");
    }
     if(xox[8]==1)
    {
      display.setCursor(98,44);
      display.print("X");
    }
    else if(xox[8]==2)
    {
      display.setCursor(98,44);
      display.print("O");
    }
  }
 
 
  durum=digitalRead(2);
  if(durum!=oncekidurum)
  {
    if(digitalRead(3)!=durum)
    {
      sayac++;
      }
      delay(20);
      Serial.print("sayaç=");
      Serial.println(sayac);
      delay(10);
  
       
    }
    
    int tikla=digitalRead(Buton);
    
    if (tikla == 1)
    {
      delay(20);
      display.clearDisplay();
      
      if(sayac%9==0 and dokuz==0)
      {
        if(sira%2==0)
        {
          xox[8]=2;
          
          }
         else
         {
          xox[8]=1;
          
          }
         dokuz=1;
         sira++;
        
        }
      else if(sayac%8==0 and sekiz==0)
       {
        if(sira%2==0)
        {
          xox[7]=2;
         
          }
         else
         {
          xox[7]=1;
          
          }
        sekiz=1;
        sira++;
        }
      else if(sayac%7==0 and yedi==0)
       {
        if(sira%2==0)
        {
          xox[6]=2;
          
          }
         else
         {
          
          xox[6]=1;
          }
        yedi=1;
        sira++;
        }
      else if(sayac%6==0 and alti==0)
       {
        if(sira%2==0)
        {
          xox[5]=2;
          
          }
         else
         {
          xox[5]=1;
          
          }
        alti=1;
        sira++;
        }
      else if(sayac%5==0 and bes==0)
       {
        if(sira%2==0)
        {
          xox[4]=2;
          
          }
         else
         {
          xox[4]=1;
          
          }
        bes=1;
        sira++;
        }
      else if(sayac%4==0 and dort==0)
       {
        if(sira%2==0)
        {
          xox[3]=2;
          
          }
         else
         {
          xox[3]=1;
          
          }
        dort=1;
        sira++;
        }
      else if(sayac%3==0 and uc==0)
       {
        if(sira%2==0)
        {
          xox[2]=2;
          
          
          }
         else
         {
          xox[2]=1;
          
          }
        uc=1;
        sira++;
        }
      else if(sayac%2==0 and iki==0)
       {
        if(sira%2==0)
        {
          xox[1]=2;
          
          }
         else
         {
          xox[1]=1;
          
          }
        iki=1;
        sira++;
        }
      else if(sayac%1==0 and bir==0)
       {
        if(sira%2==0)
        {
          xox[0]=2;
         
          }
         else
         {
          xox[0]=1;
          
          }
        bir=1;
        sira++;
        }
     
      delay(60);
      Serial.println(tikla);
      sayac=1;
       int a=1;
      
      
      }
      else
      {
        if(sayac%9==0 and dokuz==0)
      {
          display.setCursor(98,44);
          display.print("-");  
        }
      else if(sayac%8==0 and sekiz==0)
       {
          display.setCursor(56,44);
          display.print("-");
        }
      else if(sayac%7==0 and yedi==0)
       {
          display.setCursor(14,44);
          display.print("-");
        }
      else if(sayac%6==0 and alti==0)
       {
          display.setCursor(98,22);
          display.print("-");
        }
      else if(sayac%5==0 and bes==0 and sayac%10!=0)
       {
          display.setCursor(56,22);
          display.print("-");
        }
      else if(sayac%4==0 and dort==0 and sayac%10!=0)
       {
          display.setCursor(14,22);
          display.print("-");    
        }
      else if(sayac%3==0 and uc==0 )
       {         
          display.setCursor(98,-1);
          display.print("-");
        }
      else if(sayac%2==0 and iki==0 and sayac%10!=0 or sayac==11 )
       {
          display.setCursor(56,-1);
          display.print("-");
        }
      else if(sayac%1==0 and bir==0)
       {
          display.setCursor(14,-1);
          display.print("-");  
        }
        
        }
        
    oncekidurum=durum;
    
    }
    else if(secim==3)
    {
        delay(1000);
        display.clearDisplay();
        
        display.setCursor(0,0);
        display.println("Oyun");
        display.print("Bitti...");
      }
  
}
