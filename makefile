CXX = g++
CXXFLAGS = -std=c++17

SOURCES = main.cpp \
          Expression/expression.cpp \
          Expression/binary_expression.cpp \
          Expression/unary_expression.cpp \
          Operators/operators.cpp \
          Literal/literal.cpp \
          Parser/parser.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXEC = expreval

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS) $(EXEC)
