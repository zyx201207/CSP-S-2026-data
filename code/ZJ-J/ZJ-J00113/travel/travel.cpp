#include <bits/stdc++.h>
using namespace std;
#define iny signed long long
constexpr int maxn=2e5+13;

string c1,s1,c2,s2;
bool check()
{
    char x1=s1[2],x2=s2[2];
    if(x1>x2)
    {
        swap(x1,x2);
    }
    //cout<<x1<<x2;
    if(x1=='A'&&x2=='B')
    {
        return true;
    }
    if(x1=='B'&&x2=='C')
    {
        return true;
    }
    if(x1=='D'&&x2=='E')
    {
        return true;
    }
    return false;
}
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000\n";
        return 0;
    }
    cout<<"1";
    char tp1=s1[0],tp2=s1[1];
    char tt1=s2[0],tt2=s2[1];
    if(tp1!=tt1||tp2!=tt2)
    {
        cout<<"000\n";
        return 0;
    }
    cout<<"1";
    int xx1,xx2;
    if(s1[2]=='D'||s1[2]=='E')
    {
        xx1=2;
    }
    else
    {
        xx1=1;
    }
    if(s2[2]=='D'||s2[2]=='E')
    {
        xx2=2;
    }
    else
    {
        xx2=1;
    }
    if(xx1!=xx2)
    {
        cout<<"00\n";
        return 0;
    }
    cout<<"1";
    if(check())
    {
        cout<<"1\n";
    }
    else
    {
        cout<<"0\n";
    }

    return 0;
}

