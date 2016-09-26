// Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "..\Library\Library.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	ifstream f;
	short inw;
	long i;
	short mode = -1;
	long r = 0, n = 0;
	long bsize = 1024;
	char *fname;
	char buf[1024];
	for (i = 0; i<1024; i++)buf[i] = 0;

	if (argc == 3) {
		if (argv[1][0] == '-') {
			switch (argv[1][1]) {
			case 'c':mode = 0; break; //bytes
			case 'l':mode = 1; break; //lines
			case 'w':mode = 2; break; //words
			case 'a':mode = 3; break; //alpha
			default:
				std::cout << "nespravne argumenty\n\n";
				return -1;
			}
			fname = argv[2];
		}
		else {
			std::cout << "nespravne argumenty\n\n";
			return -1;
		}
	}
	else {
		std::cout << "nespravne argumenty\n\n";
		return -1;
	}

	f.open(fname, ios::in);
	if (!f) {
		cout << "chyba otvarania\n";
		return -1;
	}

	do {
		f.read(buf, bsize);
		r = f.gcount();
		switch (mode) {

		case 0: n += r; break;
		case 1: for (i = 0; i<r; i++)if (buf[i] == '\n')n++; break;
		case 2: for (i = 0; i<r; i++)
			if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z'))inw = 1;
			else { if (inw) { n++; inw = 0; } }
			break;
		case 3: for (i = 0; i<r; i++)
			if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z'))n++; break;

		}
	} while (r>0);

	switch (mode) {

	case 0: std::cout << "subor " << fname << " ma " << n << " bytov\n\n"; break;
	case 1: std::cout << "subor " << fname << " ma " << n + 1 << " riadkov\n\n"; break;
	case 2: std::cout << "subor " << fname << " ma " << n << " slov\n\n"; break;
	case 3: std::cout << "subor " << fname << " ma " << n << " alfanum znakov\n\n"; break;

	}

	f.close();
	cout << "\n";
	return 0;
}