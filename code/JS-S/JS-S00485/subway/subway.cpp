#include<bits/stdc++.h>
using namespace std;
const int maxm=500001,maxn=501;
int c,n,m,d,q,w[maxm],k[maxn];
long long dis[maxn][maxn],ans;
bool vis[maxn];
vector<pair<int,int>> g[maxn],a[maxm];
void pre()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
void solve(int x,int y)
{
    long long ans=1e18;
    for(auto e:a[x])
    {
        int i1=e.first,j1=e.second;
        for(auto e2:a[y])
        {
            int i2=e2.first,j2=e2.second;
            int t1=g[i1][j1].second,t2=g[i2][j2].second;
            // cout<<i1<<" "<<i2<<" "<<j1<<" "<<j2<<" "<<t1<<" "<<t2<<" "<<dis[i1][i2]<<'\n';
            ans=min(ans,dis[i1][i2]+t1+t2);
        }
    }
    ans+=w[x]+w[y];
    cout<<ans<<'\n';
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            int x,t;
            cin>>x>>t;
            g[i].push_back({x,t});
            a[x].push_back({i,j});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                dis[i][j]=1e18;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            for(int z=j+1;z<a[i].size();z++)
            {
                int i1=a[i][j].first,j1=a[i][j].second;
                int i2=a[i][z].first,j2=a[i][z].second;
                int t1=g[i1][j1].second,t2=g[i2][j2].second;
                dis[i1][i2]=dis[i2][i1]=min(dis[i1][i2],(long long)t1+t2);
            }
        }
    }
    pre();
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/