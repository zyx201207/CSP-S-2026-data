#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
bool if_ok;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>a>>b>>c>>d;
    int nb = (b[0] - '0') * 10 + b[1] - '0';
    int nd = (d[0] - '0') * 10 + d[1] - '0';
    int zb = b[2] - 'A';
    int zd = d[2] - 'A';
    if(a == c) cout<<"1";
    else cout<<"0";
    if(nb == nd && a == c) cout<<"1";
    else cout<<"0";
    if(((zb <= 2 && zd <= 2) || (zb >= 3 && zb <= 4 && zd >= 3 && zd <= 4)) && nb == nd && a == c)
    {
        cout<<"1";
        if_ok = true;
    }
    else cout<<"0";
    if(if_ok)
    {
        if(zb - zd == 1 || zd - zb == 1) cout<<"1";
        else cout<<"0";
    }
    else cout<<"0";
    return 0;
}
