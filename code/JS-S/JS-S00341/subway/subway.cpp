#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,d,q,ans=1000,c;
int a[N][N];
bool vis1[N],vis2[N];
vector<int> dt[N];
vector<int> zh[N];
void dfs(int c,int u,int v,int s)
{
    if(u==v&&c%2)
    {
        ans=min(ans,s);
        return;
    }
    if(c%2)
    {
        vis1[u]=1;
        for(int i=0;i<dt[u].size();i++)
        {
            if(vis2[dt[u][i]]!=1)
            {
                vis2[dt[u][i]]=1;
                dfs(c++,dt[u][i],v,s+=a[dt[u][i]][u]);
                vis2[dt[u][i]]=0;
            }

        }
    }
    else
    {
        vis2[u]=1;
        for(int i=0;i<zh[u].size();i++)
        {
            if(vis1[zh[u][i]]!=1)
            {
                vis1[zh[u][i]]=1;
                dfs(c++,zh[u][i],v,s+=a[u][zh[u][i]]);
                vis1[zh[u][i]]=0;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[0][i];
    }
    int k,k1,k2;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>k1>>k2;
            a[i][k1]=k2;
            dt[k1].push_back(i);
            zh[i].push_back(k1);
        }
    }
    while(q--)
    {
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        int u,v;
        cin>>u>>v;
        dfs(1,u,v,0);
        cout<<ans+a[0][u]+a[0][v]<<endl;
    }
    return 0;
}
