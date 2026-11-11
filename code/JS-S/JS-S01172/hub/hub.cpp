#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 5e5 + 8, INF = 0x3f3f3f3f3f3f3f3f;
LL c, n, m, d, q, w[N], k[505], dis[505][505];
bool vis[N];
vector<LL> a[N], t[N];
vector<pair<LL, LL>> edgs[N];
inline LL read()
{
    LL num = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while('0' <= ch && ch <= '9')
    {
        num = (num << 3) + (num << 1) + ch - '0';
        ch = getchar();
    }
    return (f == 1 ? num : -num);
}
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
void topposort(LL st)
{
    memset(vis, false, sizeof(vis));
    queue<LL> q;
    q.push(st);
    vis[st] = true;
    dis[st][st] = 0;
    while(!q.empty())
    {
        LL u = q.front();
        q.pop();
        for(auto [v, wv] : edgs[u])
        {
            if(dis[st][v] > dis[st][u] + wv)
            {
                dis[v][st] = dis[st][v] = dis[st][u] + wv;

            }                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
        }
    }
    return ;
}
LL solve(LL s, LL e)
{
    if(dis[s][e] < INF)
    {
        return dis[s][e] + w[s] + w[e];
    }
    topposort(s);
    return dis[s][e] + w[s] + w[e];
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    memset(dis, INF, sizeof(dis));
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        w[i] = read();
    }
    for(int i = 1; i <= n; i++)
    {
        k[i] = read();
        for(int j = 1; j <= k[i]; j++)
        {
            LL ai, ti;
            ai = read(), ti = read();
            a[i].push_back(ai);
            t[i].push_back(ti);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

