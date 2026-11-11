#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        int n;ll d,ans=0;
        cin>>n>>d;
        vector<ll> x(n+1);
        for(int i=1;i<=n;i++) cin>>x[i];
        vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
        for(int i=1;i<=n;i++){
            dp.assign(n+1,vector<ll>(n+1,0));
            dp[i][0]=1;
            for(int j=i+1;j<=n;j++){
                for(int k=1;k<=j-i;k++){
                    for(int l=lower_bound(x.begin()+1,x.end(),x[j]-d)-x.begin();l<j;l++)
                    dp[j][k]+=dp[l][k-1];
                }
            }
            for(int j=i+1;j<=n;j++){
                for(int k=1;k<=n-i;k++){
                    if(dp[j][k]){
                        ans+=(dp[j][k]==2);
                        break;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}