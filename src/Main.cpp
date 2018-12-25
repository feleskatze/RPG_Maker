#define DDX_GCC_COMPILE
#define DDX_MPM_INLINE_ASM
#define DDX_NON_INLINE_ASM

#include "DXlib.h"


char Key[256];
int gpUpdateKey();

////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
  ChangeWindowMode(TRUE); // Window Modw
  if(DxLib_Init()== -1)return -1;//DX Library Init
    SetDrawScreen(DX_SCREEN_BACK);


  while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0){








  }//while

  DxLib_End();//DX Library End
  return 0;
}

////////////////////////////////////////////
// KeyBoard Input
////////////////////////////////////////////

int gpUpdateKey(){
 char tmpKey[256];
 GetHitKeyStateAll(tmpKey);
 for(int i=0;i<256;i++){
  if(tmpKey[i]!=0){
   Key[i]++;
  }else{
   Key[i]=0;
  }
 }
 return 0;
}
