CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
INCDIR = .
LIBDIR = .
LDLIBS = -lverification

# Fichier a compiler + binaire de sortie (changeables via `make SRC=... TARGET=...`)
SRC = test.cpp
TARGET = prog

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -o $@ $(SRC) -L$(LIBDIR) $(LDLIBS) -Wl,-rpath,'$$ORIGIN:$(LIBDIR)'

# Reconstruction de la lib (optionnel, seulement si tu modifies verification.cpp)
libverification.so: verification.cpp
	$(CXX) $(CXXFLAGS) -fPIC -shared -o $@ $<

clean:
	rm -f $(TARGET) libverification.so

.PHONY: all clean
