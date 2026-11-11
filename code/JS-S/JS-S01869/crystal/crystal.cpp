#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[501111];
ll d[501111];
ll dx[501111];
ll xx;
ll n,m;
ll ans=1;
ll ddx[501111];
ll dp[501111];
bool cmp(ll x,ll y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dx[i]=a[i]-a[i-1];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ddx[j]=abs(a[i]-a[j]);
            }
            sort(ddx+1,ddx+n+1,cmp);
            ll mm=m;
            ll k=1;
        while(mm>=0){
            if(mm-ddx[k]>=0){
                dp[i]++;
                mm-=ddx[k];
                k++;
            }
            else break;
        }
        dp[i]=max(dp[i-1],dp[i]);
    }
    cout<<dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
