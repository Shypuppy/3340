# Compiler settings - Can change the compiler and the optimization level
CXX = g++
CXXFLAGS = -Wall -O2

# Part a) settings
ASN1A_SOURCES = asn1_a.cc
ASN1A_OBJECTS = $(ASN1A_SOURCES:.cpp=.o)
ASN1A_EXECUTABLE = asn1_a

# Part b) settings
ASN1B_SOURCES = asn1_b.cc
ASN1B_OBJECTS = $(ASN1B_SOURCES:.cpp=.o)
ASN1B_EXECUTABLE = asn1_b

.PHONY: all clean

all: $(ASN1A_EXECUTABLE) $(ASN1B_EXECUTABLE)

$(ASN1A_EXECUTABLE): $(ASN1A_OBJECTS)
	$(CXX) $(CXXFLAGS) $(ASN1A_OBJECTS) -o $@

$(ASN1B_EXECUTABLE): $(ASN1B_OBJECTS)
	$(CXX) $(CXXFLAGS) $(ASN1B_OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(ASN1A_OBJECTS) $(ASN1B_OBJECTS) $(ASN1A_EXECUTABLE) $(ASN1B_EXECUTABLE)

# Custom commands
asn1_a: $(ASN1A_EXECUTABLE)

asn1_b: $(ASN1B_EXECUTABLE)
