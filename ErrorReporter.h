#ifndef __ERROR_REPORTER_H
#define __ERROR_REPORTER_H

#include <string>

class SourceCodePosition;

class ErrorReporter
{
public:
	ErrorReporter();
	~ErrorReporter();

	void error(const std::string &msg);

	SourceCodePosition *getSourceCodePosition() const { return sourceCodePosition; }
	void setSourceCodePosition(SourceCodePosition *x) { sourceCodePosition = x; }
protected:
	SourceCodePosition *sourceCodePosition;
};

#endif
