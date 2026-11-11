#include <bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1==b1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(a2=b2)
    {
        cout << 1;
    }
    if(a2<b2)
    {
        cout << 1;
    }
    else if(a2+1<b2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
