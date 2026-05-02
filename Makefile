CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET   = taylor
OBJS     = main.o print.o

.PHONY: build run clean rebuild

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Compilacion exitosa -> ./$(TARGET)"

main.o: main.cpp print.h
	$(CXX) $(CXXFLAGS) -c main.cpp

print.o: print.cpp print.h
	$(CXX) $(CXXFLAGS) -c print.cpp

run: build
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean build