#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    string t1 = s1.substr(0, 2);
    string t2 = s2.substr(0, 2);
    if (t1 == t2)
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    char ch1 = s1[2];
    char ch2 = s2[2];
    if ((ch1 <= 'C' && ch2 <= 'C') || (ch1 > 'C' && ch2 > 'C'))
    {
        cout << 1;
    }
    else
    {
        cout << "00";
        return 0;
    }
    if (abs((int)ch2 - (int)ch1) == 1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}