#include <iostream>

using namespace std;

//首先我们思考怎么样是最短的，就是贪心，跳多远就多远？
/*
确实是对的，因为 d 的性质
换言之然后一对我们都可以知道最短是多少
假设这一对之间的距离是 dist，那就要 dist/d 上取整
然后你会有除不尽的情况，可以操作，

思考一下可行性，就是如果一个点距离左边一个点 >d 那路线在这里就断了
所以我们可以保证两两之间都可达，其次任意两点之间距离 <= d
发现产生浪费的原因是终点比较近
*/

namespace P40
{
    const int N = 2000005;
    typedef pair<int, int> PII;
    typedef long long LL;

    LL pos[N]; int q[N], hh, tt;
    int d[N], e[N]; int sum[N];

    void solve()
    {
        int ans = 0;

        int n; LL dist; cin >> n >> dist;
        for (int i = 1; i <= n; i++) cin >> pos[i];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) d[j] = e[j] = 0;
            for (int j = 0; j <= n; j++) sum[j] = 0;

            hh = 0, tt = -1;
            q[++tt] = i; d[i] = 1; sum[0] = 1;
            for (int j = i + 1; j <= n; j++)
            {
                while (hh <= tt && pos[j] - pos[q[hh]] > dist)
                    sum[e[q[hh]]] -= d[q[hh]], hh++;
                if (sum[e[q[hh]]] <= 2)
                {
                    d[j] = sum[e[q[hh]]];
                    int newe = e[q[hh]] + 1;

                    while (hh <= tt && newe < e[q[tt]])
                        sum[e[q[tt]]] -= d[q[tt]], tt--;

                    q[++tt] = j; e[j] = newe;
                    sum[newe] += d[j];

                    if (d[j] == 2) ans++;
                }

            }
        }

        cout << ans << '\n';
    }
}

namespace B
{
    const int N = 2000005;
    typedef long long LL;

    LL pos[N];

    void solve()
    {
        int n; LL dist; cin >> n >> dist;
        for (int i = 1; i <= n; i++) cin >> pos[i];

        cout << 0 << '\n';
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    int c, t; cin >> c >> t;
    if (c <= 10)
    {
        while (t--) P40::solve();
    }
    else if (c == 13 || c == 14)
    {
        while (t--) B::solve();
    }
    return 0;
}
