#include<bits/stdc++.h>
using namespace std;
bool f1(string x,string y)
{
    for(int i=0;i<2;i++)
        if(x[i]!=y[i])  return false;
    return true;
}
bool f2(string x,string y)
{
    if(x[3]<='B'&&y[3]<='B')    return true;
    if(x[3]>='C'&&y[3]>='C')    return true;
    return false;
}
bool f3(string x,string y)
{

    if(x[3]=='A'&&y[3]=='B')    return true;
    if(x[3]=='B'&&y[3]=='A')    return true;
    if(x[3]=='C'&&y[3]=='D')    return true;
    if(x[3]=='D'&&y[3]=='C')    return true;
    if(x[3]=='D'&&y[3]=='F')    return true;
    if(x[3]=='F'&&y[3]=='D')    return true;
    return false;
}
int main()
{
    freopen("teavel.in","r",stdin);
    int x1,y1;
    string x2,y2;
    cin>>x1>>x2>>y1>>y2;
    freopen("travel.out","w",stdout);
    if(x1==y1)  cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(f1(x2,y2)==true)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(f2(x2,y2)==true)
        cout<<"1";
    else
    {
        cout<<"00";
        return 0;
    }
    if(f3(x2,y2)==true)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
