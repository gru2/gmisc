#include <Sutf.h>

using namespace std;

int foo(int x)
{
	return x + 1;
}

int bar(int x)
{
	return x + x;
}

SUTF_REGISTER_TEST(testFoo)
{
	Sutf::test(foo(4) == 5);
}

SUTF_REGISTER_TEST(testBar)
{
	Sutf::test(bar(4) == 8);
	Sutf::test(bar(7) == 13, "testing bar.");
}

int main(int argc, char *argv[])
{
	Sutf::runTests(argc, argv);
}
