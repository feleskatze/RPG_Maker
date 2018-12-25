#define DDX_GCC_COMPILE
#define DDX_MPM_INLINE_ASM
#define DDX_NON_INLINE_ASM

#include "DxLib.h"

#include "Define.hpp"

#include "Message.hpp"

#define FRAME_DRAW_X 10
#define FRAME_DRAW_Y 320
#define FRAME_DRAW_WIDTH 620
#define FRAME_DRAW_HEIGHT 140

#define TEXT_DRAW_X 20
#define TEXT_DRAW_Y 340
#define TEXT_DRAW_WIDTH 600
#define TEXT_DRAW_HEIGHT 110


int Message::FontInit(){
  Message::Font = CreateFontToHandle("", FONT_SIZE, 1, DX_FONTTYPE_EDGE);
  SetFontSize(FONT_SIZE);
}


int Message::FrameInit(){
  LoadDivGraph("data/image/Frame.png", 9, 3, 3, 6, 6, Message::FrameImage);
}


int Message::TextBufInit(){
  for(int i = 0; i < 40; i++){
    for(int j = 0; j < 100; j++) Message::TextBuf[i][j] = NULL;
  }
}



int Message::FrameDraw(){
  SetDrawBlendMode(DX_BLENDMODE_ALPHA,230);

  DrawGraph(FRAME_DRAW_X, FRAME_DRAW_Y,Message::FrameImage[0],TRUE);
  DrawExtendGraph(FRAME_DRAW_X + 6, FRAME_DRAW_Y, FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y + 6, FrameImage[1], TRUE);
  DrawGraph(FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y, Message::Frame_Image[2], TRUE);
  DrawExtendGraph(FRAME_DRAW_X, FRAME_DRAW_Y + 6, FRAME_DRAW_X + 6, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, Message::FrameImage[3], TRUE);
  DrawExtendGraph(FRAME_DRAW_X + 6, FRAME_DRAW_Y + 6, FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, Message::FrameImage[4], TRUE);
  DrawExtendGraph(FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y + 6, FRAME_DRAW_X + FRAME_DRAW_WIDTH, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, Message::FrameImage[5],TRUE);
  DrawGraph(FRAME_DRAW_X, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, Message::FrameImage[6], TRUE);
  DrawExtendGraph(FRAME_DRAW_X+6, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6,  FRAME_DRAW_Y + height, Message::FrameImage[7], TRUE);
  DrawGraph(FRAME_DRAW_X + FRAME_DRAW_WIDTH - 6, FRAME_DRAW_Y + FRAME_DRAW_HEIGHT - 6, Message::FrameImage[8], TRUE);

  SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}

int Message::TextDraw(char Text[]){

}
