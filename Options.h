#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>
#include <vector>
#include <map>

class ErrorReporter;

struct Option
{
	std::string name;
	std::string longName;
	bool manadory;
	bool hasArgument;
	std::string value;
	bool present;
};

class Options
{
public:
	Options();
	~Options();

	void addOption(const std::string &name, const std::string &longName,
		bool mandatory, bool hasArgument, const std::string &defaultValue);
	void processArgs(int argc, char **argv);
	void processArgs(const std::vector<std::string> &args);
	Option *findOption(const std::string &name);
	std::string findOptionValue(const std::string &name);
	void error(const std::string &msg);

	std::vector<std::string> &getFiles() { return files; }

	ErrorReporter *getErrorReporter() { return errorReporter; }
	void setErrorReporter(ErrorReporter *x) { errorReporter = x; }
protected:
	std::vector<std::string> files;
	std::vector<Option> options;
	ErrorReporter *errorReporter;
};

#endif
