#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q,ext[550000],dis[550][550],dp[550][550];
vector<array<int,2>>val[550000];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>ext[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int v,w;
            cin>>v>>w;
            val[v].push_back({i,w});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;++i){
        for(auto j:val[i]){
            for(auto k:val[i]){
                if(j==k){
                    dis[j[0]][j[0]]=0;
                }
                else{
                    dis[j[0]][k[0]]=min(dis[j[0]][k[0]],j[1]+k[1]);
                    dis[k[0]][j[0]]=min(dis[k[0]][j[0]],j[1]+k[1]);
                }
            }
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dp[i][j]=dis[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
    for(int i=1;i<=q;++i){
        int x,y,ans=2e18;
        cin>>x>>y;
        for(auto j:val[x]){
            for(auto k:val[y]){
                ans=min(ans,dp[j[0]][k[0]]+j[1]+k[1]+ext[x]+ext[y]);
            }
        }
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}
