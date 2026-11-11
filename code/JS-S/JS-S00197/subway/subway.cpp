#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXM = 1005;
const int MAXN = 505;


int c, n, m, d, q;

vector<int> g[MAXM];
int w[MAXM], t[MAXM][MAXN];
bool vis[MAXM];
int dist[MAXM][MAXN];


int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    int T, k, pre, crt, t_j;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> crt;
            cin >> t[pre][t_j];
            T = t[pre][t_j];
            if (j >= 2)
            {
                g[pre].push_back(crt);
                g[crt].push_back(pre);
            }
            pre = crt;
        }
    }



    int x, y;
    while(q--)
    {
        cin >> x >> y;
        cout << abs(x - y) * T + w[x] + w[y] << endl;
    }
    return 0;
}
