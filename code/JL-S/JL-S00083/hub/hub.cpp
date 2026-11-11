#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,x,y;
int cccc,t,b[N],par[N],f[N][20],dep[N],ans=1e18;
vector<int>v[N],d;
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    for(int i=0;i<=19;i++) f[x][i+1]=f[f[x][i]][i];
    for(int i=0;i<v[x].size();i++)
    {
        if(fa==v[x][i]) continue;
        f[v[x][i]][0]=x;
        dfs(v[x][i],x);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
        if(x==y) return x;
    }
    for(int i=20;i>=0;i--)
    {
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
int dist(int x,int y)
{
    int l=lca(x,y);
    return dep[x]+dep[y]-dep[l]*2;
}
int getroot(int x)
{
    if(par[x]==-1) return x;
    par[x]=getroot(par[x]);
    return par[x];
}
bool un(int x,int y)
{
    int f1=getroot(x),f2=getroot(y);
    if(f1==f2) return false;
    par[f1]=f2;
    return true;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&cccc,&t);
    while(t--)
    {
        for(int i=1;i<=n;i++) v[i].clear();
        scanf("%lld%lld",&n,&m);ans=1e18;
        for(int i=1;i<n;i++)
        {
            scanf("%lld%lld",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        f[1][0]=1;
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
            if(i<=m) b[i]=1;
            else b[i]=0;
        }
        do
        {
            d.clear();
            for(int i=1;i<=n;i++)
            {
                if(b[i]) d.push_back(i);
                par[i]=-1;
            }
            for(int i=0;i<d.size();i++)
            {
                for(int j=0;j<d.size();j++)
                {
                    if(i==j) continue;
                    if(dist(i,j)==1) un(i,j);
                }
            }
            int cnt=0,dt,dd=-1e18;
            for(int i=0;i<d.size();i++)
            {
                if(par[d[i]]==-1) cnt++;
            }
            if(cnt!=2) continue;
            for(int i=1,j;i<=n;i++)
            {
                dt=1e18;
                for(j=0;j<d.size();j++)
                {
                    if(i==d[j]) break;
                }
                if(j!=d.size()) continue;
                for(j=0;j<d.size();j++)
                {
                    dt=min(dt,dist(i,d[j]));
                }
                dd=max(dd,dt);
            }
            for(int j=0;j<d.size();j++) printf("%lld ",d[j]);
            printf(":is one solution----%lld\n",dd);
            ans=min(ans,dd);
        }while(prev_permutation(b+1,b+1+n));
        printf("%lld\n",ans);
    }
}
