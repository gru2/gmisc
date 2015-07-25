#include <InputStream.h>
#include <SourceCodePosition.h>
#include <ErrorReporter.h>
#include <stdio.h>
#include <assert.h>

InputStream::InputStream()
{
	position = 0;
	sourceCodePosition = 0;
}

InputStream::~InputStream()
{
}

void InputStream::openFile(const std::string &fileName)
{
	FILE *file = fopen(fileName.c_str(), "r");
	if (file == 0)
	{
		error("Unable to open file '" + fileName + "'");
		return;
	}
	fseek(file, 0, SEEK_END);
	unsigned length = ftell(file);
	buffer.resize(length);
	fseek(file, 0, SEEK_SET);
	fread(&buffer[0], length, 1, file);
	fclose(file);
}

void InputStream::openString(const std::string &s)
{
	unsigned len = s.size();
	buffer.resize(len);
	for (unsigned i = 0; i < len; i++)
		buffer[i] = s[i];
}

char InputStream::getChar()
{
	if (position >= 0 && position < (int)buffer.size())
	{
		char c = buffer[position];
		if (sourceCodePosition)
			sourceCodePosition->getChar(c);
		position++;
		return c;
	}
	position++;
	return 0;
}

void InputStream::putBackChar()
{
	position--;
	if (position >= 0 && position < (int)buffer.size())
	{
		char c = buffer[position];
		if (sourceCodePosition)
			sourceCodePosition->putBackChar(c);
	}
}

void InputStream::putBackChars(int count)
{
	for (int i = 0; i < count; i++)
		putBackChar();
}

bool InputStream::isEof()
{
	if (position >= (int)buffer.size())
		return true;
	return false;
}

void InputStream::setPosition(int x)
{
	if (x >= position)
	{
		for (int i = position; i < x; i++)
			getChar();
	}
	for (int i = x; i < position; i++)
		putBackChar();
}

void InputStream::error(const std::string &msg)
{
	assert(errorReporter);
	errorReporter->error(msg);
}
