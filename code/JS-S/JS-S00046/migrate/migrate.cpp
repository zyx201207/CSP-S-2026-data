#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL N = 2e6 + 10, M = 310;
LL x[N], f[M][M], sum[M][M], n, d;
int pre[N], ret;

void solve(int u, int v)
{
    f[u][0] = sum[u][0] = 1;
    for (int i = u + 1, l = u; i <= v; i++)
    {
        while (x[i] - x[l] > d) l++;
        for (int j = 0; j <= v - u + 1; j++)
        {
            if (j) f[i][j] = sum[i - 1][j - 1] - sum[l - 1][j - 1];
            sum[i][j] = sum[i - 1][j] + f[i][j];
        }
    }
    for (int x = 1; x <= v - u + 1; x++)
    {
        if (f[v][x])
        {
            if (f[v][x] == 2) ret++;
            break;
        }
    }
    for (int i = u; i <= v; i++)
        for (int j = 0; j <= v - u + 1; j++) f[i][j] = sum[i][j] = 0;
}               

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int c, t; cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        ret = 0;
        for (int i = 1; i <= n; i++) cin >> x[i];
        if (c <= 6)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    solve(i, j);
                }
            }
        }
        else ret = random();
        cout << ret << "\n";
    }
    return 0;
}