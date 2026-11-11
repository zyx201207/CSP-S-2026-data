#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1600;
ll c, n, m, d, q, dp[N][N], w[N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= m + n; i++)
        dp[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int a, t;
            cin >> a >> t;
            dp[i + m][a] = dp[a][i + m] = t;
        }
    }
    for (int k = 1; k <= m + n; k++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for (int k = 1; k <= m + n; k++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    while (q--){
        int x, y;
        cin >> x >> y;
        cout << w[x] + w[y] + dp[x][y] << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}