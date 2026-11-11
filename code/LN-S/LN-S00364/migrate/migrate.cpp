#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5005;
pair<int, int> dp[maxn][maxn];
int x[maxn];
int c, t;
int n, d;

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c >> t;

    while(t--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i], dp[i][i] = {1, 0};

        for(int len = 2; len <= n; len++)
        {
            for(int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                dp[i][j] = {0, 2e6 + 1};
                for(int k = i; k < j; k++)
                {
                    if(x[j] - x[k] <= d)
                    {
                        if(dp[i][k].second + 1 == dp[i][j].second)
                            dp[i][j].first += dp[i][k].first;
                        else if(dp[i][k].second + 1 < dp[i][j].second)
                            dp[i][j] = {dp[i][k].first, dp[i][k].second + 1};
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                if(dp[i][j].first == 2) ans++;
        cout << ans << "\n";

        /*
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                printf("dp[%d][%d] = {%d, %d}\n", i, j, dp[i][j].first, dp[i][j].second);
        cout << "\n";*/
    }


    return 0;
}
