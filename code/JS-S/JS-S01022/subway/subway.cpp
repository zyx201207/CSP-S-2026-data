#include <bits/stdc++.h>

using namespace std;
long long c,n,m,d,q;
struct Edge{
    long long to,nxt,w;
};Edge e[50005];
long long head[1005],cnt,w[50006],k,dian[505][1005],num[5005],a[505][50005],value[505][50005],maxn=INT_MAX,lin_num[500005],s=0;
bool flag[100005][505],x;
void add(long long u,long long v,long long w)
{
    e[++cnt].w=w;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(long long u,long long v,long long line)
{
    if(u==v)
    {
        maxn=min(maxn,s+value[line][v]);
        return;
    }
    if(flag[u][line]==1 && x==0) return;
    x=0;
    if(line==0)
    {
        for(long long i=1;i<=m;i++)
        {
            bool f=0;
            for(long long j=1;j<=num[i];j++)
            {
                if(dian[u][j]==i)
                {
                    f=1;
                    break;
                }
            }
            if(f==1)
            {
                for(long long j=1;j<=lin_num[i];j++)
                {
                    s+=value[i][u];
                    flag[u][line]=1;
                    dfs(a[i][j],v,i);
                    flag[u][line]=0;
                    s-=value[i][u];
                }
            }
        }
    }
    else
    {
        for(long long i=1;i<=lin_num[line];i++)
        {
            flag[u][line]=1;
            dfs(a[line][i],v,line);
            flag[u][line]=0;
        }
        for(long long i=1;i<=num[u];i++)
        {
            if(dian[u][i]!=line)
            {
                s+=value[line][u]+value[dian[u][i]][u];
                flag[u][line]=1;
                dfs(u,v,dian[u][i]);
                flag[u][line]=0;
                s-=(value[line][u]+value[dian[u][i]][u]);
            }
        }
    }

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(long long i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(long long i=1;i<=m;i++)
    {
        cin>>k;
        for(long long j=1;j<=k;j++)
        {
            long long g,v;
            cin>>g>>v;
            a[i][j]=g;
            value[i][g]=v;
            dian[g][++num[g]]=i;
        }
        lin_num[i]=k;
    }
    while(q--)
    {
        maxn=INT_MAX;
        memset(flag,0,sizeof(flag));
        long long u,v;
        cin>>u>>v;
        s=0;
        for(long long i=1;i<=m;i++)
        {
            flag[u][i]=1;
        }
        x=1;
        dfs(u,v,0);
        cout<<maxn+w[u]+w[v]<<endl;
    }
    return 0;
}
