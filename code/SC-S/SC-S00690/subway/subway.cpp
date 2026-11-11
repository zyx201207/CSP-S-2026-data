#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll jin[500005];
struct node{
    ll v,w;
};
vector<node>a[500005];
ll dp[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll c,n,m,d,q,s,t,k;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>jin[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>s>>t;
            a[s].push_back((node){i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)dp[i][j]=2e18;
        dp[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int len=a[i].size();
        for(int j=0;j<len-1;j++){
            for(int k=j+1;k<len;k++){
                dp[a[i][j].v][a[i][k].v]=min(dp[a[i][j].v][a[i][k].v],a[i][j].w+a[i][k].w);
                dp[a[i][k].v][a[i][j].v]=min(dp[a[i][k].v][a[i][j].v],a[i][j].w+a[i][k].w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        }
    }
    for(int i=1;i<=q;i++){
        ll u,v,minn=2e18;
        cin>>u>>v;
        ll len1=a[u].size(),len2=a[v].size();
        for(int j=0;j<len1;j++){
            for(int k=0;k<len2;k++){
                minn=min(minn,dp[a[u][j].v][a[v][k].v]+a[u][j].w+a[v][k].w+jin[u]+jin[v]);
            }
        }
        cout<<minn<<'\n';
    }
    return 0;
}