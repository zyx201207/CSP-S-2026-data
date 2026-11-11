#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    if(ay[2]=='F') ay[2]='E';
    if(by[2]=='F') by[2]='E';
    int a=(int)(ax==bx);
    int b=(int)(ay[0]==by[0] && ay[1]==by[1]);
    b&=a;
    int c=(int)((ay[2]<='C' && by[2]<='C') || (ay[2]>'C' && by[2]>'C'));
    c&=b;
    int d=(int)((max((ay[2]-by[2]),(by[2]-ay[2]))==1ll) && (!((ay[2]=='C' && by[2]=='D'))) && (!((ay[2]=='D' && by[2]=='C'))));
    d&=c;
    cout<<a<<b;
    cout<<c<<d;
    return 0;
}

