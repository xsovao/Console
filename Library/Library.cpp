// Library.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Library.h"
//#include <windows.h>
#include <iostream>
//#include <tchar.h>


//// This is an example of an exported variable
//LIBRARY_API int nLibrary=0;
//
//// This is an example of an exported function.
//LIBRARY_API int fnLibrary(void)
//{
//    return 42;
//}
//
//// This is the constructor of a class that has been exported.
//// see Library.h for the class definition
//CLibrary::CLibrary()
//{
//    return;
//}


int countf(std::istream &is, Readmode mode) {

	short inw = 0;
	long i;
	long r = 0, n = 0;
	char buf[bsize] = { 0, };

	is.seekg(0, is.beg);

	do {
		is.read(buf, bsize);
		r = is.gcount();
		switch (mode) {

		case bytes: n += r; break;
		case lines: for (i = 0; i<r; i++)if (buf[i] == '\n')n++; break;
		case words: for (i = 0; i<r; i++)
			if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z'))inw = 1;
			else { if (inw==1) n++; inw = 0; }
			break;
		case alphas: for (i = 0; i<r; i++)
			if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z'))n++; break;

		}
	} while (r>0);

	switch (mode) {

	case words: if (inw) n++; return n;
	case bytes:
	case alphas:
		return n;
	case lines: return n + 1;
	}

}
