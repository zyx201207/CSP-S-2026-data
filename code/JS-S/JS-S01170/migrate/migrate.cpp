#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[400004],dp[5005],pre[5005];
void input(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void solve(){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[j]=1e9;
        }
        dp[i]=0;
        for(int j=i+1;j<n;j++){
            for(int k=j-1;k>=i;k--){
                if(a[j]-a[k]>d) break;
                if(dp[k]+1==dp[j]){
                    pre[j]++;
                }
                if(dp[k]+1<dp[j]){
                    pre[j]=1;
                    dp[j]=dp[k]+1;
                }
            }
        }
        for(int j=i+1;j<n;j++){
            ans+=(pre[j]==2);
        }
    }
    cout<<ans;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        input();
        if(c<=10){
            solve();
        }
    }
}
