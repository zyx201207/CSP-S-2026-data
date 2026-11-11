#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5005, M = 2e6 + 5;
ll a[M];
int dp[N][N], ways[N][N];

void solve1()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    memset(ways, 0, sizeof ways);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1, ways[i][i] = 1;
        int last = i, sum = 1;
        for (int j = i + 1; j <= n; j++)
        {
            while (last < j && a[j] - a[last] > m) last++;
            if (last == j) break;
            dp[i][j] = dp[i][last] + 1;
            last = i;

            for (int k = max(i, max(1, j - m)); k <= j; k++)
            {
                if (dp[i][k] < dp[i][j]) ways[i][j] += ways[i][k];
                else break;
            }

            if (ways[i][j] == 2) ans++;
        }
    }
    cout << ans << '\n';
}

void solve2()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll d = a[2] - a[1];
    ll d1 = m / d;
    if (d1 <= 1) cout << 0 << '\n';
    else if (n >= d1 * 2) cout << n - d1 * 2 + 1 << '\n';
    else cout << 0 << '\n';
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, T;
    cin >> c >> T;
    if (c <= 10) while (T--) solve1();
    else while (T--) solve2();
    return 0;
}
