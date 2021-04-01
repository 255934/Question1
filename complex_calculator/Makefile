

#Makefile to execute a complex calculator using structures


PROJECT = compcalc

SRC = src/complex_calculator.c


TEST = test/test_compcalc.c\
unity/unity.c

INC =  -Iinc\
-Iunity

$(PROJECT):all

.PHONY: run clean test doc all cover size sani

sani: $(SRC) $(TEST)
	gcc $(INC) $(TEST) $(SRC) -o $(PROJECT).out -fsanitize=address -g

size: $(SRC) $(TEST)
	gcc $(INC) $(TEST) $(SRC) -o $(PROJECT).out
	size ./$(PROJECT).out

cover: $(SRC) $(TEST)
	gcc -fprofile-arcs -ftest-coverage $(INC) $(SRC) $(TEST) -o $(PROJECT).out
	./$(PROJECT).out

all:$(SRC) $(TEST)
	gcc $(INC) $(TEST) $(SRC) -o $(PROJECT).out
	
test:$(SRC) $(TEST)
	gcc $(INC) $(TEST) $(SRC) -o $(PROJECT).out 
	./$(PROJECT).out

run: $(PROJECT)
	./$(PROJECT).out

clean:
	rm $(PROJECT).out
