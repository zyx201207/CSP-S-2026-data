#include <bits/stdc++.h>
using namespace std;
bool check(string a)
{
    if (a.back() >= 'A' && a.back() <= 'C')
    {
        return 1;
    }
    return 0;
}
bool check(char a, char b)
{
    if (a > b)
        swap(a, b);
    if (a == 'C' && b == 'D')
        return 0;
    return b - a == 1;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << 1;
        if (s1.substr(0, 2) == s2.substr(0, 2))
        {
            cout << 1;
            if (check(s1) == check(s2))
            {
                cout << 1;
                if (check(s1.back(), s2.back()))
                {
                    cout << 1;
                }
                else
                    cout << 0;
            }
            else
                cout << "00";
        }
        else
            cout << "000";
    }
    else
        cout << "0000";
}