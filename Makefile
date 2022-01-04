PROJECT     = Payload

ARCH        = Win32
#ARCH       = Win64

CMAKE       = cmake.exe
TOOLCHAIN   = 
CMAKE_FLAGS = 

BUILD       = build
SOURCE      = source
INCLUDE     = include

SOURCES     = $(wildcard $(SOURCE)/*.c)
OBJECTS     = $(patsubst $(SOURCE)/%.c,$(BUILD)/CMakeFiles/$(PROJECT).dir/$(SOURCE)/%.c.o,$(SOURCES))

all: $(PROJECT)
$(PROJECT): release debug

release: CMakeLists.txt
	$(CMAKE) --build $(BUILD) --config Release

debug: CMakeLists.txt
	$(CMAKE) --build $(BUILD) --config Debug

.PHONY: $(OBJECTS)
CMakeLists.txt: $(OBJECTS)
	$(CMAKE) -B $(BUILD) -A $(ARCH)

clean:
	rm -fr bin/*
	rm -fr build/*

extra-clean:
	rm -fr bin
	rm -fr build
