CC=gcc
CFLAG=-c 
CFLAGS=-Wall -Werror -Wextra -std=c11
SRC_DIR=backend
BACK_SRC=s21_smart_calc/alg.c
TEST=s21_smart_calc/unit_test.c
OS := $(shell uname)

ifeq ($(OS),Linux)
TEST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
TEST_LIBS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: clean install dvi

install: clean
	cd s21_smart_calc && cmake CMakeLists.txt && make && rm Makefile && mv s21_smart_calc.app ../s21_SC.app

uninstall:
	rm -rf s21_SC.app

dvi:
	@open s21_smart_calc/README.html

test: clean
	$(CC) $(CFLAGS) $(TEST) $(BACK_SRC) $(TEST_LIBS) -o s21_smart_calc/unit_test
	cd s21_smart_calc && ./unit_test

gcov_report:
	$(CC) $(CFLAGS) --coverage $(TEST) $(BACK_SRC) $(STACS_SRC) $(NAME) $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

dist: install
	rm -rf Archive_calc/
	mkdir Archive_calc/
	mv s21_SC.app Archive_calc
	tar -cvzf Archive_calc.tar.gz Archive_calc

format:
	clang-format -style=Google -n s21_smart_calc/*.c s21_smart_calc/*.h s21_smart_calc/*.cpp

clean:
	@rm -rf *.o
	@rm -rf *.gcda *.gcno *.info
	@rm -rf gcov_report
	@rm -rf gcov_test
	@rm -rf report
	@rm -rf s21_smart_calc/unit_test
	@rm -rf build/
	@rm -rf s21_SC.app
	@rm -rf s21_smart_calc/s21_smart_calc_autogen
	@rm -rf s21_smart_calc/CMakeFiles
	@rm -rf s21_smart_calc/CMakeCache.txt
	@rm -rf s21_smart_calc/cmake_install.cmake
	@rm -rf Archive_calc
	@rm -rf dist-newstyle/


.PHONY: all install uninstall dvi test gcov_report dist format check clean