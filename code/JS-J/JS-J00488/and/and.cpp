#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],dp[200010],ans=INT_MIN;
void dfs(ll x,ll nans,ll summ){
    if(x==n+1){
        if(summ==m) ans=max(ans,nans);
        return;
    }
    if(summ==0) dfs(x+1,a[x],1);
    else dfs(x+1,nans&a[x],summ+1);
    dfs(x+1,nans,summ);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(ll i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans<<'\n';
        return 0;
    }
    if(m==2){
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                ans=max(a[i]&a[j],ans);
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(ll i=2;i<=n;i++) ans&=a[i];
        cout<<ans<<'\n';
        return 0;
    }
    dfs(1,0,0);
    cout<<ans<<'\n';
    return 0;
}
