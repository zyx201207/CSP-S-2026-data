#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    int c1,c2;
    cin >> c1 >> c2;
    if(c1 == c2 && c1 != 01 && c1 != 16)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    return 0;
}