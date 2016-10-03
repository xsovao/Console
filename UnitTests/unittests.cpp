#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

#include "../Library/Library.h"

#include <vector>

namespace UnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_XGetOpt_fail)
		{
			optarg = nullptr;
			optind = 0;

			std::vector<char *> argv = { "appName", "-db", "param B", "-a", "-c", "-e", "param E", "--fail" };
			char * opts = "ab:cde:";

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == 'd', L"option -d");
			Assert::IsTrue(optarg == nullptr, L"option param -d");

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == 'b', L"option -b");
			Assert::AreEqual(argv[2], optarg, L"option param -b");

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == 'a', L"option -a");
			Assert::IsTrue(optarg == nullptr, L"option param -a");

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == 'c', L"option -c");
			Assert::IsTrue(optarg == nullptr, L"option param -c");

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == 'e', L"option -e");
			Assert::AreEqual(argv[6], optarg, L"option param -e");

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == '?', L"option --fail");
			Assert::IsTrue(optind == 8, L"--fail index");
		}

		TEST_METHOD(Test_XGetOpt_param)
		{
			optarg = nullptr;
			optind = 0;

			std::vector<char *> argv = { "appName", "-db", "param B", "-e", "param E", "param 1", "param 2" };
			char * opts = "ab:cde:";

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == 'd', L"option -d");
			Assert::IsTrue(optarg == nullptr, L"option param -d");

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == 'b', L"option -b");
			Assert::AreEqual(argv[2], optarg, L"option param -b");

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == 'e', L"option -e");
			Assert::AreEqual(argv[4], optarg, L"option param -e");

			Assert::IsTrue(getopt((int)argv.size(), &argv[0], opts) == EOF, L"last option");
			Assert::IsTrue(optind == 5, L"first param index");
		}

		TEST_METHOD(Test_wc)
		{

			ifstream ifs;
			int c;
			//TODO check test.txt externally.

			//TEST DOCUMENT atomovy zakon.txt
			// 25757 words
			// 185167 bytes
			// 3828 lines
			
			/*
			ifs.open("atomovy zakon.txt", ios::in);
			//Assert::IsFalse(ifs.badbit, L"open");
			c = countf(ifs, words);
			Assert::IsTrue(countf(ifs, words) == 25757, L"word count");
			c = countf(ifs, lines);
			Assert::IsTrue(countf(ifs, lines) == 3828, L"line count");
			c = countf(ifs, bytes);
			Assert::IsTrue(countf(ifs, bytes) == 185167, L"byte count");
			*/

			//TEST DOCUMENTempty.txt
			// 0 words
			// 0 bytes
			// 1 lines

			ifs.open("empty.txt", ios::in);
			Assert::IsTrue(countf(ifs, words) == 0, L"empty.txt word count");
			ifs.close();
			ifs.open("empty.txt", ios::in);
			Assert::IsTrue(countf(ifs, lines) == 1, L"empty.txt line count");
			ifs.close();
			ifs.open("empty.txt", ios::in);
			Assert::IsTrue(countf(ifs, bytes) == 0, L"empty.txt byte count");
			ifs.close();

			//TEST DOCUMENT ten.txt
			// 10 words
			// 48 bytes
			// 10 lines

			ifs.open("ten.txt", ios::in);
			//Assert::IsFalse(ifs.badbit, L"open");
			Assert::IsTrue(countf(ifs, words) == 10, L"ten.txt word count");
			ifs.close();
			ifs.open("ten.txt", ios::in);
			Assert::IsTrue(countf(ifs, lines) == 10, L"ten.txt line count");
			ifs.close();
			ifs.open("ten.txt", ios::in);
			Assert::IsTrue(countf(ifs, bytes) == 48, L"ten.txt byte count");
			ifs.close();


		}
	};
}