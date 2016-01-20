#include <Options.h>
#include <ErrorReporter.h>
#include <iostream>
#include <stdlib.h>

Options::Options()
{
	errorReporter = 0;
}

Options::~Options() { }

void Options::addOption(const std::string &name, const std::string &longName,
	bool mandatory, bool hasArgument, const std::string &defaultValue)
{
	Option o;
	o.name = name;
	o.longName = longName;
	o.manadory = mandatory;
	o.hasArgument = hasArgument;
	o.value = defaultValue;
	o.present = false;
	options.push_back(o);
}

void Options::processArgs(int argc, char **argv)
{
	std::vector<std::string> args;
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		args.push_back(arg);
	}
	processArgs(args);
	return;
}

void Options::processArgs(const std::vector<std::string> &args)
{
	int argc = (int)args.size();
	int i = 0;
	for (;;)
	{
		if (i >= argc)
			break;

		const std::string &arg = args[i];
		if ((int)arg.size() > 0 && arg[0] == '-')
		{
			Option *opt = findOption(arg);
			if (opt)
			{
				opt->present = true;
				if (opt->hasArgument)
				{
					i++;
					if (i >= argc)
					{
						error("option '" + arg + "' must have argument");
						continue;
					}
					opt->value = args[i];
				}
			}
			else
				error("unknown option '" + arg + "'");
		}
		else
		{
			files.push_back(arg);
		}
		i++;
	}

	// chek for mandatory arguments;
	for (i = 0; i < (int)options.size(); i++)
	{
		Option &opt = options[i];
		if ((!opt.present) && opt.manadory)
		{
			error("mandatory option '" + opt.name + "' not present");
		}
	}
}

Option *Options::findOption(const std::string &name)
{
	int i;
	for (i = 0; i < (int)options.size(); i++)
	{
		Option &opt = options[i];
		if (opt.name == name || opt.longName == name)
		{
			return &opt;
		}
	}
	return 0;
}

std::string Options::findOptionValue(const std::string &name)
{
	Option *opt = findOption(name);
	if (opt == 0)
		return "";
	return opt->value;
}

void Options::error(const std::string &msg)
{
	if (errorReporter)
		errorReporter->error(msg);
	else
	{
		std::cout << "ERROR:" + msg + "\n";
		exit(1);
	}
}
