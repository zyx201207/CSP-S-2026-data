#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
long long a[2000005], n, d, t, _, ext[2000005];
bool bfs(long long s, long long t)
{
    long long mindis = 0x3f3f3f3f3f3f3f3f, routes = 0;
    queue <pair <long long, long long> > q;
    q.push({s, 0});
    while (!q.empty())
    {
        auto [u, l] = q.front();
        q.pop();
        if (l > mindis)
        {
            continue;
        }
        if (u == t)
        {
            if (mindis == 0x3f3f3f3f3f3f3f3f)
            {
                mindis = l;
            }
            routes++;
            continue;
        }
        else if (u > t)
        {
            continue;
        }
        for (long long v = u+1; v <= ext[u]; v++)
        {
            q.push({v, l+1});
        }
    }
    return (routes == 2);
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> _ >> t;
    while (t--)
    {
        cin >> n >> d;
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (long long i = 1; i <= n; i++)
        {
            ext[i] = upper_bound(a+1, a+n+1, a[i]+d)-a-1;
        }
        long long sum = 0;
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = i+1; j <= n; j++)
            {
                sum += bfs(i, j);
            }
        }
        cout << sum  << "\n";
    }
    return 0;
}
