// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <keyboard.h>
#include "../include/scheduler.h"
#include "../include/naiveConsole.h"

static const unsigned char ASCIITable[] = {
     0,   27,  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', 0, 8,  
     9, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 0,  '+', '\n', 0,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '{', '|', 14,  '}', // 14 es shift izquierdo pressed
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',','.', '-',  15, '*', 0,  ' ', 11, 17, // 15 Shift derecho pressed, 11 bloq mayus, 17 F1 que representa device control 1 en tabla ascii
    18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 18 es F2, 19 es F3
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0xAA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xB6 // 0xAA y 0xB6 shift izquierdo y derecho release
};

static unsigned char actualKey;

void keyboard_handler() {
  unsigned char key = getKey();
  if (key < 183) {
    actualKey = ASCIITable[key];
    awakeKeyboardQueue();
  }
}

unsigned char getInput() {
  if (!actualKey)
    return 0;
  char aux = actualKey;
  actualKey = 0;
  return aux;
}
