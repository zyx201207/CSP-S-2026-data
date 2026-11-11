#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    string h1=s1.substr(0,2),h2=s2.substr(0,2);
    char t1=s1[2],t2=s2[2];
    bool f1=(a==b),f2=(h1==h2&&f1),f3=(((t1<='C'&&t2<='C')||(t1>'C'&&t2>'C'))&&f2),f4=((abs((int)(t1-t2))==1&&(!((t1=='C'&&t2=='D')||(t1=='D'&&t2=='C'))))&&f2);
    cout<<f1<<f2<<f3<<f4<<endl;
    return 0;
}