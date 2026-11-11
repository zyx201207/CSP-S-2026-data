#include <bits/stdc++.h>
using namespace std;
bool book[6];
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool b;
    if (c1 == c2)
    {
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            if (book[s1[2] - 'A'] == book[s2[2] - 'A'])
            {
                if (!(abs(s1[2] - s2[2]) == 2))
                {
                    cout << "1111" << '\n';
                }
                else
                {
                    cout << "1110" << '\n';
                }
            }
            else
            {
                cout << "1100" << '\n';
            }
        }
        else
        {
            cout << "1000" << '\n';
        }
    }
    else
    {
        cout << "0000" << '\n';
    }
}