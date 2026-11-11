#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    string r,rc,x,xc;
    cin >> r >> rc >> x >> xc;
    if(r==x)
    {
        cout << 1 ;
    }
    else
    {
        cout << 0 << 0 << 0 << 0;return 0;
    }
    if(rc[0]==xc[0]&&rc[1]==xc[1])
    {
        cout << 1;
    }
    else{cout << 0 << 0 << 0;return 0;}
    if(rc[2]=='A'||rc[2]=='B'||rc[2]=='C')
    {
        if(xc[2]=='D'||xc[2]=='F')cout << 0;
        else cout << 1;
    }
    if(rc[2]=='D'||rc[2]=='F')
    {
        if(xc[2]=='A'||xc[2]=='B'||xc[2]=='C')cout << 0;
        else cout << 1;
    }
    if(rc[2]=='A')
    {
        if(xc[2]=='B')cout << 1;
        else cout << 0;
    }
    else if(rc[2]=='B')
    {
        if(xc[2]=='A'||xc[2]=='C')cout << 1;
        else cout << 0;
    }
    else if(rc[2]=='C')
    {
        if(xc[2]=='B')cout << 1;
        else cout << 0;
    }
    else if(rc[2]=='D')
    {
        if(xc[2]=='F')cout << 1;
        else cout << 0;
    }
    else if(rc[2]=='F')
    {
        if(xc[2]=='D')cout << 1;
        else cout << 0;
    }
}
