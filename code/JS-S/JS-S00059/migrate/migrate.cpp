#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,d;
int* a;
int** dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        a = new int[n + 1];
        dp = new int*[n + 1];
        dp[0] = new int[n + 1]();
        for(int i = 1;i <= n;i++)
        {
            dp[i] = new int[n + 1]();
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(a[j] - a[i] <= d) dp[i][j] += 1;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(a[j] - a[i] > d)
                {
                    for(int k = i + 1;k < j;k++) dp[i][j] += dp[i][k] * dp[k][j];
                }
            }
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(dp[i][j] == 2) cnt++;
            }
        }
        cout << cnt << '\n';
        delete[] a;
    }
    return 0;
}
