#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

void CRat::show(){
    for(int i = 0; i < this->dim*2; i++){
        cout << endl <<data[i]<< endl;
    }
}

CRat0::CRat0(const CRat0 &other){// конструктор копирования
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
void CRat0::operator = (const CRat0 &other){
    this->dim = other.dim;
    data.clear();
    for(int i = 0; i < dim*2; i++){
        this->data.push_back(other.data[i]);
    }
}
CRat0 CRat0::operator+ (const CRat0 &B){
        CRat0 rat(B.dim);
        for(int i = 0; i< this->dim*2;i++){
        rat.data[i] = this->data[i]+B.data[i];
        }
        rat.dim = B.dim;
        return rat;
}

CRat0 CRat0::operator- (const CRat0 &B){
        CRat0 rat(B.dim);
        for(int i = 0; i< this->dim*2;i++){
        rat.data[i] = this->data[i]-B.data[i];
        }
        rat.dim = B.dim;
        return rat;
}
CRat0::~CRat0(){}
double CRat0::operator* (const CRat0 &B){//скалярное умножение
        double ch = 0, zn = 0, p = 0;
        for(int i = 0; i< this->dim*2;i=+2){
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
        fout<<" X"<<i<<" = ";
        fout<<data[i]<<"/"<<data[i+1]<<" ";// Выводим данные в строку
        i = i+1;
    }
    return 0;
}
CRat1::CRat1(const CRat1 &other){// конструктор копирования
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
    data.resize(dim*2,0);
}
void CRat1::operator = (const CRat1 &other){
    this->dim = other.dim;
    data.clear();
    for(int i = 0; i < dim; i++){
        this->data.push_back(other.data[i]);
    }
}
CRat1 CRat1::operator+ (const CRat1 &B){
        CRat1 rat(B.dim);
        for(int i = 0; i< this->dim*2;i++){
        rat.data[i] = this->data[i]+B.data[i];
        }
        rat.dim = B.dim;
        return rat;
}
CRat1 CRat1::operator- (const CRat1 &B){
        CRat1 rat(B.dim);
        for(int i = 0; i< this->dim*2;i++){
        rat.data[i] = this->data[i]-B.data[i];
        }
        rat.dim = B.dim;
        return rat;
}
double CRat1::operator* (const CRat1 &B){//скалярное умножение
        double ch = 0, zn = 0, p = 0;
        for(int i = 0; i< this->dim*2;i++){
            ch = (double)(this->data[i]*B.data[i]);
            zn = (double)(this->data[i+1]*B.data[i+1]);
            p = p + (ch/zn);
            i= i+1;
        }
        return p;
}
CRat1::~CRat1(){}
int CRat1::output()
{
    ofstream fout(outfile.c_str(), ios_base::app);
    for(int i = 0; i < dim*2; i++){
        fout<<"X"<<i<<" = ";
        fout<<data[i]<<"/"<<data[i+1]<<"\n";// Выводим данны в столбец
        i = i+1;
    }
fout.close();
return 0;
}
