
# Include general environment variables
include ../../env

# Location of general helper files
INC_DIR=../../include

# List of applications to target
TARGETS=repeater_answer.exe

# Override some flags
CXXFLAGS=-g -std=c++11 -O0

all: $(TARGETS)

# General compilation step
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -I$(BASE_INC_DIR) -I$(INC_DIR) -L$(BASE_LIB_DIR) $<\
		-o $@ $(BASE_LIB_FLAGS)

# Clean step
clean:
	rm -r *.exe


.EXPORT_ALL_VARIABLES:
