#include<bits/stdc++.h>
using namespace std;
const long long nx=1020;
struct node
{
    long long zd,l;
};
queue<long long>q1;
long long c,n,m,d,q,x,y,k,ans=1e9;
long long e[nx];
long long w[nx];
bool vis[nx][nx];
long long a[310][nx],t[310][nx];
vector<node>v[nx];
void dfs(long long now,long long lc)
{
    //cout<<now<<' '<<lc<<endl;
    if(now==y)
    {
        ans=min(ans,lc);
        return;
    }
    for(int i=0;i<v[now].size();i++)
    {
        if(vis[now][v[now][i].zd])continue;
        vis[now][v[now][i].zd]=1;
        vis[v[now][i].zd][now]=1;
        dfs(v[now][i].zd,lc+v[now][i].l);
        vis[now][v[now][i].zd]=0;
        vis[v[now][i].zd][now]=0;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }

    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j]>>t[i][j];
            e[a[i][j]]=j;
        }
        for(int j=1;j<=k;j++)
        {
            for(int j1=1;j1<=k;j1++)
            {
                if(a[i][j]!=a[i][j1])
                {
                    v[a[i][j]].push_back({a[i][j1],t[i][e[a[i][j]]]+t[i][e[a[i][j1]]]});
                }
            }
        }
    }
   // for(int i=1;i<=m;i++)
   // {
   //     for(int j=0;j<v[i].size();j++)
   //     {
   //         cout<<v[i][j].zd<<' '<<v[i][j].l<<endl;
   //     }
  //  }
    while(q--)
    {
        cin>>x>>y;
        memset(vis,0,sizeof vis);
        dfs(x,0);
        cout<<ans+w[x]+w[y]<<endl;
    }

    return 0;
}
