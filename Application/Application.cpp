// Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "..\Library\Library.h"
#include <iostream>
#include <fstream>



using namespace std;
/*
enum Readmode {
	bytes, lines, words, alphas
};

int countf(istream &is, Readmode mode) {

	short inw;
	long i;
	long r = 0, n = 0;
	char buf[bsize] = { 0, };
	
	
	do {
		is.read(buf, bsize);
		r = is.gcount();
		switch (mode) {

		case bytes: n += r; break;
		case lines: for (i = 0; i<r; i++)if (buf[i] == '\n')n++; break;
		case words: for (i = 0; i<r; i++)
			if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z'))inw = 1;
			else { if (inw) { n++; inw = 0; } }
			break;
		case alphas: for (i = 0; i<r; i++)
			if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z'))n++; break;

		}
	} while (r>0);

	switch(mode){
	case bytes:
	case words:
	case alphas:
		cout << n; break;
	case lines: cout << n + 1;
	}

	cout << "\n";
	return 0;

}

*/

int main(int argc, char **argv)
{

	ifstream f;
	short inw;
	long i;
	Readmode mode;
	long r = 0, n = 0;
	char *fname;
	char buf[bsize] = {0,};
	//for (i = 0; i < 1024; i++)buf[i] = 0;


	switch (argc ) {
	case 3:
		if (argv[1][0] == '-') {
			switch (argv[1][1]) {
			case 'c':mode = bytes; break; //bytes
			case 'l':mode = lines; break; //lines
			case 'w':mode = words; break; //words
			case 'a':mode = alphas; break; //alpha
			default:
				std::cout << "nespravne argumenty\n\n";
				return -1;
			}

			f.open(fname, ios::in);
			if (!f) {
				cout << "chyba otvarania\n";
				return -1;
			}

			cout << countf(f,mode);

		}
		else {
			std::cout << "nespravne argumenty\n\n";
			return -1;
		}
		break;
	case 2:
		if (argv[1][0] == '-') {
			switch (argv[1][1]) {
			case 'c':mode = bytes; break; //bytes
			case 'l':mode = lines; break; //lines
			case 'w':mode = words; break; //words
			case 'a':mode = alphas; break; //alpha
			default:
				std::cout << "nespravne argumenty\n\n";
				return -1;
			}

			cout << countf(cin,mode);
		}
	default:
		std::cout << "nespravne argumenty\n\n";
		return -1;
	}
	return 0;
}