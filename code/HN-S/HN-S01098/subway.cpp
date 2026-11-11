#include<bits/stdc++.h>
#define int long long
#define pii pair <int ,int >
using namespace std;
const int N=500,M=5e5,inf=1e18;
int c,n,m,d,_;
int dis[N+5][N+5];
int w[M+5];
vector <pii > q[M+5];
void ckmin(int &x,int k){if(k<x) x=k;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>_;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) dis[i][j]=inf;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int x,y,t;cin>>x;
        for(int j=1;j<=x;j++) cin>>y>>t,q[y].push_back({i,t});
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<q[i].size();j++)
            for(int x=j+1;x<q[i].size();x++)
            {
                pii u=q[i][j],v=q[i][x];
                ckmin(dis[u.first][v.first],u.second+v.second);
                ckmin(dis[v.first][u.first],u.second+v.second);
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int x=1;x<=n;x++)
                if(dis[i][x]!=inf&&dis[x][j]!=inf)
                    ckmin(dis[i][j],dis[i][x]+dis[x][j]);
    for(int i=1;i<=_;i++)
    {
        int x,y;cin>>x>>y;int ans=inf;
        if(x==y) {cout<<"0\n";continue;}
        for(int i=0;i<q[x].size();i++)
            for(int j=0;j<q[y].size();j++)
            {
                pii u=q[x][i],v=q[y][j];
                if(dis[u.first][v.first]==inf) continue;
                ckmin(ans,dis[u.first][v.first]+w[x]+w[y]+u.second+v.second);
            }
        cout<<ans<<"\n";
    }
}