#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i ++ )
#define DF(i, a, b) for (int i = (a); i >= (b); i -- )
inline void chkmin(int& a, int b) { if (a > b) a = b; }
inline void chkmax(int& a, int b) { if (a < b) a = b; }

bool side[500];

signed main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    side['A'] = side['B'] = side['C'] = 1;
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << "1";
        if (s1[0] == s2[0] && s1[1] == s2[1]) 
        {
            cout << "1";
            if (side[s1[2]] == side[s2[2]])
            {
                cout << "1";
                if (abs(s1[2] - s2[2]) == 1 || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D')
                    cout << "1\n";
                else cout << "0\n";
            }
            else cout << "00\n";
        }
        else cout << "000\n";
    }
    else cout << "0000\n";
    return 0; 
}