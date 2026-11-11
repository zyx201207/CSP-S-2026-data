#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m;
int a[N];
deque < int > q;

int solve()
{
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (q.empty())
        {
            q.push_back(i);
            continue;
        }
        int len = q.size(), d = a[i] - a[i - 1];
        res = max(res, len);
        while (cnt + len * d > m)
        {
            cnt -= (a[i] - a[q.front()]);
            q.pop_front();
        }
        cnt += len * d;
        q.push_back(i);
    }
    return res;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = solve();
    printf("%lld\n", ans);
    return 0;
}
