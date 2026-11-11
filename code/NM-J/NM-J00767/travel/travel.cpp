#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1[4], s1[4], c2[4], s2[4];
    for(int i = 0; i <= c1; i++)
    {
        cin >> c1[i];
    }
    for(int i = 0; i <= s1; i++)
    {
        cin >> s1[i];
    }
    for(int i = 0; i <= c2; i++)
    {
        cin >> c2[i];
    }
    for(int i = 0; i <= s2; i++)
    {
        cin >> s2[i];
    }

    if (c1 == c2)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0";
    }
    if (s1[1][2] == s2[1][2])
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0";
    }
    if (s1[3] == s2[3])
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (s1[1][2][3] - s2[1][2][3] == 1 || s2[1][2][3] - s1[1][2][3] == 1)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}


