#include <bits/stdc++.h>
using namespace std;

const unsigned int MAXN = 500005;
int n, m;
int a[MAXN], dis[MAXN];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, cmp);

    // 构造2层数据dis
    for (int i = 1; i <= n - 1; i++)
    {
        dis[i] = a[i] - a[i + 1];
    }

    int maxn = -0x3f3f3f, ans = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            dis[j] = dis[j] + dis[j + 1];
        }
        if (dis[i] <= m && dis[i] > maxn)
        {
            ans = i + 2;
            maxn = dis[i];
        }
    }

    cout << ans << endl;

    return 0;
}
