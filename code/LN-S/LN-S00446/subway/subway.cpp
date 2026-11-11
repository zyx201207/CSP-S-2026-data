#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> a[500010];

long long f[510][510];
int n,m,w[500010];

void flody()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int _, __,q;
    cin >> _ >> n >> m >> __ >> q;
    for (int i = 1; i <= m ;i ++ )
        cin >> w[i];
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            f[i][j] = 1e18;
    for (int i = 1; i <= n; i ++ )f[i][i] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int k;
        cin >> k;
        while (k -- )
        {
            int x ,y;
            cin >> x >> y;
            for (int j = 0 ; j < a[x].size(); j ++ )
            {
                f[a[x][j].first][i] = f[i][a[x][j].first] = min(f[i][a[x][j].first],1ll*y+a[x][j].second);
            }
            a[x].push_back({i,y});
        }
    }
    flody();
    while (q -- )
    {
        int x,y;
        cin >> x >> y;
        long long ans = 1e18;
        for (int i = 0; i < a[x].size(); i ++ )
            for (int j = 0; j < a[y].size(); j ++ )
            {
                long long t = f[a[x][i].first][a[y][j].first]+a[x][i].second+a[y][j].second+w[x]+w[y];
                ans = min(ans,t);
            }
        cout << ans << endl;
    }
    return 0;
}
