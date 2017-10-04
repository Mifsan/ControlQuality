// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static const int ARGUMENTS_COUNT = 4;

using namespace std;

bool IsEqual(const double x, const double y);
bool IsMore(const double x, const double y);
bool IsValidArgument(const char* argv);
bool IsValidArgumentsCount(const int & argc);
string TypeOfTriangle(const double a, const double b, const double c);

int main(int argc, char* argv[])
{
	if (!IsValidArgumentsCount(argc))
	{
		cout << "triangle.exe using: <a> <b> <c>" << endl;
		return 1;
	}

	for (size_t i = 1; i < ARGUMENTS_COUNT; ++i)
	{
		if (!IsValidArgument(argv[i]))
		{
			cout << "Invalid argument, argument should be <positive double number>" << endl;
			return 1;
		}
	}
	string arg1 = regex_replace(argv[1], regex(","), ".");
	string arg2 = regex_replace(argv[2], regex(","), ".");
	string arg3 = regex_replace(argv[3], regex(","), ".");
	double a = stod(arg1);
	double b = stod(arg2);
	double c = stod(arg3);
	cout << TypeOfTriangle(a, b, c) << endl;

	return 0;
}

bool IsEqual(const double x, const double y)
{
	return fabs(x - y) < FLT_EPSILON;
}

bool IsMore(const double x, const double y)
{
	return (!IsEqual(x, y) && x > y);
}

string TypeOfTriangle(const double a, const double b, const double c)
{
	if (!((IsMore(a + b, c)) && (IsMore(a + c, b)) && IsMore(b + c, a)))
	{
		return "Not a triangle";
	}
	else if ((IsEqual(a, b)) && IsEqual(b, c))
	{
		return "Equilateral triangle";
	}
	else if (IsEqual(a, b) || IsEqual(b, c) || IsEqual(a, c))
	{
		return "Isosceles triangle";
	}
	else
	{
		return "Common triangle";
	}
}

bool IsValidArgumentsCount(const int & argc)
{
	return (argc == ARGUMENTS_COUNT);
}

bool IsValidArgument(const char* argv)
{
	try
	{
		string checkStr = regex_replace(argv, regex(","), ".");
		double checkTransforming = stod(checkStr);
		if (checkTransforming <= 0)
		{
			return false;
		}
		return true;
	}
	catch (exception const& e)
	{
		cout << e.what() << endl;
		return false;
	}
}

