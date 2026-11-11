#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N = 2e6+5;
ll x[N];
bool p[5005];
int dp[5005][5005];
int s[5005][5005];
ll c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c>=11&&c<=12){
            int a=x[2]-x[1];
            cout<<a<<" ";
            if(d>=2*a&&d<3*a){
                cout<<n-3<<" "<<max(0ll,n-3)<<'\n';
            }
            else cout<<0<<'\n';
        }
        else {
            ll ans=0;
            memset(dp,0x3f,sizeof(dp));memset(s,0,sizeof(s));memset(p,0,sizeof(p));
            for(int l=2;l<=n;l++){
                for(int i=1;i+l-1<=n;i++){
                    if(p[i])continue;
                    int j=i+l-1;
                    if(x[j]-x[i]<=d)dp[i][j]=1,s[i][j]=1;
                    else{
                        for(int k=i+1;k<j;k++){
                            if(dp[i][k]+dp[k][j]<dp[i][j])dp[i][j]=dp[i][k]+dp[k][j],s[i][j]=min(s[i][k]*s[k][j],3);
                            else if(dp[i][k]+dp[k][j]==dp[i][j])s[i][j]=min(s[i][j]+s[i][k]*s[k][j],3);
                        }
                    }
                    if(s[i][j]==3)p[i]=1;
                    ans+=s[i][j]==2;
                }
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}
