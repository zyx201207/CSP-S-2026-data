#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
ll pre[500005];
ll n,m;
int solve(ll idx,ll x){
    ll l=1,r=idx,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if((idx-mid+1)*x-(pre[idx]-pre[mid-1])<=m){
            ans=idx-mid+1;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(i,a[i]));
    }
    if(ans==n){
        if((m-(a[n]*n-pre[n]))%n!=0)ans--;
    }
    cout<<ans;
    return 0;
}
