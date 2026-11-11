#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const LL INF = 2e18;
const int N = 505, M = 500005;
int w[M], k[N];
vector<PII> a[M];
LL f[N][N];
int c, n, m, d, q;
void work()
{
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
        cin >> w[i];
    for (int i=1;i<=n;i++)
    {
        cin >> k[i];
        while (k[i] --)
        {
            int x, t;
            cin >> x >> t;
            a[x].pb({i, t});
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i != j)
                f[i][j] = INF;
    for (int i=1;i<=m;i++)
    {
        const int siz = a[i].size();
        for (int j=0;j<siz;j++)
            for (int k=j+1;k<siz;k++)
                f[a[i][j].x][a[i][k].x] = f[a[i][k].x][a[i][j].x] = min(f[a[i][k].x][a[i][j].x], (LL)a[i][j].y + a[i][k].y);
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        LL ans = INF;
        for (PII i : a[x])
            for (PII j : a[y])
                ans = min(ans, f[i.x][j.x] + i.y + j.y);
        cout << ans + w[x] + w[y] << '\n';
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--)work();
    return 0;
}
