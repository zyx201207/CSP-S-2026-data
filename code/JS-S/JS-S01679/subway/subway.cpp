#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
typedef long long LL;
const LL INF = 1e18;
int c, n, m, d, q, x, y;
LL W[MAXN];
LL w[1005][1005];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> W[i];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
        {
            if(i == j)
                w[i][j] = 0;
            else
                w[i][j] = INF;
        }
    for(int i = 1,k; i <= n; i++)
    {
        cin >> k;
        int a[k + 1];
        LL t[k + 1];
        for(int j = 1; j <= k; j++)
        {
            cin >> a[j] >> t[j];
            for(int h = 1; h < j; h++)
            {
                w[a[h]][a[j]] = min(t[h] + t[j], w[a[h]][a[j]]);
                w[a[j]][a[h]] = w[a[h]][a[j]];
            }
        }
    }
    for(int k = 1; k <= m; k++)
        for(int i = 1; i < m; i++)
        {
            if(w[i][k] == INF)
                continue;
            for(int j = i + 1; j <= m; j++)
            {
                if(w[k][j] == INF)
                    continue;
                w[i][j] = min(w[i][k] + w[k][j], w[i][j]);
                w[j][i] = w[i][j];
            }
        }
    while(q--)
    {
        cin >> x >> y;
        cout << W[x] + W[y] +w[x][y]<< "\n";
    }
    return 0;
}
