#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 500005, M = 505;
typedef pair<int, int> PII;
typedef long long LL;

int arr[N]; vector<PII> t[N];
LL dist[M][M];
int c, n, m, d, q;

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        while (k--)
        {
            int station, tim; cin >> station >> tim;
            t[station].push_back({ i, tim });
        }
    }

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
        {
            if (i == j) continue;
            dist[i][j] = 1e18;
        }
    for (int i = 1; i <= m; i++)
    {
        for (auto aa : t[i])
        {
            int line1 = aa.first, t1 = aa.second;
            for (auto bb : t[i])
            {
                int line2 = bb.first, t2 = bb.second;
                if (line1 == line2) continue;
                dist[line1][line2] = dist[line2][line1] = min(dist[line1][line2], 0ll + t1 + t2);
            }
        }
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    while (q--)
    {
        int x, y; cin >> x >> y;
        LL ans = 1e18;
        for (auto aa : t[x])
            for (auto bb : t[y])
            {
                int line1 = aa.first, t1 = aa.second;
                int line2 = bb.first, t2 = bb.second;
                ans = min(ans, dist[line1][line2] + arr[x] + arr[y] + t1 + t2);
            }
        cout << ans << '\n';
    }

    return 0;
}
