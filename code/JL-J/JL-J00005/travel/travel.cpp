#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> c2 >> s1 >> s2;

    if(c1 == s1) cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    if(c2[0] == s2[0] && c2[1] == s2[1]) cout << 1;
    else
    {
        cout << "000";
        return 0;
    }

    if(('A' <= c2[2]  && c2[2] <= 'C'  && 'A' <= s2[2] && s2[2] <= 'C') || ('D' <= c2[2] && 'D' <= s2[2]))
    {
        cout << 1;
    }
    else
    {
        cout << "00";
        return 0;
    }

    if(abs((c2[2] -'A') - (s2[2] - 'A')) == 1 ) cout << 1;
    else
    {
        cout << "0";
        return 0;
    }
    return 0;
}
