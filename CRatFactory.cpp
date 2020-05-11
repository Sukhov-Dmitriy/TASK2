#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

CRat* CRatFactory0::create_dat(int d)
{
    return new CRat0(d);
}
CRat* CRatFactory1::create_dat(int d)
{
    return new CRat1(d);
}
