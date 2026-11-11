#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

bool check1()
{
    if (s1[2] >= 'A' && s1[2] <= 'C')
        if (s2[2] >= 'A' && s2[2] <= 'C') return true;
        else return false;
    else if (s1[2] >= 'D' && s1[2] <= 'F')
        if (s2[2] >= 'D' && s2[2] <= 'F') return true;
        else return false;
    return false;
}

bool check2()
{
    if (!check1()) return false;
    if (abs((s2[2] - 'A') - (s1[2] - 'A')) == 1) return true;
    return false;
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    cout << (c1 == c2);
    cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]);
    cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check1());
    cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check1() && check2());
    cout << endl;
    return 0;
}
