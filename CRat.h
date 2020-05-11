#include<fstream>
#include<iostream>
#include<vector>

using namespace std;
class CRat;
class CRat0;
class CRat1;

class CRat{//базовый класс, который хранит данныйе для одного вектора
protected:
public:
   int dim;
   vector<int> data;
   string outfile;
   CRat(){}
   void show();
   virtual ~CRat(){}
   virtual int output()=0;
};

class CRat0 : public CRat{
private:

public:
    CRat0(const CRat0 &other);// конструктор копирования
    CRat0(int d);
    CRat0();
    void operator = (const CRat0 &other);
    CRat0 operator+ (const CRat0 &B);
    CRat0 operator- (const CRat0 &B);
    ~CRat0();
    double operator* (const CRat0 &B);//Скалярное умножение
    int output();
};

class CRat1 : public CRat{
private:

public:
    CRat1(const CRat1 &other);// конструктор копирования
    CRat1(int d);
    CRat1();
    void operator = (const CRat1 &other);
    CRat1 operator+ (const CRat1 &B);
    CRat1 operator- (const CRat1 &B);
    ~CRat1();
    double operator* (const CRat1 &B);//Скалярное умножение
    int output();
};

