#ifndef __INPUT_STREAM_H
#define __INPUT_STREAM_H

#include <vector>
#include <string>

class SourceCodePosition;
class ErrorReporter;

class InputStream
{
public:
	InputStream();
	~InputStream();

	void openFile(const std::string &file);
	void openString(const std::string &file);

	char getChar();
	void putBackChar();
	void putBackChars(int count);
	char lookAhead(int n);
	bool isEof();
	int getPosition() { return position; }
	void setPosition(int x);
	void error(const std::string &msg);

	SourceCodePosition *getSourceCodePosition() const
		{ return sourceCodePosition; }
	void setSourceCodePosition(SourceCodePosition *x)
		{ sourceCodePosition = x; }
	ErrorReporter *getErrorReporter() const { return errorReporter; }
	void setErrorReporter(ErrorReporter *x) { errorReporter = x; }
protected:
	std::vector<char> buffer;
	int position;
	SourceCodePosition *sourceCodePosition;
	ErrorReporter *errorReporter;
};

#endif
