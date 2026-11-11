#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int a, n, m, s[200002] = {}, maxn = INT_MIN, a1 ,a2, a3, num, ans, c = 0;
    cin >> n >> m;
    num = n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    ans = s[num];
    if(n <= 20)
    {
        while(n--)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int i = 1; i <= m - 1; i++)
                {
                    if(ans | s[num - n + c] > maxn)
                    {
                        maxn = ans | s[num - n + c];
                        ans = ans | s[num - n + c];
                    }
                    c++;
                }
                c = 0;
            }

        }
        cout << maxn;
        return 0;
    }






    return 0;
}
