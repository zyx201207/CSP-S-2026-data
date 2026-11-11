#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;
constexpr int N = 5007;
int c, t;
ll n, d, a[N];
bool vis[N];
vector<int> e[N];
struct Node
{
    int num, step;
    bool flag;
};
ll solve()
{
    ll res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            int mind = 0, nowi = i;
            do
            {
                nowi = min(e[nowi][e[nowi].size() - 1], j);
                mind++;
            } while (nowi < j);
            bool flag = false;
            queue<Node> q;
            q.push({i, 0, false});
            bool viss[5007][5007] = {{}};
            while (!q.empty())
            {
                int tn = q.front().num, ts = q.front().step;
                bool tf = q.front().flag;
                q.pop();
                if (ts > mind)
                    continue;
                for (int i : e[tn])
                    if (i > tn)
                    {
                        bool nf = viss[i][ts + 1];
                        if (tf && nf)
                            goto bad;
                        q.push({i, ts + 1, nf});
                        viss[i][ts + 1] = true;
                    }
            }
            res++;
bad:
            0;
        }
    return res;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            for (int j = 1; j < i; ++j)
                if (a[i] - a[j] <= d)
                    e[i].push_back(j), e[j].push_back(i);
        }
        cout << solve();
    }
    return 0;
}
