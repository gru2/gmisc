#ifndef __SOURCE_CODE_POSITION_H
#define __SOURCE_CODE_POSITION_H

#include <string>

class SourceCodePosition
{
public:
	SourceCodePosition();
	~SourceCodePosition();

	std::string getUnitName() const { return unitName; }
	void setUnitName(std::string &x) { unitName = x; }
	int getLineNumber() const { return lineNumber; }
	void setLineNumber(int x) { lineNumber = x; }

	void getChar(char c);
	void putBackChar(char c);
protected:
	std::string unitName;
	int lineNumber;
};

#endif
