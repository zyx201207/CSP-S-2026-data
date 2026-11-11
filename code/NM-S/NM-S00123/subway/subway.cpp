#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct base
{
    ll to;
    ll dis;
};

struct target
{
    ll begin;
    ll end;
};

struct query
{
    ll index;
    ll begin;
    ll to;
};

struct item
{
    ll to;
    ll dis;

    bool operator<(item b) const
    {
        return dis > b.dis;
    }
};

void dijkstra(vector<vector<base>> &G, vector<ll> &D, ll s)
{
    priority_queue<item> q;
    // map<ll,bool>used;
    q.push({s, 0});

    // ll num=0;
    while (!q.empty())
    {
        // num++;
        // if(num==1000){
        //     cout<<"p"<<endl;
        // }

        item t = q.top();
        q.pop();
        ll u = t.to;
        // used[u]=true;

        if (D[u] > t.dis)
        {
            D[u] = t.dis;

            for (ll i = 0; i < G[u].size(); i++)
            {
                base p = G[u][i];
                q.push({p.to, D[u] + p.dis});
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll c = 0;
    ll m = 0; //station_num
    ll n = 0; //way_num
    ll d = 0; //for station->Max way_num
    ll q = 0; //plan_num

    cin >> c >> n >> m >> d >> q;

    vector<ll> enter_time(m + 1);
    for (ll i = 1; i <= m; i++)
    {
        cin >> enter_time[i];
    }

    vector<vector<base>> G(n + m + 1);
    vector<vector<ll>> belong(m + 1);
    vector<map<ll, ll>> change(n + 1);
    for (ll i = 1; i <= n; i++) //line
    {
        ll k = 0;
        cin >> k;
        G[i].assign(k, {0, 0});
        for (ll j = 0; j < k; j++) //station
        {
            ll pos = 0, time = 0;
            cin >> pos >> time;

            // G[i].push_back({})
            G[i][j].to = pos + n;
            G[i][j].dis = time;

            change[i][pos] = time;

            // G[pos + n].emplace_back(i);
            // G[pos + n].emplace_back(time);
            G[pos + n].push_back({i, time});

            belong[pos].push_back(i);
        }
    }

    // vector<vector<ll>> D(m + 1, vector<ll>(n + m + 1, LLONG_MAX));
    // for (ll s = n + 1; s <= n + m; s++)
    // {
    //     dijkstra(G, D[s - n], s);
    // }

    vector<ll> D;
    vector<ll> ans(q + 1);
    // vector<>
    unordered_map<ll, vector<query>> ask;
    for (ll i = 1; i <= q; i++)
    {

        ll u = 0, v = 0;
        cin >> u >> v;

        ask[u].push_back({i, u, v});

        // dijkstra(G, D, u + n);

        // cout << D[v + n] + enter_time[u] + enter_time[v] << '\n';
    }

    for (auto it = ask.begin(); it != ask.end(); it++)
    {
        D.assign(n + m + 1, LLONG_MAX);
        ll from = (*it).first;
        dijkstra(G, D, from + n);

        for (int i = 0; i < (*it).second.size(); i++)
        {
            ans[(*it).second[i].index] = D[(*it).second[i].to + n] + enter_time[(*it).first] + enter_time[(*it).second[i].to];
        }
    }

    for (ll i = 1; i <= q; i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}