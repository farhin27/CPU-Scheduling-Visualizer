# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SOURCES = Process_Scheduling/proc_sched_driver.cpp \
		  Process_Scheduling/FCFS.cpp \
		  Process_Scheduling/LJF.cpp \
		  Process_Scheduling/LRTF.cpp \
		  Process_Scheduling/Priority_non.cpp \
		  Process_Scheduling/Priority.cpp \
		  Process_Scheduling/RR.cpp \
		  Process_Scheduling/SJF.cpp \
		  Process_Scheduling/SRTF.cpp \
		  Process_Scheduling/utilities.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXECUTABLE = cpu_scheduling_visualizer

# Compile and link
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
