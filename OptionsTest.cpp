#include <Options.h>
#include <iostream>

int main()
{
	Options opts;
	opts.addOption("-l", "", false, true, "lArg");
	opts.addOption("-m", "--mand", false, false, "mArg");
	std::vector<std::string> args;
	args.push_back("-l");
	args.push_back("lArg2");
	args.push_back("-m");
	args.push_back("file_1");
 
	opts.processArgs(args);

 	std::cout << "-l value = "  << opts.findOptionValue("-l") << "\n";
	std::cout << "files:\n";
	int i;
	for (i = 0; i < (int)opts.getFiles().size(); i++)
	{
		std::cout << "\t" << opts.getFiles()[i] << "\n";
	}
	std::cout << "TEST_PASSED\n";
	return 0;
}
