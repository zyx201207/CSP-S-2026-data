#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int c, t, n;
long long d, x;
vector<long long> farthest;
queue<long long> cls;
long long ans;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        ans = 0;
        scanf("%d%lld", &n, &d);
        farthest.clear();
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &x);
            while (!cls.empty() && x - cls.front() > d)
            {
                farthest.emplace_back(i - 1);
                cls.pop();
            }
            cls.emplace(x);
        }
        while (!cls.empty())
        {
            farthest.emplace_back(n - 1);
            cls.pop();
        }
        for (int i = 0; i < n; ++i)
        {
            int mid = farthest.at(i);
            if (mid > i + 1)
                ans += (farthest.at(mid - 1) - farthest.at(mid - 2));
        }
        printf("%lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
