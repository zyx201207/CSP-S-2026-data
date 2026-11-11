#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;

ll c, n, m, d, q;
vector<ll> w;
vector<vector<ll>> a;
vector<vector<ll>> t;
vector<vector<bool>> can;
mt19937 mt;
void solve(ll sta, ll end)
{

    vector<ll> ti; //Di tie Shi jian
    ti.resize(n + 5, 0x7fffffffffffffffLL);
    queue<ll> q; //ZhanTing
    q.push(sta);
    ti[sta] = w[sta];
    while (!q.empty())
    {
        ll to = q.front();
        q.pop();

        for (ll i = 1; i <= a[to].size(); ++i)
        {
            ll Z = a[to][i];
            ll j = 1;
            for (; j <= a[Z].size(); ++j)
            {
                if (a[Z][j] == to)
                {
                    break;
                }
            }
            if (ti[Z] > (ti[to] + t[to][Z] + t[Z][j]))
            {
                ti[Z] = (ti[to] + t[to][Z] + t[Z][j]);
                q.push(Z);
            }
        }
    }
    cout << ti[end]<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    w.reserve(m + 5);

    for (ll i = 1; i <= m; ++i)
    {
        cin >> w[i];
    }
    a.reserve(n + 5);
    t.reserve(n + 5);
    for (ll i = 1; i <= n; ++i)
    {
        ll k;
        cin >> k;
        for (ll j = 1; j <= k; ++j)
        {
            a[j].push_back(0);
            ll x;
            cin >> x >> t[i][j];
            a[j].push_back(x);
        }
    }
    mt19937_64 mt2;
    mt2.seed(7891);
    mt.seed(mt2());
    while (q--)
    {
        ll from_, to_;
        cin >> from_ >> to_;
        // solve(from_,to_);
        cout<<mt()<<"\n";

    }
    return 0;
}