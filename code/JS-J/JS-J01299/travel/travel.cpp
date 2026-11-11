#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
        cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1])
        cout << 1;
    else
    {
        cout << "000";
        return 0;
    }
    int a1, a2;
    if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
        a1 = 1;
    else
        a1 = 2;
    if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
        a2 = 1;
    else
        a2 = 2;
    if(a1 == a2)
        cout << 1;
    else
    {
        cout << "00";
        return 0;
    }
    if(a1 == 2)
        cout << 1;
    else if(s1[2] == 'B' || s2[2] == 'B')
        cout << 1;
    else
        cout << 0;
    return 0;
}
