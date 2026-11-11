#include <bits/stdc++.h>
using namespace std;
int n, m;
int w[500002]={0};
int k[502]={0};
int a[502][500002]={0};
unordered_map<int, int> ts[500002];
bool lp[502][500002]={false};
unordered_map<int, long long> cost;
long long dijkstra(int, int);
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, d;
    int q;
    cin >> c >> n >> m >> d >> q;
    for (int i=1; i<=m; i++)
    {
        cin >> w[i];
    }
    for (int i=1; i<=n; i++)
    {
        cin >> k[i];
        for (int j=1; j<=k[i]; j++)
        {
            int tt;
            cin >> a[i][j] >> tt;
            lp[i][a[i][j]] = true;
            ts[a[i][j]].insert({i, tt});
        }
    }
    ;

    while (q--)
    {
        int x, y;
        cost.clear();
        cin >> x >> y;
        long long ans = dijkstra(x, y) + w[x] + w[y];
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
long long dijkstra(int x, int y)
{
    queue<pair<int, long long>> qu;
    cost.insert({x, 0});
    qu.push({x, 0});

    while(!qu.empty())
    {
        pair<int, long long> u = qu.front();
        qu.pop();

        int station = u.first;
        long long cost_s = u.second;
        if(cost.find(station)!=cost.end() && cost_s>cost[station])
            continue;
        for (int i=1; i<=n; i++)
        {
            if(lp[i][station])
            {
                for (int j=1; j<=k[i]; j++)
                {
                    int nxt = a[i][j];
                    if(nxt == station)
                        continue;
                    long long cost_cur = cost_s + ts[station][i] + ts[nxt][i];
                    if(cost.find(nxt) == cost.end())
                    {
                        cost.insert({nxt, cost_cur});
                        qu.push({nxt, cost_cur});
                    }
                    else
                    {
                        if(cost[nxt] > cost_cur)
                        {
                            cost[nxt] = cost_cur;
                            qu.push({nxt, cost_cur});
                        }
                    }
                }
            }
        }
    }
    if(cost.find(y) != cost.end())
    {
        return cost[y];
    }

    return 0;
}


