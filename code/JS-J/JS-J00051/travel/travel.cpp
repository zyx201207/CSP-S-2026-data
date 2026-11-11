#include <bits/stdc++.h>
using namespace std;

string ca, sa, cb, sb, s1, s2;
char c1, c2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> ca >> sa >> cb >> sb;
    s1 = sa.substr(0, 2);
    s2 = sb.substr(0, 2);
    c1 = sa[2];
    c2 = sb[2];
    if (ca == cb)
    {
        cout << "1";
        if (s1 == s2)
        {
            cout << "1";
            if ((c1 <= 'C' && c2 <= 'C') || (c1 >= 'D' && c2 >= 'D'))
            {
                cout << "1";
                if ((c1 >= 'D' && c2 >= 'D') || (c1 <= 'C' && c2 <= 'C' && (c1 == 'B' || c2 == 'B')))
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
            }
            else
            {
                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}
