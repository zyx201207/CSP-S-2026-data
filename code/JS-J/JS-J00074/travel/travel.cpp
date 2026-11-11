#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool x = true,p = true;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int p1 = s1[0] * 10 + s1[1];
    int p2 = s2[0] * 10 + s2[1];
    char m1 = s1[2];
    char m2 = s2[2];
    if(c1 == c2)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    if(p1 == p2)
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if(m1 == 'A' || m1 == 'B' || m1 == 'C' && m2 == 'D' || m2 == 'F' || (m2 == 'A' || m2 == 'B' || m2 == 'c' && m1 == 'D' || m1 == 'F'))
    {
        cout << 0;
    }
    else
    {

        cout << 1;
    }
    if(m1 == 'A' && m2 == 'B' || m1 == 'B' && m2 == 'C' || m1 == 'B' && m2 == 'A' || m1 == 'C' && m2 == 'B' || m1 == 'D' && m2 == 'F' || m2 == 'D' && m1 == 'F')
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
