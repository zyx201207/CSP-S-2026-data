#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[505][505],w[500010];
vector<pair<int,int> > po[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=4e18;
        }
        dp[i][i]=0;
    }
    signed u,v,k;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            scanf("%d%d",&u,&v);
            po[u].push_back({i,v});
        }
    }//500005
    for(int i=0;i<m;i++){
        for(int j=0;j<po[i].size();j++){
            for(int k=j+1;k<po[i].size();k++){
                dp[po[i][j].first][po[i][k].first]=min(po[i][j].second+po[i][k].second,dp[po[i][j].first][po[i][k].first]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=min(dp[i][j],dp[j][i]);
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    int ans,s,t;
    while(q--){
        cin>>s>>t;
        ans=8e18;
        for(int i=0;i<po[s].size();i++){
            for(int j=0;j<po[t].size();j++){
                ans=min(ans,dp[po[s][i].first][po[t][j].first]+po[s][i].second+po[t][j].second);
            }
        }
        cout<<ans+w[s]+w[t]<<"\n";
    }
}
