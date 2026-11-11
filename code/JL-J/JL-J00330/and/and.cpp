#include<bits/stdc++.h>;
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll n,m;
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        ll ans = a[1];
        for(int i=2;i<=n;i++){
            ans = ans & a[i];
        }
        cout<<ans;
    }else if(m==1){
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans,a[i]);
        }
        cout<<ans;
    }else{
        ll dp[n+10][m+10];
        memset(dp,0,sizeof(dp));

        dp[0][0]=a[1];
        for(int i=1;i<=n;i++){
            dp[i][1]=a[i];
            for(int j=m;j>=1;j--){
                dp[i][j]=max({dp[i-1][j],dp[i-1][j-1]&a[i],dp[i][j]});
            }
        }
        cout<<dp[n][m];
    }



    return 0;
}
