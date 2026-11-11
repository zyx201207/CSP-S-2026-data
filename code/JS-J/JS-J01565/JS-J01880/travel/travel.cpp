#include <bits/stdc++.h>
using namespace std;
int c1,x1;
string c2,x2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>x1>>x2;
    if(x1==c1) cout<<1;
    else {cout<<"0000";return 0;}
    if(c2[0]==x2[0] && c2[1]==x2[1]) cout<<1;
    else {cout<<"000";return 0;}
    if(c2[2]=='A' || c2[2]=='B' || c2[2]=='C')
    {
        if(x2[2]=='A' || x2[2]=='B' || x2[2]=='C') cout<<1;
        else {cout<<"00";return 0;}
    }
    else
    {
        if(x2[2]=='D' || x2[2]=='F') cout<<1;
        else {cout<<"00";return 0;}
    }
    if(c2[2]==x2[2]+1 && x2[2]!='C') cout<<1;
    else if(c2[2]==x2[2]-1 && c2[2]!='C') cout<<1;
    else cout<<0;
    return 0;
}
