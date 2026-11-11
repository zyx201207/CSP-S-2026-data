#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N =2e6+5;
ll c=0,n=0,d=0,T=0,ans=0;
ll a[N],dp[5005][5005],nm[5005][5005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        memset(dp,0,sizeof(dp));
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            nm[i][i]=1;
        }
        ans=0;
        for(ll l=1;l<=n;l++){
            for(ll r=l+1;r<=n;r++){
                ll mn=2e18,cnt=0;
                for(ll i=r-1;i>=l;i--){
                    if(a[r]-a[i]>d){
                        break;
                    }
                    if(dp[l][i]<mn){
                        mn=dp[l][i];
                        cnt=nm[l][i];
                    }
                    else if(dp[l][i]==mn){
                        cnt+=nm[l][i];
                    }
                }
                dp[l][r]=mn+1;
                nm[l][r]=cnt;
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
