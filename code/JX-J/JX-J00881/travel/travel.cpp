#include <bits/stdc++.h>
using namespace std;
string r[10],x[10];
bool f;
bool ok2(string a,string b)
{
    if(a[0]==b[0]&&a[1]==b[1])
    {
        return 1;
    }
    else return 0;
}
bool ok3(string a,string b)
{
    if(a[2]=='A'||a[2]=='B'||a[2]=='C')
    {
        if(a[2]!=b[2]&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))
        {
            return 1;
        }
    }
    else if(a[2]=='D'||a[2]=='F')
    {
        if(a[2]!=b[2]&&(b[2]=='D'||a[2]=='F'))
        {
            return 1;
        }
    }
    return 0;
}
bool ok4(string a,string b)
{
    if(a[2]-1==b[2]||a[2]+1==b[2])return 1;
    else
    {
        return 0;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r[1]>>r[2]>>x[1]>>x[2];
    bool h=r[1]==x[1];
    if(r[1]==x[1])
    {
        cout<<1;
    }
    else cout<<0;
    f=ok2(r[2],x[2]);
    if(f&&h)
    {
        cout<<1;
    }
    else cout<<0;
    if(f&&ok3(r[2],x[2])&&h)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(ok3(r[2],x[2])&&f&&ok4(r[2],x[2])&&h)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
