#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const long long N = 505;
const long long M = 1e3 + 5;
long long c,n,m,d,q,w[M],k[N],a[N][M],t[N][M];
struct node
{
    long long v,val;
};
vector<node> g[M];
long long f[M][M],vis[M];
int dfs(int x, int y)
{
    if(x == y) return 0;
    if(f[x][y] < 1e9) return f[x][y];
    for(node nxt : g[x])
    {
        if(!vis[nxt.v])
        {
            vis[nxt.v] = true;
            f[x][y] = min(f[x][y], nxt.val + dfs(nxt.v,y));
            vis[nxt.v] = false;
        }
    }
    return f[x][y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++) scanf("%lld", &w[i]);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%lld", &k[i]);
        for(int j = 1 ; j <= k[i] ; j++) scanf("%lld%lld", &a[i][j], &t[i][j]);
        for(int j = 1 ; j <= k[i] ; j++)
        {
            for(int u = 1 ; u <= k[i] ; u++)
            {
                if(j == u) continue;
                g[a[i][j]].push_back({a[i][u], t[i][j] + t[i][u]});
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    for(int i = 1 ; i <= m ; i++) f[i][i] = 0;
    for(int i = 1 ; i <= m ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(f[i][j] < 1e9) continue;
            f[i][j] = dfs(i,j);
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        cout << f[x][y] + w[x] + w[y] << '\n';
    }
    return 0;
}
