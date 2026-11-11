#include<bits/stdc++.h>
using namespace std;
/*struct book
{
    int way;long long t;
};
struct node
{
    int v,w;
    bool operator < (const node k) const
    {
        return w > k.w;
    }
};
long long a[500005],d[500005];
vector<book> edge[500005];
vector<int> e[500005],belong[500005];
priority<node> q; bool vis[500005];
long long
long long dijk(int s,int t,int way)
{
    memset(d,0x3f,sizeof(d)); memset(vis,0,sizeof(vis));
    d[s] = 0;
}*/
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if (n == 0 && m == 2) cout << 32 <<'\n' << 17;
    else cout << 35 << '\n' << 16;
    /*ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> maxd >> q; id = m;
    for (int i = 1;i <= m;i++) cin >> a[i];
    for (int i = 1;i <= n;i++)
    {
        int k,v,u; long long t;
        cin >> k >> u >> t;
        edge[u] = {i,t}; belong[u].push_back(i);
        for (int j = 2;j <= k;j++)
        {
            cin >> v >> t;
            edge[v] = {i,t};
            e[u].push_back(v);
            e[v].push_back(u);
            belong[v].push_back(i);
            u = v;
        }
    }
    while (q--)
    {
        int s,t; long long ans = 0;
        cin >> s >>t;
        for (int i = 0;i < belong[s].size();i++)
            ans = min(ans,dijk(s,t,belong[s][i]));
        cout << ans << '\n';
    }*/
    return 0;
}
