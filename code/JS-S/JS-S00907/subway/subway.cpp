#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 5e5 + 5;
const int N = 505;
const int INF = 0x3f3f3f3f;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];
vector<int> id[N];
vector<int> road[N];
set<int> road2[N];
bool vis[N];
void read(int &x)
{
    x = 0; int f = 1;
    char c = getchar();
    while(!isdigit(c)) f = c == '-' ? -1 : f,c = getchar();
    while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
    x *= f;
}
int step = INF;
void dfs2(int u,int v,int dep)
{
    if(dep > step) return;
    if(vis[u] || vis[v])
    {
        step = min(step,dep);
        return;
    }
    for(int xx : road[u])
    {
        vis[xx] = true;
        for(int yy : road[v])
        {
            vis[yy] = true;
            dfs2(xx,yy,dep + 1);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(c); read(n); read(m); read(d); read(q);
    for(int i = 1;i <= m;++i) read(w[i]);
    for(int i = 1;i <= n;++i)
    {
        read(k[i]);
        for(int j = 1;j <= k[i];++j)
        {
            read(a[i][j]); read(t[i][j]);
            id[a[i][j]].push_back(i);
        }
    }
    while(q--)
    {
        int x,y;
        read(x); read(y);
        ll ans = w[x] + w[y];
        for(int i = 1; i <= m;++i)
            for(int j : id[i])
            {
                for(int k : id[i])
                {
                    if(j == k) continue;
                    int xx = road2[j].size();
                    road2[j].insert(k);
                    if(xx != road2[j].size())
                    {
                        road[j].push_back(k);
                        road[k].push_back(j);
                    }
                }
            }
        for(int i : road[x])
        {
            memset(vis,0,sizeof vis);
            for(int j : road[y])
                dfs2(i,j,0);
        }
        ans += step * 2 * t[1][1];
        printf("%lld\n",ans);
    }
    return 0;
}
