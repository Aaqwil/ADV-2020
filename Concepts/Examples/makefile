CXX = g++-10
EXEC = test
CXXFLAGS += -pedantic -Wall -MMD -MP -std=c++2a
LFLAGS = -lm -pthread -fconcepts-diagnostics-depth=2

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

$(EXEC): $(OBJ) 
	$(CXX) $^ -o $@ $(LFLAGS)

.PHONY: clean

clean:
	@rm -f $(EXEC) $(OBJ) $(DEP)

-include $(DEP)
