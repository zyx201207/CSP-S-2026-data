#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c,aa,bb,cc,dd;
int main()
{
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        aa=1;
    }
    if(b[0]==d[0] && b[1]==d[1] && aa==1)
    {
        bb=1;
    }
    if(b[2]>'C'&&d[2]>'C' && bb==1)
    {
        cc=1;
    }
    if(b[2]<'D'&&d[2]<'D' && bb==1)
    {
        cc=1;
    }
    if(b[2]==d[2]+1 || b[2]==d[2]-1)
    {
        if(cc==1)
        {
            dd=1;
        }
    }
    cout<<aa<<bb<<cc<<dd;
    return 0;
}
