#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,m,n,d,q;
int w[500005],dp[505][505];
set<int> path[500005];
map<pair<int,int>,int>pw;
void work(){
    int x,y,ans=LLONG_MAX;
    cin>>x>>y;
    for(auto i:path[x]){
        for(auto j:path[y]){
            ans=min(ans,dp[i][j]+pw[make_pair(i,x)]+pw[make_pair(j,y)]+w[x]+w[y]);
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++){
        cin>>w[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) dp[i][j]=0;
            else{
                dp[i][j]=INT_MAX;
                dp[i][j]<<=5;
            }
        }
    }
    for(int i=1; i<=n; i++){
        int z; cin>>z;
//        cout<<i<<" "<<z<<"\n";
        for(int j=1; j<=z; j++){
            int y1,y2; cin>>y1>>y2;
            pw[make_pair(i,y1)]=y2;
            path[y1].insert(i);
//            cout<<y1<<"\n";
//            for(auto j:path[y1]){
//                cout<<j<<" ";
//            }
//            cout<<"\n";
        }
    }
    for(int i=1; i<=m; i++){
        for(auto j:path[i]){
            for(auto k:path[i]){
                if(j==k) continue;
                dp[j][k]=dp[k][j]=min(dp[j][k],pw[make_pair(j,i)]+pw[make_pair(k,i)]);
//                cout<<i<<" "<<j<<" "<<k<<" "<<pw[make_pair(j,i)]<<" "<<pw[make_pair(k,i)]<<"\n";
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]=dp[j][i];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                dp[j][k]=min(dp[j][k],min(dp[i][j],dp[j][i])+min(dp[i][k],dp[k][i]));
            }
        }
    }
    while(q--){
        work();
    }
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
    return 0;
}
