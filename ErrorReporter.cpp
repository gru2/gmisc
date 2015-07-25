#include <ErrorReporter.h>
#include <iostream>
#include <stdlib.h>

ErrorReporter::ErrorReporter()
{
	sourceCodePosition = 0;
}

ErrorReporter::~ErrorReporter()
{
}

void ErrorReporter::error(const std::string &msg)
{
	std::cout << "error:" << msg << std::endl;
	exit(1);
}
