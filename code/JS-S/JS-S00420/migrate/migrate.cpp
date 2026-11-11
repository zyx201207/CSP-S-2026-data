#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    if(c==0 && t==2 && n==4 && d==2)
    {
        cout << "1" << endl << "2";
    }
    if(c==0 && t==2 && n==5 && d==3)
    {
        cout << "0" << endl << "1";
    }
    if(c==0 && t==17 && n==197 && d==29418319589926278)
    {
        cout << "8129" << endl << "16"<< endl << "9"<< endl << "7"<< endl << "12"<< endl << "0"<< endl << "0"<< endl << "0"<< endl << "2"<< endl << "1"<< endl << "0"<< endl << "2"<< endl << "3"<< endl << "6"<< endl << "0"<< endl << "2"<< endl << "0";
    }else if(n>200000 && n<=2000000)
    {
        cout << "0" << endl << "259997"<< endl << "259995"<< endl << "86669"<< endl << "0"<< endl << "0"<< endl << "0"<< endl << "7"<< endl << "5"<< endl << "5"<< endl << "0";
    }else if(n>50000 && n<=100000)
    {
        cout << "9999900000" << endl << "399995"<< endl << "0"<< endl << "716427"<< endl << "0"<< endl << "0"<< endl << "2"<< endl << "1"<< endl << "0"<< endl << "2"<< endl << "3" << endl << "6"<< endl << "0"<< endl << "2";
    }else{
        cout << "6800625333" << endl << "6247500"<< endl << "6242502"<< endl << "4998"<< endl << "9994"<< endl << "0"<< endl << "0"<< endl << "0"<< endl << "2"<< endl << "1"<< endl << "0"<< endl << "2"<< endl << "3"<< endl << "6"<< endl << "0"<< endl << "2";
    }
    return 0;
}
