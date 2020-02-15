#include <Esplora.h>


//Actions to write to the board

void makeBlank() {
    Esplora.writeRGB(0,0,0);
}

void makeRed() {
    Esplora.writeRGB(255,0,0);
}

void makeGreen() {
    Esplora.writeRGB(0,255,0);
}

void makeBlue() {
    Esplora.writeRGB(0,0,255);
}

void makeYellow() {
    Esplora.writeRGB(255,255,0);
}
void makeOrange() {
    Esplora.writeRGB(255,165,0);
}
void makeSound() {
    Esplora.tone(6000);
}

void turnSoundOff() {
    Esplora.noTone();
}


//Functions to check the status of each switch and perform a desired action if the switch is on
//Will turn off the sound or LED if a switch is not pressed

void checkSwitch1(void (*actionFunction)()) {
    if (!Esplora.readButton(SWITCH_1)) {
        (*actionFunction)();
    } else {
        makeBlank();
        turnSoundOff();
    }
}

void checkSwitch2(void (*actionFunction)()) {
    if (!Esplora.readButton(SWITCH_2)) {
        (*actionFunction)();
    } else {
        makeBlank();
        turnSoundOff();
    }
}

void checkSwitch3(void (*actionFunction)()) {
    if (!Esplora.readButton(SWITCH_3)) {
        (*actionFunction)();
    } else {
        makeBlank();
        turnSoundOff();
    }
}

void checkSwitch4(void (*actionFunction)()) {
    if (!Esplora.readButton(SWITCH_4)) {
        (*actionFunction)();
    } else {
        makeBlank();
        turnSoundOff();
    }
}

void checkLight() {
  Serial.println(Esplora.readLightSensor());
}

bool checkSlider(int activationPercentage) {
  if ((Esplora.readSlider() / 1023.0 * 100.0) < (100 - activationPercentage)) {
    return true;
  } else {
    return false;
  }
}

float readSlider() {
  return (1 - Esplora.readSlider() / 1023.0);
}

void setup() {

}

//Here are the functions you can enter for each of the switches:
//  makeRed
//  makeGreen
//  makeBlue
//  makeYellow
//  makeOrange
//  makeSound

String name = "Lizzie is Cool."; //<<       CHANGE THIS LINE

void loop() {
  if (checkSlider(50)) {
    checkSwitch1(makeBlue);
    checkSwitch2(makeOrange);
    checkSwitch3(makeYellow);
    checkSwitch4(makeSound);
  }

  Serial.println(name.substring(0, floor(readSlider() * name.length())));
}
