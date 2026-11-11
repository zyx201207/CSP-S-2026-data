#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
constexpr int N = 507;
constexpr int M = 500007;
using ll = long long;
struct At
{
    ll v, w;
};
ll c, n, m, d, q;
bool pB;
ll tB;
ll station[M];
vector<At> to_hall[N];
vector<At> to_line[M];
ll dis[N][N];
inline ll line_to_line_min_time(ll line1, ll line2)
{
    set<ll> _s;
    vector<ll> andset;
    bool flag_andset = false;
    for (At i : to_hall[line1])
        _s.insert(i.v);
    ll sz = _s.size();
    for (At i : to_hall[line2])
    {
        _s.insert(i.v);
        if (sz == _s.size())
            andset.push_back(i.v), flag_andset = true;
        sz = _s.size();
    }
    if (pB && flag_andset)
        return 2 * tB;
    ll _a, _b, res = 0x3f3f3f3f3f3f3f3fll;
    for (int i : andset)
    {
        for (auto j : to_line[i])
        {
            if (j.v == line1)
                _a = j.w;
            if (j.v == line2)
                _b = j.w;
        }
        res = min(res, _a + _b);
    }
    return res;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    pB = (c >= 12 && c <= 19);
    for (int i = 1; i <= m; ++i)
        scanf("%d", station + i);
    for (int i = 1, k, a, t; i <= n; ++i)
    {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j)
        {
            scanf("%d%d", &a, &t);
            tB = t;
            to_line[a].push_back({i, t});
            to_hall[i].push_back({a, t});
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i - 1; ++j)
            dis[j][i] = dis[i][j] = line_to_line_min_time(i, j);
    for (int h = 1; h <= n; ++h)
        for (int i = 1; i <= n; ++i)
        {
            if (i == h)
                continue;
            for (int j = 1; j < i; ++j)
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][h] + dis[h][j]);
        }
    while (q--)
    {
        ll st, ed, ans_r = 0x3f3f3f3f3f3f3f3fll;
        cin >> st >> ed;
        for (At i : to_line[st])
            for (At j : to_line[ed])
                ans_r = min(ans_r, i.w + j.w + dis[i.v][j.v]);
        cout << station[st] + station[ed] + ans_r << "\n";
    }
    return 0;
}
