#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int maxp = 100;
struct ptype
{
    string first, last;
    string dept;
    double salary;
};
const ptype initrec = {"firstname", "lastname", "dept", 0.0};
void initem(ptype p[], int &nump)
{
    int i;
    for (i=0; i<maxp; i++) p[i] = initrec;
    nump = 0;
}
void printem(ptype p[], int nump, ofstream &outf)
{
    int i;
    string dummy;
    for(i = 0; i<nump; i++)
    {
        dummy = p[i].last + ", " + p[i].first;
        outf << left << setw(25) << dummy << setw(20)<< p[i].dept << right
        << setw(12) << p[i].salary << endl;
    }
}
void getaverage(ptype p[], int nump, ofstream &outf)
{
    int i;
    double average=0;
    for (i=0; i<nump; i++) average += p[i].salary;
    average /= nump;
    outf << "\n\nThe average salary is "<< average << endl << endl;
}
void swapem(ptype &a, ptype &b)
{
    ptype temp;
    temp = a;
    a = b;
    b = temp;
}
void sortem(ptype p[], int nump)
{
    int i, j;
    for (j=0; j<nump-1; j++)
        for (i=0; i<nump-1; i++)
            if (p[i].dept > p[i+1].dept) swapem(p[i],p[i+1]);
}void readem(ptype p[], int &nump)
{
    int i;
    ifstream inf("demo1.dat");
    i = 0;
    while (!inf.eof())
    {
        getline(inf,p[i].first,'|');
        getline(inf,p[i].last,'|');
        getline(inf, p[i].dept,'|');
        inf>> p[i].salary >> ws;
        i++;
    }
    nump = i;
}
void main()
{
    ptype p[maxp];
    int nump;
    ofstream outf("demo1.out");
    outf.setf(ios::fixed);
    outf.precision(2);
    initem(p, nump);
    readem(p, nump);
    printem(p, nump,outf);
    getaverage(p, nump, outf);
    sortem(p,nump);
    printem(p, nump,outf);
    system("pause");
}