#define DDX_GCC_COMPILE
#define DDX_MPM_INLINE_ASM
#define DDX_NON_INLINE_ASM

#include "DxLib.h"

#include "Define.hpp"

#include "Message.hpp"
#include "KeyBoard.hpp"

#define FRAME_DRAW_X 10
#define FRAME_DRAW_Y 320
#define FRAME_DRAW_WIDTH 620
#define FRAME_DRAW_HEIGHT 140

#define TEXT_DRAW_X 20
#define TEXT_DRAW_Y 340
#define TEXT_DRAW_WIDTH 600
#define TEXT_DRAW_HEIGHT 110

Message::Message(){
  Message::FontInit();
  Message::FrameInit();
  Message::TextBufInit();
}


int Message::FontInit(){
  Font = CreateFontToHandle("", FONT_SIZE, 1, DX_FONTTYPE_EDGE);
  SetFontSize(FONT_SIZE);
}


int Message::FrameInit(){
  LoadDivGraph("data/image/Frame.png", 9, 3, 3, 6, 6, FrameImage);
}


int Message::TextBufInit(){
  for(int i = 0; i < 40; i++){
    for(int j = 0; j < 100; j++) TextBuf[i][j] = NULL;
  }
}



int Message::FrameDraw(){
  SetDrawBlendMode(DX_BLENDMODE_ALPHA,230);

  DrawGraph(FRAME_DRAW_X, FRAME_DRAW_Y, FrameImage[0],TRUE);
  DrawExtendGraph(FRAME_DRAW_X + 6, FRAME_DRAW_Y, FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y + 6, FrameImage[1], TRUE);
  DrawGraph(FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y, FrameImage[2], TRUE);
  DrawExtendGraph(FRAME_DRAW_X, FRAME_DRAW_Y + 6, FRAME_DRAW_X + 6, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, FrameImage[3], TRUE);
  DrawExtendGraph(FRAME_DRAW_X + 6, FRAME_DRAW_Y + 6, FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, FrameImage[4], TRUE);
  DrawExtendGraph(FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y + 6, FRAME_DRAW_X + FRAME_DRAW_WIDTH, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, FrameImage[5],TRUE);
  DrawGraph(FRAME_DRAW_X, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, FrameImage[6], TRUE);
  DrawExtendGraph(FRAME_DRAW_X+6, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6,  FRAME_DRAW_Y + FRAME_DRAW_HEIGHT, FrameImage[7], TRUE);
  DrawGraph(FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, FrameImage[8], TRUE);

  SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}

int Message::TextDraw(char Text[]){
  static int CursorX,CursorY; // TextBuf
  static int Counter = 0; // Frame Counter
  static int CharaP; // Reference Point
  static int Flag; // End Flag
  static int KeyFlag; // Key Wait Flag

  char OneCharaBuf[5];

  if(Flag == 0){
    char Chara;

    if(KeyFlag == 1){
      if(Counter % 20 == 0) DrawFormatStringToHandle(TEXT_DRAW_X + TEXT_DRAW_WIDTH - FONT_SIZE -5, TEXT_DRAW_Y + TEXT_DRAW_HEIGHT -5 , COLOR, Font, "￣");

      if(KeyBoard_Get(KEY_INPUT_SPACE) == 1){
        if( (CursorY + 1) * FONT_SIZE >= TEXT_DRAW_HEIGHT ){
          for(int i = 0; i < 40; i++){
            for(int j = 0; j * FONT_SIZE / 2 < TEXT_DRAW_WIDTH; j++) TextBuf[i][j] = NULL;
          }
          CursorX = 0; CursorY = 0;
        }
        KeyFlag = 0;
      }
    } // KeyFlag IfEnd
    else{
      do{
        if( KeyBoard_Get(KEY_INPUT_SPACE) == 1 && KeyFlag != 1) KeyFlag = 2;

        Chara = Text[CharaP];
        switch( Chara ){
          case '@': //　NewLine Code
            if( CursorX != 0){
              CursorX = 0; CursorY++;
              if( (CursorY + 1) * FONT_SIZE >= TEXT_DRAW_HEIGHT) KeyFlag = 1;
            }
            CharaP++;
            break;

          case '#': // Wait Code
            KeyFlag = 1; CharaP++;
            break;

          case '\0':
          case ';': // End Code
            Flag = 1; CharaP++; KeyFlag = 0;
            break;

          case '|': //Clear Code
            for(int i = 0; i < 40; i++){
              for(int j = 0; j * FONT_SIZE / 2 < TEXT_DRAW_WIDTH; j++) TextBuf[i][j] = NULL;
            }
            CursorX = 0; CursorY = 0; CharaP++; KeyFlag = 0;
            break;

          default:
            int byte = mblen( &Text[CharaP], MB_CUR_MAX);
            for(int i = 0; i <= byte; i++) OneCharaBuf[i] = Text[CharaP + i];
            for(int i = 0; i < byte; i++) TextBuf[CursorY][CursorX + i] = OneCharaBuf[i];
            CharaP += byte; CursorX += byte;
            if(GetDrawFormatStringWidthToHandle(Font, TextBuf[CursorY]) >= TEXT_DRAW_WIDTH - FONT_SIZE){
              CursorX = 0; CursorY++;
              if( (CursorY + 1) * FONT_SIZE >= TEXT_DRAW_HEIGHT) KeyFlag = 1;
            }
            break;

        }// Switch End

      }while(KeyFlag == 2);// do while End
    } // KeyFlag ElseEnd
  }// Flag IfEnd
  else if(Flag == 1){
    if(KeyBoard_Get(KEY_INPUT_SPACE) == 1){
      Flag = 0; KeyFlag = 0; CursorX = 0; CursorY = 0; CharaP = 0;
      return -1;
    }
  }// Flag ElseIfEnd
  Counter++;
}


int Message::Run(char Text[]){
  Message::FrameDraw();
  for(int i=0; i < 40; i++) DrawFormatStringToHandle(TEXT_DRAW_X, TEXT_DRAW_Y + i * FONT_SIZE, COLOR, Font, TextBuf[i]);
  if(Message::TextDraw(Text) == -1){
    Message::TextBufInit();
    return -1;
  }
  return 0;
}
