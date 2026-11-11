#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
int c,n,m,d,q;
vector<int> v[maxn];
ll dis[505][505],w[maxn],t[maxn][25],cnt[maxn],b[maxn];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,h;
            cin>>x>>h;
            v[x].push_back(i);
            b[cnt[x]]=i;
            t[x][cnt[x]]=h;
            cnt[x]++;
        }
    }
    for(int i=0;i<=501;i++)
    {
        for(int j=0;j<=501;j++)
        {
            dis[i][j]=5e17;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            for(int k=j+1;k<v[i].size();k++)
            {
                ll ret=t[i][j]+t[i][k];
                dis[v[i][j]][v[i][k]]=min(dis[v[i][j]][v[i][k]],ret);
                dis[v[i][k]][v[i][j]]=dis[v[i][j]][v[i][k]];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==k)
                continue;
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        ll ans=1e18;
        cin>>x>>y;
        for(int j=0;j<v[x].size();j++)
        {
            for(int k=0;k<v[y].size();k++)
            {
                ans=min(ans,w[x]+w[y]+t[x][j]+t[y][k]+dis[v[x][j]][v[y][k]]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
