#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
CRat0::CRat0(const CRat0 &other){// êîíñòðóêòîð êîïèðîâàíèÿ
    this->dim = other.dim;
    for(int i = 0; i < dim*2; i++){
        this->data.push_back(other.data[i]);
    }
}
CRat0::CRat0(const CRat &other){// êîíñòðóêòîð êîïèðîâàíèÿ
    this->dim = other.dim;
    for(int i = 0; i < dim*2; i++){
        this->data.push_back(other.data[i]);
    }
}
CRat0::CRat0(int d){
    dim = d;
    data.resize(d*2,0);
}
CRat0::CRat0(){
    dim = 2;
    data.resize(dim*2,0);
}

CRat0::~CRat0(){}
double CRat0::operator * (const CRat &B){
        double ch = 0, zn = 0, p = 0;
        for(int i = 0; i< this->dim*2; i+=2){
            ch = (double)(this->data[i]*B.data[i]);
            zn = (double)(this->data[i+1]*B.data[i+1]);
            p += ch/zn;
        }
        return p;
}
int CRat0::output()
{
    ofstream fout(outfile.c_str(), ios_base::app);
    for(int i = 0; i < dim*2; i++){
        fout<<" X"<<i/2<<" = ";
        fout<<data[i]<<"/"<<data[i+1]<<" ";// Âûâîäèì äàííûå â ñòðîêó
        i = i+1;
    }
    return 0;
}
