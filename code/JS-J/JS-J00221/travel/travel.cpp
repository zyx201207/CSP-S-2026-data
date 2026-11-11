#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int cxx,c2xx;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]=='1')
    {
        cxx+=10;
    }
    if(c1[1]=='1')
    {
        cxx+=1;
    }
    else if(c1[1]=='2')
    {
        cxx+=2;
    }
    else if(c1[1]=='3')
    {
        cxx+=3;
    }
    else if(c1[1]=='4')
    {
        cxx+=4;
    }
    else if(c1[1]=='5')
    {
        cxx+=5;
    }
    else if(c1[1]=='6')
    {
        cxx+=6;
    }
    else if(c1[1]=='7')
    {
        cxx+=7;
    }
    else if(c1[1]=='8')
    {
        cxx+=8;
    }
    else if(c1[1]=='9')
    {
        cxx+=9;
    }
    if(c2[0]=='1')
    {
        c2xx+=10;
    }
    if(c2[1]=='1')
    {
        c2xx+=1;
    }
    else if(c2[1]=='2')
    {
        c2xx+=2;
    }
    else if(c2[1]=='3')
    {
        c2xx+=3;
    }
    else if(c2[1]=='4')
    {
        c2xx+=4;
    }
    else if(c2[1]=='5')
    {
        c2xx+=5;
    }
    else if(c2[1]=='6')
    {
        c2xx+=6;
    }
    else if(c2[1]=='7')
    {
        c2xx+=7;
    }
    else if(c2[1]=='8')
    {
        c2xx+=8;
    }
    else if(c2[1]=='9')
    {
        c2xx+=9;
    }
    if(cxx!=c2xx)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<"1000"<<endl;
        return 0;
    }
    char sxxx=s1[2];
    char s2xx=s2[2];
    if((sxxx=='D'&&s2xx!='F')||(sxxx=='F'&&s2xx!='D')||(sxxx=='A'&&s2xx!='B'&&s2xx!='C')||(sxxx=='B'&&s2xx!='A'&&s2xx!='C')||(sxxx=='C'&&s2xx!='B'&&s2xx!='A'))
    {
        cout<<"1100"<<endl;
        return 0;
    }
    if(sxxx==s2xx-1||sxxx==s2xx+1)
    {
        cout<<"1111"<<endl;
        return 0;
    }
    else
    {
        cout<<"1110"<<endl;
        return 0;
    }


}
