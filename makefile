OPT_FLAGS = -g

CPPFLAGS = $(OPT_FLAGS) -I.

TARGETS = SutfTest OptionsTest

all: $(TARGETS)

SutfTest: SutfTest.o Sutf.o
	g++ -o SutfTest SutfTest.o Sutf.o

OptionsTest: OptionsTest.o Options.o ErrorReporter.o
	g++ -o OptionsTest OptionsTest.o Options.o ErrorReporter.o

%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

clean::
	-rm -vf $(TARGETS) *.o

