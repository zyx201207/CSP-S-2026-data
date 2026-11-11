#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using ll=long long;
ll n,m,a[N],s[N],ans=1;
ll find(ll l,ll r,ll i){
    while(l<=r){
        ll mid=(l+r)>>1;
        if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) r=mid-1;
        else l=mid+1;
    }
    return r+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(ll i=1,L,R;i<=n;i++){
        L=R=i;
        if(i>1) L=find(1,i-1,i);
        ans=max(ans,R-L+1);
    }
    cout<<ans;
    return 0;
}