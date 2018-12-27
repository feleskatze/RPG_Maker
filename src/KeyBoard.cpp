#define DDX_GCC_COMPILE
#define DDX_MPM_INLINE_ASM
#define DDX_NON_INLINE_ASM


#include <DxLib.h>
#include "Keyboard.hpp"

static int Key[256];

int KeyBoard_Update(){
  char tmpKey[256];
  GetHitKeyStateAll(tmpKey);
  for(int i = 0; i < 256; i++) tmpKey[i] != 0 ? (Key[i]++) : (Key[i] = 0);
  return 0;
}

int KeyBoard_Get(int KeyCode){
  return Key[KeyCode];
}

int KeyCode_Add(int KeyCode, int Num){
  Key[KeyCode] += Num;
}

int KeyBoard_Clear(){
  for(int i = 0; i < 256; i++) Key[i] = 0;
}
