#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int c1, c2;
bool ans[7], x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    if(c1 == c2)
    {
        ans[1] = 1;
        if(s1[1] == s2[1] && s1[2] == s2[2])
        {
            ans[2] = 1;
            x = (s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C');
            y = (s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C');
            if(x == y)
            {
                ans[3] = 1;
                if(x == 0 && y == 0)
                    ans[4] == 1;
                else if(x == 1 && y == 1)
                {
                    if((s1[3] == 'A' && s2[3] == 'B') || (s1[3] == 'B' && s2[3] == 'A'))
                        ans[4] = 1;
                    if((s1[3] == 'B' && s2[3] == 'C') || (s1[3] == 'C' && s2[3] == 'B'))
                        ans[4] = 1;
                }
            }
        }
    }
    cout << ans[1] << ans[2] << ans[3] << ans[4];
    return 0;
}
