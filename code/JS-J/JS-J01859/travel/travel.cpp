#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)
    {
        cout << "0000";
    }
    else if(c1 == c2)
    {
        if(s1[0] != s2[0] || s1[1] != s2[1])
        {
            cout << "1000";
        }
        else
        {
            char a = s1[2], b = s2[2];
            if(a == 'A' && b == 'D' || a == 'A' && b == 'F'
              || a == 'B' && b == 'D' || a == 'B' && b == 'F'
              || a == 'C' && b == 'D' || a == 'C' && b == 'F'
              || a == 'D' && b == 'A' || a == 'F' && b == 'A'
              || a == 'D' && b == 'B' || a == 'F' && b == 'B'
              || a == 'D' && b == 'C' || a == 'F' && b == 'C')
            {
                cout << "1100";
            }
            else
            {
                if(abs(a - b) == 1 || a == 'D' && b == 'F' || a == 'F' && b == 'D')
                {
                    cout << "1111";
                }
                else
                {
                    cout << "1110";
                }
            }
        }
    }
    return 0;
}
