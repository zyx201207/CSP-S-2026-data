#include<bits/stdc++.h>
using namespace std;
int n,d;
const int MAXN=2e6+10;
typedef long long ll;
ll a[MAXN];
ll dp[MAXN];
ll cnt[MAXN];
ll solve(int k){
    for(int i=k;i<=n;i++){
        dp[i]=LLONG_MAX;
        cnt[i]=0;
    }
    dp[1]=0;
    for(int i=k;i<=n;i++){
        for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++){
            if(dp[j]==dp[i]+1)cnt[j]++;
            else if(dp[j]>dp[i]+1){
                dp[j]=dp[i]+1;
                cnt[j]=1;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==2)ans++;
    }
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    //freopen("mi.in","r",stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll ans=0;
        for(int i=1;i<=n;i++)ans+=solve(i);
        cout<<ans<<endl;
    }
    return 0;
}