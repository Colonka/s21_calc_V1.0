CHECK_FLAGS = $(shell pkg-config --libs check --cflags)

CFLAGS = -Wall -Werror -Wextra -std=c11
CC = gcc
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

now:=$(shell date)
VERSION = `date +"%Y.%m.%d"`
ARCHIVE = s21_calc-$(VERSION)

PREF_BIN = ./binary/
PREF_SRC = ./source/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJS = $(patsubst $(PREF_SRC)%.c, $(PREF_BIN)%.o, $(SRC))

all: install

install: clean
	mkdir build
	cd s21_calc && cmake -S ./ -B ../build
	cd build && $(MAKE)

run:
	open -Fn build/s21_calc.app

uninstall: 
	rm -rf build
	rm -rf html
	rm -rf latex

dvi: 
	mkdir docs
	doxygen Doxyfile
	mv html latex docs
	open docs/html/index.html

docs:
	open docs/html/index.html

dist: clear install
	tar -cf $(ARCHIVE).tar build/*

s21_calc.a : $(OBJS)
	ar rc libs21_calc.a $(OBJS)
	ranlib libs21_calc.a

$(PREF_BIN)%.o : $(PREF_SRC)%.c $(PREF_SRC)s21_calc.h
	mkdir -p binary
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $@

test: clean s21_calc.a ./test/test.c 
	$(CC) $(FLAGS) $(CHECK_FLAGS) -c ./test/test.c
	$(CC) -L. -ls21_calc test.o $(GCOV_FLAGS) $(SRC) ${CHECK_FLAGS} -o run_tests
	./run_tests

gcov_report: test
	mkdir report
	./run_tests
	gcov -f *.gcno
	gcovr -r. --html --html-details -o report/report.html
	open ./report/report.html
	
git:
	git add -A
	git commit -m "$m"
	git push origin "$b"

style:
	clang-format -i -style=google *.c *.h s21_calc/*.cpp s21_calc/*.h
	clang-format -style=google -n *.c *.h s21_calc/*.cpp s21_calc/*.h

check: clean test
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h s21_calc/*.cpp s21_calc/*.h
	leaks --atExit -- ./run_tests

clean:
	rm -rf binary *.o *.gcov *.gcno *.gcda run_tests *.a report build *.bak *.tar s21_calc/*.user

		 