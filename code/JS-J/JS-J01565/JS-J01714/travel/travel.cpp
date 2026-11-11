#include <bits/stdc++.h>

using namespace std;

void solve(string c1, string s1, string c2, string s2)
{
    if(c1 == c2)
        cout << 1;
    else
    {
        cout << "0000";
        return;
    }

    if(s1[0] == s2[0] && s1[1] == s2[1])
        cout << 1;
    else
    {
        cout << "000";
        return;
    }

    if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
        cout << 7;
    else
    {
        cout << "00";
        return;
    }

    if(abs(s1[2] - s2[2]) == 1)
        cout << 6;
    else
        cout << 0;
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    solve(c1, s1, c2, s2);

    return 0;
}