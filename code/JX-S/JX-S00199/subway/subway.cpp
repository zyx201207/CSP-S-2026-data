#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL c,n,m,d,q,w[500005],k[505],dp[505][505];
struct edg{
    LL lin,co;
};
vector<edg> e[500005];

int main(){
    memset(dp,0x3f,sizeof(dp));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            e[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
       int si=e[i].size();
       for(int j=0;j<si;j++){
           for(int h=j+1;h<si;h++){
               dp[e[i][j].lin][e[i][h].lin]=min(dp[e[i][j].lin][e[i][h].lin],e[i][j].co+e[i][h].co);
               dp[e[i][h].lin][e[i][j].lin]=dp[e[i][j].lin][e[i][h].lin];
           }
       }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int h=1;h<=n;h++){
                dp[i][h]=min(dp[i][h],dp[i][j]+dp[j][h]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //        cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        int x,y;
        LL ans=1e18;
        cin>>x>>y;
        int sx=e[x].size(),sy=e[y].size();
        for(int i=0;i<sx;i++){
            for(int j=0;j<sy;j++){
                ans=min(ans,w[x]+e[x][i].co+dp[e[x][i].lin][e[y][j].lin]+e[y][j].co+w[y]);
            }
        }
       // cout<<w[x]+e[x][1].co+dp[e[x][1].lin][e[y][j].lin]+e[y][1].co+w[y]<<'\n';
        cout<<ans<<'\n';
    }
   
    return 0;
}