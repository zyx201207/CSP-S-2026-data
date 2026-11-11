#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll maxn = 505;
constexpr ll maxm = 5e5 + 5;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

ll TESTCASE, n, m, d, q;
vector<ll> w;

struct passway // info of passageway from platform to station hub
{
    ll line, t;
    passway(ll LINE = 0, ll T = 0) : line(LINE), t(T) {;}
};

vector<vector<passway>> stat; // subways lines at station and the time it takes to go to their corresponding platform
vector<vector<ll>> tran; // minimum transfer time from line to line

void init()
{
    // construct graph "tran"
    for (int station = 1; station <= m; ++station)
    {
        for (int l = 0; l < stat[station].size() - 1; ++l)
        {
            for (int r = l + 1; r < stat[station].size(); ++r)
            {
                ll line0 = stat[station][l].line, line1 = stat[station][r].line;
                tran[line0][line1] = tran[line1][line0] = stat[station][l].t + stat[station][r].t;
            }
        }
    }
    // then floyd
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i == k)
                continue;
            for (int j = 1; j <= n; ++j)
            {
                if (i == j && k == j)
                    continue;
                if (tran[i][j] > tran[i][k] + tran[k][j])
                {
                    tran[i][j] = tran[i][k] + tran[k][j];
                }
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%lld%lld%lld%lld%lld", &TESTCASE, &n, &m, &d, &q);
    w.resize(m + 1);
    stat.resize(m + 1);
    tran.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        tran[i].resize(n + 1, INF);
    for (int i = 1; i <= n; ++i)
        tran[i][i] = 0;
    for (int i = 1; i <= m; ++i)
        scanf("%lld", &w[i]);
    for (int i = 1; i <= n; ++i)
    {
        ll k, a, t;
        scanf("%lld", &k);
        for (int j = 0; j < k; ++j)
        {
            scanf("%lld%lld", &a, &t);
            stat[a].push_back(passway(i, t));
        }
    }
    init();
    while (q--)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        // determine which two lines take the shortest time
        ll travel = LLONG_MAX;
        for (int start = 0; start < stat[x].size(); ++start) // starting subway line #
        {
            for (int finish = 0; finish < stat[y].size(); ++finish) // finishing subway line #
            {
                ll line0 = stat[x][start].line, line1 = stat[y][finish].line;
                travel = min(travel, tran[line0][line1] + stat[x][start].t + stat[y][finish].t);
            }
        }
        printf("%lld\n", w[x] + w[y] + travel);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
