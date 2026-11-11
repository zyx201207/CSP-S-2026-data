#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll rd()
{
    ll a = 0, q = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
        {
            q = -1;
        }
        ch = getchar();
    }
    while (isdigit(ch))
    {
        a = (a << 3) + (a << 1) + (ch ^ 48);
        ch = getchar();
    }
    return a * q;
}
int c, T, n, k;
int fa[4010], so[4010];
vector<int> t[1000010];
void dfs(int s)
{
    for (auto v : t[s])
    {
        if (fa[s] != v)
        {
            fa[v] = s;
            dfs(v);
            so[s] += so[v] + 1;
        }
    }
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    c = rd(), T = rd();
    while(T--)
    {
        n = rd(), k = rd();
        for (int i = 1; i < n; i++)
        {
            int u, v;
            u = rd();v = rd();
            t[u].push_back(v);
            t[v].push_back(u);
        }
        /*int ans = n;
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            dfs(i);
            int d = -1, dd = -1, ma;
            for (auto v : t[i])
            {
                if (so[v] > ma)
                {
                    d = v;
                    dd = d;
                }
            }
        }*/
        cout << k - 1 << endl;
    }
    return 0;
}
