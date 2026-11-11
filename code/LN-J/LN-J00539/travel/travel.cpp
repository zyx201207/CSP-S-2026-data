#include<bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;

bool check3(char a, char b)
{
    if(a <= 'C' && b <= 'C') return 1;
    if(a >= 'D' && b >= 'D') return 1;
    return 0;
}

bool check4(char a, char b)
{
    if(a <= 'C' && b <= 'C' && abs(a - b) == 1) return 1;
    else if(a >= 'D' && b >= 'D' && abs(a - b) == 2) return 1;
    return 0;
}

signed main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 != c2)
    {
        cout << "0000\n";
        return 0;
    }else cout << "1";

    if(!(s1[0] == s2[0] && s1[1] == s2[1]))
    {
        cout << "000\n";
        return 0;
    }else cout << "1";

    if(!check3(s1[2], s2[2]))
    {
        cout << "00\n";
        return 0;
    }else cout << "1";

    if(!check4(s1[2], s2[2]))
    {
        cout << "0\n";
        return 0;
    }else cout << "1\n";

    return 0;
}
