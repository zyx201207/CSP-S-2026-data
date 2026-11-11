#include <bits/stdc++.h>

struct node
{
    int ds, id;
    bool operator<(const node& oth) const
    {
        return ds > oth.ds;
    }
};

void slv()
{
    int N;
    long long d;
    std:: cin >> N >> d;

    std:: vector<long long> x(N + 1);
    bool f = 1;

    for (int i = 1; i <= N; ++i)
    {
        std:: cin >> x[i];
        if (i > 2 && (x[i] - x[i - 1]) != (x[2] - x[1])) f = 0;
    }

    if (f)
    {
        long long df = x[2] - x[1];
        if (d < 2 * df)
        {
            std:: cout << "0\n";
            return;
        }
        long long div = d / df;
        std:: cout << std:: max(N - (2 * div - 1), 0LL) << '\n';

        return ;
    }

    std:: vector<std:: vector<int>> adj(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            if (x[j] - x[i] <= d)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            } else break;
        }
    }

    long long zct = 0;
    for (int nd = 1; nd <= N; ++nd)
    {
        std:: vector<int> dss(N + 1), ct(N + 1);
        std:: vector<bool> vis(N + 1);

        std:: queue<node> q;
        q.push({0, nd});
        vis[nd] = 1;

        while (!q.empty())
        {
            auto nw = q.front();
            q.pop();

            int u = nw.id, di = nw.ds + 1;
            for (auto v : adj[u])
            {
                if (vis[v] && di != dss[v]) continue;
                vis[v] = 1;

                if (!dss[v]) dss[v] = di;
                if (di == dss[v]) ct[v]++;

                q.push({di, v});
            }
        }

        int nct = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (ct[i] == 2) nct++;
        }

        zct += nct;
    }

    std:: cout << (zct / 2) << '\n';
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.in", "w", stdout);

    int c, t;
    std:: cin >> c >> t;

    while (t--)
    {
        slv();
    }

    return 0;
}