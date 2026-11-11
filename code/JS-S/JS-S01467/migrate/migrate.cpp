#include<bits/stdc++.h>
#define int long long 
using namespace std;
int x[2000005];
int n,d;
int dp[5005][5005];
int minn[5005][5005];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    memset(dp,0x3f,sizeof(dp));
    memset(minn,0x3f,sizeof(minn));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]<=d){
                dp[i][j]=1;
                minn[i][j]=1;
            }
            else break;
        } 
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(minn[i][k]+minn[k][j]<minn[i][j]){
                    minn[i][j]=minn[i][k]+minn[k][j];
                    dp[i][j]=dp[i][k]*dp[k][j];
                }
                else if(minn[i][k]+minn[k][j]==minn[i][j]){
                    dp[i][j]+=dp[i][k]*dp[k][j];
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(dp[i][j]==2) ans++;
        }
    }
    cout<<ans<<"\n";
}
void solve2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    cout<<0<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    if(c<=6) while(t--) solve();
    else while(t--) solve2();
    return 0;
}