#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << 1;
        string t1, t2;
        for (int i = 0;i < 2;i++)
        {
            t1 = s1[i];
            t2 = s2[i];
        }
        if (t1 == t2)
        {
            cout << 1;
            char m1 = s1[2], m2 = s2[2];
            if ((m1 <= 'C' && m2 <= 'C') || (m1 > 'C' && m2 > 'C'))
            {
                cout << 1;
                if (abs (m1 - m2) == 1 || (m1 > 'C' && m2 > 'C'))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
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
