#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
CRat1::CRat1(const CRat1 &other){// êîíñòðóêòîð êîïèðîâàíèÿ
    this->dim = other.dim;
    for(int i = 0; i < dim; i++){
        this->data.push_back(other.data[i]);
    }
}
CRat1::CRat1::CRat1(int d){
    dim = d;
    data.resize(dim*2,0);
}
CRat1::CRat1(){
    dim = 2;
    cout << "Enter the dimension: ";
    cin >> dim;
     data.resize(dim*2,0);
}

double CRat1::operator * (const CRat &B){
        double ch = 0, zn = 0, p = 0;
        for(int i = 0; i< this->dim*2;i+=2){
            ch = (double)(this->data[i]*B.data[i]);
            zn = (double)(this->data[i+1]*B.data[i+1]);
            p = p + (ch/zn);
        }
        return p;
}
CRat1::~CRat1(){
}
int CRat1::output()
{
    ofstream fout(outfile.c_str(), ios_base::app);
    for(int i = 0; i < dim*2; i++){
        fout<<"X"<<i/2<<" = ";
        fout<<data[i]<<"/"<<data[i+1]<<"\n";// Âûâîäèì äàííû â ñòîëáåö
        i = i+1;
    }
fout.close();
return 0;
}
