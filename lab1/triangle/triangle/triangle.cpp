// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static const int ARGUMENTS_COUNT = 4;

using namespace std;

bool IsValidArgument(const char* argv);
bool IsValidArgumentsCount(const int & argc);
string TypeOfTriangle(const float a, const float b, const float c);

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
			cout << "Invalid argument, argument should be <positive float number>" << endl;
			return 1;
		}
	}

	float a = stof(argv[1]);
	float b = stof(argv[2]);
	float c = stof(argv[3]);

	cout << TypeOfTriangle(a, b, c) << endl;

	return 0;
}

string TypeOfTriangle(const float a, const float b, const float c)
{
	if (!((a + b > c) && (a + c > b) && (b + c > a)))
	{
		return "Not a triangle";
	}
	else if ((a == b) && (b == c))
	{
		return "Equilateral triangle";
	}
	else if ((a == b) || (b == c) || (a == c))
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
		string checkStr = argv;
		regex_replace(checkStr, regex(","), ".");
		float checkTransforming = stoi(argv);
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

