
#include <SourceCodePosition.h>

SourceCodePosition::SourceCodePosition()
{
	lineNumber = 0;
}

SourceCodePosition::~SourceCodePosition()
{
}

void SourceCodePosition::getChar(char c)
{
	if (c == '\n')
		lineNumber++;
}

void SourceCodePosition::putBackChar(char c)
{
	if (c == '\n')
		lineNumber--;
}
