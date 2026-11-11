#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int check(char x,char y)
{
    if(x=='A'&&y=='B')return 2;
    if(x=='A'&&y=='C')return 1;
    if(x=='B'&&y=='A')return 2;
    if(x=='B'&&y=='C')return 2;
    if(x=='C'&&y=='A')return 1;
    if(x=='C'&&y=='B')return 2;
    if(x=='D'&&y=='F')return 2;
    if(x=='F'&&y=='D')return 2;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,a,b;
    char c,d;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    a=(s1[0]-'0')*10+s1[1]-'0';
    b=(s2[0]-'0')*10+s2[1]-'0';
    c=s1[2];
    d=s2[2];
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(c1==c2&&a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(c1==c2&&a==b&&check(c,d))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(c1==c2&&a==b&&check(c,d)==2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
