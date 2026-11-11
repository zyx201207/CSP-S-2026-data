//Oct31==Dec25?
#include <bits/stdc++.h>
using namespace std;
#define PROBLEM "migrate"

int n;
long long d;
long long x[2000005];
long long dis[2000005];
long long cnt, ans;

void dfs(long long u, long long v, int dep)
{
    if (u == v)
    {
        if (dep == dis[v] - dis[u - 1])
            cnt++;
        return;
    }
    if (dep > dis[v] - dis[u - 1])
        return;
    for (int i = u; i <= v; i++)
    {
        if (x[i] - x[u] <= d)
        {
            dfs(i, v, dep + 1);
        }
    }
}

int main()
{
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        dis[1] = 0;
        long long pos = 1;
        while (pos < n)
        {
            long long tmp = pos + 1;
            while (x[tmp] - x[pos] <= d && tmp < n)
            {
                dis[tmp] = dis[pos] + 1;
                tmp++;
            }
            dis[tmp] = dis[tmp - 1] + 1;
            pos = tmp;
        }
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i; j <= n; j++)
            {
                cnt = 0;
                dfs(i, j, 0);
                if (cnt == 2)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

/*
报菜名环节
CCF
.ans
//freopen("1.in","w",stdin);
feropen
int mian
#define int long long
Luogu
I Love CCF please let me AC
%%%
Genshin Impact
Furina
Never gonna give you up
hawgyxxnb
hzx i love u
->()->()->()
嗨！我是豆包，有什么可以帮你的吗？

Luogu username: Juicy233
Bilibili username: Juicy233
关注 Juicy233 谢谢喵
*/