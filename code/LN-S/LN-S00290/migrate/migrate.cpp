#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

namespace langfengya
{
    void Main();
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    langfengya::Main();
    return 0;
}

namespace langfengya
{
    int c, t;
    int n, d;
    const int N = 5010;
    int x[N];
    void read()
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
    }
    vector <int>e[N];
    priority_queue <PII, vector<PII>, greater<PII> >q;
    bool flag[N];
    int num[N][N];
    int dis[N];
    void dij(int x)
    {
        for (int i = 1; i <= n; i++) flag[i] = 0;
        q.push({0, x});
        dis[x] = 0;
        while (!q.empty())
        {
            
            PII t = q.top();
            q.pop();
            int u = t.second;
            int w = t.first;
            
            if (flag[u]) continue;
            flag[u] = 1;
            for (int v : e[u])
            {
                if (dis[v] > dis[u] + 1)
                {
                    //cerr << "in" << u << endl;
                    if (dis[v] != 1e9) num[v][dis[v]] = 0;
                    dis[v] = dis[u] + 1;
                    num[v][dis[v]] = 1;
                    q.push({dis[v], v});
                }
                else if (dis[v] == dis[u] + 1)
                {
                    num[v][dis[v]]++;
                }
            }
        }
        return ;
    }
    void solve()
    {
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (x[j] - x[i] <= d)
                {
                    e[i].push_back(j);
                }
            }
            //cerr << "！！！！" << e[i].size() << endl;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j ++) 
            {
                num[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) dis[j] = 1e9;
            dij(i);
            for (int j = i + 1; j <= n; j++)
            {
                if (num[j][dis[j]] == 2)
                {
                    ans++;
                }
                num[j][dis[j]] = 0;
            }
        }
        cout << ans << endl;
    }
    void Main()
    {
        cin >> c >> t;
        while (t--)
        {
            read();
            solve();
        }
    }
}