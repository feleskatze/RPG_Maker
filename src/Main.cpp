#define DDX_GCC_COMPILE
#define DDX_MPM_INLINE_ASM
#define DDX_NON_INLINE_ASM

#include "DXlib.h"
#include "KeyBoard.hpp"
#include "Message.hpp"

////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
  SetOutApplicationLogValidFlag(false);
  SetMainWindowText("RPG");
  SetGraphMode(640,480,16);
  ChangeWindowMode(TRUE); // Window Modw
  if(DxLib_Init()== -1)return -1;//DX Library Init
  SetDrawScreen(DX_SCREEN_BACK);

  // Init
  Message Message;


  // Main Loop
  while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && KeyBoard_Update()==0){

    Message.Run("こっこｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋｋ");







  }// Main Loop End

  DxLib_End();//DX Library End
  return 0;
}
