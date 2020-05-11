#include<fstream>
#include<iostream>
#include "CRatFactory.h"
#include <map>

CRat *CreateData(ifstream &input, std::map<string,CRatFactory*> f);
void test1();
void test2();
void test3();
void test4();
