#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if (a == c)
    {
        cout << '1';
    }
    else
    {
        cout <<"0000" <<'\n';
        return 0;
    }
    int a1,c1;
    a1 = (b[0]-'0')*10+(b[1]-'0');
    c1 = (d[0]-'0')*10+(d[1]-'0');
    if (a1 == c1)
    {
        cout << '1';
    }
    else
    {
        cout <<"000"<<'\n';
        return 0;
    }
    int b1,d1;
    b1 = b[2]-'A';
    d1 = d[2]-'A';
    if ((b1<=2&&d1<=2)||(b1>2&&d1>2))
    {
        cout << '1';
    }
    else
    {
        cout <<"00"<<'\n';
        return 0;
    }
    if ((b1<=2&&d1<=2)&&abs(b1-d1)==1)
    {
        cout << '1'<<'\n';
    }
    else if ((b1>2&&d1>2)&&abs(b1-d1)==2)
    {
        cout << '1' <<'\n';
    }
    else
    {
        cout << '0' <<'\n';
    }
    return 0;
}













