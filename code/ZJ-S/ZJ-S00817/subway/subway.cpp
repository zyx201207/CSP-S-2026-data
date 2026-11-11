#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500005],k[505],dp[505][505];
struct node{int x;ll w;};
vector<node>vec[500005];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int u,w;
            cin>>u>>w;
            vec[u].push_back({i,w});
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;i++)
    for(int j=0;j<vec[i].size();j++)
    for(int k=j+1;k<vec[i].size();k++)
    {
        dp[vec[i][j].x][vec[i][k].x]=min(dp[vec[i][j].x][vec[i][k].x],vec[i][j].w+vec[i][k].w);
        dp[vec[i][k].x][vec[i][j].x]=min(dp[vec[i][k].x][vec[i][j].x],vec[i][j].w+vec[i][k].w);
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
        dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
    for(;q--;)
    {
        int l,r;
        cin>>l>>r;
        ll ans=9e16;
        for(node i:vec[l])
        for(node j:vec[r])
            ans=min(ans,dp[i.x][j.x]+i.w+j.w+w[l]+w[r]);
        cout<<ans<<"\n";
    }
}