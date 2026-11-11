#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    char a1,a2,a3,b1,b2,b3;
    cin >> a >> a1 >> a2 >> a3 >> b >> b1 >> b2 >> b3;
    if(a==b) cout << "1";
    else
    {
        cout << "0000";
        return 0;
    }
    if(a2==b2) cout << "1";
    else
    {
        cout << "000";
        return 0;
    }
    int n = int(a3);
    int m = int(b3);
    if( (n==65&&(m==66||m==67)) || (n==66&&(m==65||m==67)) || (n==67&&(m==65||m==66)) || (n==68&&m==69) || (n==69&&m==68))
        cout << "1";
    else
    {
        cout << "00";
        return 0;
    }
    if( (n==65&&m==66) || (n==66&&m==65) || (n==66&&m==67) || (n==67&&m==66) || (n==68&&m==69) || (n==69&&m==68))
        cout << "1";
    else cout << "0";
    return 0;
}
