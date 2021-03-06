#include <Sutf.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace Sutf;

int failCount = 0;

Initializer *Initializer::tests = 0;

Initializer::Initializer(TestType x, const std::string &name)
{
	test = x;
	nextTest = tests;
	tests = this;
	testName = name;
}

Initializer *Initializer::getTests()
{
	return tests;
}

void Sutf::test(bool result)
{
	if (!result)
	{
		std::cout << "FAILED\n";
		failCount++;
	}
}

void Sutf::test(bool result, const std::string &msg)
{
	if (!result)
	{
		std::cout << "FAILED " + msg + "\n";
		failCount++;
	}
}

int Sutf::runTests(int argc, char *argv[])
{
	Sutf::Initializer *p = Sutf::Initializer::getTests();
	std::vector<Sutf::Initializer *> tests;
	for (;;)
	{
		if (!p)
			break;
		tests.push_back(p);
		p = p->getNextTest();
	}

	int n = (int)tests.size();
	for (int i = 0; i < n; i++)
	{
		p = tests[n - i - 1];
		int oldFailCount = failCount;
		TestType test = p->getTest();
		std::cout << "Running test " + p->getTestName() << "...\n";
		std::cout.flush();
		test();
		if (failCount == oldFailCount)
		{
			std::cout << "PASSED\n";
			std::cout.flush();
		}
		else
		{
			std::cout << "FAILED\n";
			std::cout.flush();
		}
	}

	std::cout << "Total fail count is " << failCount << ".\n";

	if (failCount == 0)
		return 0;

	return 1;
}
