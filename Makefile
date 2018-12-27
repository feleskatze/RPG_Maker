TARGET=RPG
CC=gcc
CXX=g++
CFLAGS=-g -O2 -w -mwindows
CXXFLAGS=$(CFLAGS)
LDFLAGS=-static-libgcc -static-libstdc++
INCDIR=-I./include -I./DXLib
LIBDIR=-L./include -L./DXLib
LIBS= -lDxLib -lDxUseCLib -lDxDrawFunc -ljpeg -lpng -lzlib -ltiff -ltheora_static -lvorbis_static -lvorbisfile_static -logg_static -lbulletdynamics -lbulletcollision -lbulletmath -lopusfile -lopus -lsilk_common -lcelt
LIBS+=-lgdi32
SRCDIR=./src
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJDIR=./obj
OBJS=$(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPENDS   = $(OBJS:.o=.d)

.PHONY: all
all: $(TARGET)


.PHONY: start
start:
	$(TARGET)

.PHONY: debug
debug:
	gdb $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCDIR)  -o $@ -c $<



-include $(DEPENDS)
