#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    s1 = "?" + s1;
    s2 = "?" + s2;
    if (c1 != c2)
    {
        cout << "0000" << '\n';
    }
    else
    {
        cout << "1";
        if (s1[1] != s2[1] || s1[2] != s2[2])
        {
            cout << "000" << '\n';
        }
        else
        {

            cout << "1";
            if (((s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C') && (s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C')) || ((s1[3] == 'E' || s1[3] == 'F') && (s2[3] == 'E' || s2[3] == 'F')))
            {

                cout << "1";
                if (abs(s1[3] - s2[3]) == 1)
                {

                    cout << "1" << '\n';
                }
                else
                {
                    cout << "0" << '\n';
                }
            }
            else
            {
                cout << "00" << '\n';
            }
        }
    }
    return 0;
}
