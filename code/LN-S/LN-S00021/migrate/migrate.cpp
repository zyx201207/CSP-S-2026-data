#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,NN=305,INF=1e18;
int dp[NN][NN],dis[NN][NN];
int n,d,x[N],ans;
void solve1(){
    ans=0;
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        cin >> x[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dis[i][j]=0;
                dp[i][j]=1;
                continue;
            }
            dis[i][j]=dp[i][j]=INF;
        }
    }
    for(int len=1;len<n;len++){
        for(int lf=1;lf+len<=n;lf++){
            int rt=lf+len,cdp=0;
            if(x[rt]-x[lf]<=d){
                dis[lf][rt]=dp[lf][rt]=1;
                continue;
            }
            for(int k=lf+1;k<rt;k++){
                if(dis[lf][rt]>dis[lf][k]+dis[k][rt]){
                    dis[lf][rt]=dis[lf][k]+dis[k][rt];
                    cdp=dp[lf][k]*dp[k][rt];
                    // cout << cdp << " " << dp[lf][k] << " " << dp[k][rt] << " " << lf << " " << k << " " << rt << "\n";
                }
                else if(dis[lf][rt]==dis[lf][k]+dis[k][rt]){
                    cdp+=dp[lf][k]*dp[k][rt];
                    // cout << cdp << " " << dp[lf][k] << " " << dp[k][rt] << " " << lf << " " << k << " " << rt << "\n";
                }
            }
            dp[lf][rt]=cdp;
            // cout << lf << " " << rt << " " << cdp << "\n";
            if(cdp==2){
                ans++;
            }
        }
    }
    // cout << dp[1][1] << "\n";
    cout << ans << "\n";
}
void solve2(){
    ans=0;
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> x[i];
    int k=d/(x[2]-x[1]);
    if(k<=1) cout << "0\n";
    else cout << max(0ll,n-2*k+1) << "\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin >> c >> T;
    if(c<=6){
        while(T--) solve1();
    }
    else if(11<=c&&c<=12){
        while(T--) solve2();
    }
    return 0;
}