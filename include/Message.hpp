#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_


class Message {
    private:
      int Font; // Font Setting
      int FontInit(); // Font Init
      int FrameImage[9];
      int FrameInit(); // Frame Init

      char TextBuf[40][100];
      int TextBufInit();

      // Draw
      int FrameDraw();
      int TextDraw(char Text[]); // Diray Message Text


    public:
      Message(); //Message Init
      int Run(char Text[]); // Message Running
};

#endif
