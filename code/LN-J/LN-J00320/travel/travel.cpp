#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, ans = "0000";
int is1, is2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    is1 = s1[2] + 1;
    is2 = s2[2] + 1;
    if(c1 == c2)
    {
        ans[0] = '1';
        if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            ans[1] = '1';
            if(s1[2] <= 'C' && s2[2] <= 'C' || s1[2] > 'C' && s2[2] > 'C')
            {
                ans[2] = '1';
                int a = is1 - is2;
                if(s1[2] <= 'C' && s2[2] <= 'C' && (a == 1 || a == -1))
                    ans[3] = '1';
                else if(s1[2] > 'C' && s2[2] > 'C')
                    ans[3] = '1';
            }
        }
    }
    cout << ans;
    return 0;
}
