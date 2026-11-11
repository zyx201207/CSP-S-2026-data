#include <bits/stdc++.h>
using namespace std;
//#define ll long long



int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if (s1 != s3)
    {
        cout << "0000";
    }
    else
    {
        cout << "1";
        int k1 = (s2[0] - 48) * 10 + s2[1] - 48;
        int k2 = (s4[0] - 48) * 10 + s4[1] - 48;
        if (k1 != k2)
        {
            cout << "000";
        }
        else
        {
            cout << "1";
            char k3 = s2[2];
            char k4 = s4[2];
            if (k3 < 'D' && k4 > 'C' || k3 > 'C' && k4 < 'D')
            {
                cout << "00";
            }
            else
            {
                cout << "1";
                if (abs(k3 - k4) <= 1) cout << "1";
                else cout << "0";
            }
        }

    }

    return 0;
}
