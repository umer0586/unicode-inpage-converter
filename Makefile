#gcc version 8.1.0 (i686-posix-sjlj-rev0, Built by MinGW-W64 project)

#If your using Windows make sure that you are using make build tool from MSYS 
#MSYS is a linux shell for Windows which allows linux commands to be executed on Windows

WXWIDGETS_LIBS_DEBUG = -lwxmsw31ud_core -lwxbase31ud -lwxmsw31ud_xrc
WXWIDGETS_LIBS_RELEASE = -lwxmsw31u_core -lwxbase31u -lwxmsw31u_xrc

#if "make clean" is invoked then we don't have to check for value of MODE 
ifeq ($(MAKECMDGOALS),clean)
clean-all: clean
else
    ifndef MODE 
        $(error MODE is not set, use MODE=DEBUG or MODE=RELEASE)
    endif
    
      # optimization flags https://www.rapidtables.com/code/linux/gcc/gcc-o.html
      # debug flags https://www.rapidtables.com/code/linux/gcc/gcc-g.html
    ifeq ($(MODE),DEBUG)
        $(info builing in $(MODE) mode)
        WXWIDGETS_LIBS = $(WXWIDGETS_LIBS_DEBUG)
        CXXFLAGS =	-O0 -g -Wall -std=c++11
    else
         ifeq ($(MODE),RELEASE)
            $(info builing in $(MODE) mode)
            WXWIDGETS_LIBS = $(WXWIDGETS_LIBS_RELEASE)
            CXXFLAGS =	-O3 -g0 -std=c++11
        
         else
            $(error MODE must be either DEBUG or RELEASE )
         endif

    endif
    
endif


CXX = g++

#root for wxWidgets folder, change this accordingly 
WXWIDGETS_ROOT = D:/wxWidgets-3.14_x86

WXWIDGETS_INCLUDE = -I$(WXWIDGETS_ROOT)/include

# I built this application using pre-build dlls from wxWidgets github release page. Make sure you have dlls version matched with your compiler
WXWIDGETS_LIB_PATH = -L$(WXWIDGETS_ROOT)/lib/gcc810_dll

BUILD_PATH = ./build
# -mwindows will hide console appearing behind GUI
LINKER_FLAGS = -mwindows
TARGET =	wxMain.exe
OBJS = wxMain.o Converter.o MainFrame.o
TARGET_DEPENDCIES = $(addprefix $(BUILD_PATH)/,$(OBJS) )

$(BUILD_PATH)/$(TARGET):	$(TARGET_DEPENDCIES)
	$(CXX) $? -o $@  $(WXWIDGETS_INCLUDE) $(WXWIDGETS_LIB_PATH) $(WXWIDGETS_LIBS) $(LINKER_FLAGS)
	
$(BUILD_PATH)/%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(WXWIDGETS_INCLUDE)
	
$(BUILD_PATH)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $? -o $@ $(WXWIDGETS_INCLUDE)


all:	$(BUILD_PATH)/$(TARGET)

clean:
	$(RM) $(BUILD_PATH)/*.o $(BUILD_PATH)/*.exe
