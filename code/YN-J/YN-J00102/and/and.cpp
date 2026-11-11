#include <bits/stdc++.h>
#define N 200005
typedef long long ll;

int f(int x)
{
    int res = 0;
    while (x)
    {
        res += x & 1;
        x >>= 1;
    }
    return res;
}

bool cmp(int x, int y)
{
    return f(x) < f(y);
}
int n, m, a[N];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    std::sort(a + 1, a + n + 1, cmp);
    int res = a[n];
    for (int i = n - m + 1; i <= n; i++)
    {
        res = res & a[i];
    }
    printf("%d\n", res);
    return 0;
}
/*
#include <bits/stdc++.h>
#define N 200005
typedef long long ll;

int n, m, a[N], b[N];
std::vector<int> val[35];
std::set<int> s[2];
int x = 0;

int main()
{
    freopen("and1.in", "r", stdin);
    // freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    int id = 0;
    for (int j = 0; j <= 31; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((a[i] >> j) & 1)
            {
                val[j].push_back(i);
            }
        }
        if (val[j].size() >= m)
        {
            id = j;
        }
    }
    for (int v : val[id])
    {
        s[x].insert(v);
        // printf("%d ", v);
    }
    // s[!x] = s[x];
    // l[x] = val[id];
    for (int j = id - 1; j >= 0; j--)
    {
        // printf("ciallo");
        // s[x] = s[!x];
        s[!x] = s[x];
        std::set<int>().swap(s[x]);
        for (int v : val[j])
        {
            if (s[!x].find(v) != s[!x].end())
            {
                s[x].insert(v);
            }
        }
        if (s[x].size() < m)
        {
            x = !x;
            int ans = 0x7FFFFFFF;
            for (int v : s[x])
            {
                ans = ans & v;
                // printf("%d ", v);
            }
            printf("%d\n", ans);
            // printf("ddd %d\n", val[id - 1].size());
            return 0;
        }
    }
    return 0;
}
*/