#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == c)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    string e, f;
    e = b[0] + b[1];
    f = d[0] + d[1];
    if(e == f)
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    char g, h;
    g = b[2];
    h = d[2];
    bool flag1 = false, flag2 = false;
    if((e == f) && ((g <= 'C' && h <= 'C') || (g >= 'D' && h >= 'D')))
    {
        cout << 1;
    }
    else
    {
        cout << "00";
        return 0;
    }
    if(g <= 'C' && h <= 'C')
    {
        flag1 = true;
    }
    if(g >= 'D' && h >= 'D')
    {
        flag2 = true;
    }
    if(e == f && flag1 == true && abs(int(g) - int(h)) == 1)
    {
        cout << 1;
    }
    else if(e == f && flag2 == true)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
