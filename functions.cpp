#include <iostream>
#include <fstream>
#include "functions.h"

CRat *CreateData(ifstream &input, std::map<string,CRatFactory*>  f){
    string I;
    int d = 2;
    string filename;
    CRat *rat = NULL;
    input >> I;
    input >> filename;
    input >> d;
    rat = f[I]->create_dat(d);
    for(int j = 0; j < d*2; j++){
        input >> rat->data[j];
        if(j%2 == 1 && rat->data[j]== 0){
            cout <<"Warning! You try to divide by zero!";
        }
    }
    rat->dim = d;
    rat->outfile = filename;

    return rat;
}

void test1(){//оператор присваивания
    CRat0 k(2);
    for(int i = 0; i < 4; i++)
    k.data[i] = i;
    CRat0 p(2);
    p = k;
    k.data[1] = 20;
    if(p.data[1] == 1){
       cout<< "Test 1 passed saccessfully"<<endl;
    }
}

void test2(){// оператор сложения
    CRat0 k(2);
    for(int i = 0; i < 4; i++)
    k.data[i] = i;
    CRat0 p(2);
    p = k + k;
    if(p.data[1] == 2){
       cout<< "Test 2 passed saccessfully"<<endl;
    }
}

void test3(){// оператор скалярного умножения
    CRat1 k(2);
    double p = 0;
    for(int i = 0; i < 4; i++)
        k.data[i] = i+1;
    k.data[2] = 4;
    p = k*k;
    if(p == 1.25){
       cout<< "Test 3 passed saccessfully"<<endl;
    }
}

void test4(){//конструктор копирования
    CRat0 k(2);
    for(int i = 0; i < 4; i++)
    k.data[i] = i;
    CRat0 p = k;
    k.data[1] = 20;
    if(p.data[1] == 1){
       cout<< "Test 4 passed saccessfully"<<endl;
    }
}
