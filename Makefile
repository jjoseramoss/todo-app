CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(wildcard $(INCLUDE_DIR)/*.h)

MAIN_SRCS = $(filter-out $(SRC_DIR)/test_main.cpp, $(SRCS))
MAIN_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(MAIN_SRCS))

TEST_SRCS = $(SRC_DIR)/test_main.cpp $(filter-out $(SRC_DIR)/main.cpp, $(MAIN_SRCS))
TEST_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRCS))

MAIN_TARGET = main_app
TEST_TARGET = test_main

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJS) -o $@

$(TEST_TARGET): $(filter-out $(OBJ_DIR)/main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) -o $@

.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(MAIN_TARGET) $(TEST_TARGET)

.PHONY: run_main
run_main: $(MAIN_TARGET)
	./$(MAIN_TARGET)

.PHONY: run_test
run_test: $(TEST_TARGET)
	./$(TEST_TARGET)