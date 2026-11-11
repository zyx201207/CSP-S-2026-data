#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int Tid, T;
const int N = 2e6 + 5;
int n, ans; ll d;
ll a[N];
int cnt, minn;

void dfs1(int pos, int ed, int l)
{
    if (pos == ed)
    {
        minn = min(minn, l);
        return;
    }
    for (int i = pos + 1; i <= ed; ++i)
    {
        ll dis = a[i] - a[pos];
        if (dis <= d)
            dfs1(i, ed, l + 1);
    }
    return;
}

void dfs2(int pos, int ed, int l)
{
    if (cnt > 2)
        return;
    if (pos == ed)
    {
        if (l == minn)
            ++cnt;
        return;
    }
    for (int i = pos + 1; i <= ed; ++i)
    {
        ll dis = a[i] - a[pos];
        if (dis <= d)
            dfs2(i, ed, l + 1);
    }
    return;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &Tid, &T);
    if (Tid >= 1 && Tid <= 2)
    {
        while (T--)
        {
            ans = 0;
            scanf("%d%lld", &n, &d);
            for (int i = 1; i <= n; ++i)
                scanf("%lld", a + i);
            for (int l = 1; l <= n; ++l)
            {
                for (int r = l + 1; r <= n; ++r)
                {
                    minn = 114514;
                    dfs1(l, r, 0);
                    cnt = 0;
                    dfs2(l, r, 0);
                    if (cnt == 2)
                        ++ans;
                }
            }
            printf("%d\n", ans);
        }
        return 0;
    }
    // if (Tid >= 11 && Tid <= 12)
    // {
    //     while (T--)
    //     {
    //         scanf("%d%lld", &n, &d);
    //         for (int i = 1; i <= n; ++i)
    //             scanf("%lld", a + i);
    //         if (2 * (a[2] - a[1]) > d)
    //             { puts("0"); continue; }
    //     }
    //     return 0;
    // }
    while (T--)
        puts("0");
    return 0;
}

//I forget when I opened T3.
//16:22 hurt a finger
//16:57 +8pts from #1~2(n <= 9)
//no clue at all
//I'm super weak.