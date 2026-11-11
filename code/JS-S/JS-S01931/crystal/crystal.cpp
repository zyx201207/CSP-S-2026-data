#include<bits/stdc++.h>
#define ll long long 
const int N=5e5+10;
using namespace std;
ll n,m,a[N],c[N],aa;
inline void add(ll x,ll k){
    while(x<=n){
        c[x]+=k;
        x+=(x&-x);
    }
}
inline ll query(ll axd,ll x){
    ll sum=0;
    while(x>0){
        sum+=c[x];
        x-=(x&-x);
    }
    return sum;
}
inline ll check(ll i,ll j){
    ll ans=(i-j)*a[i]-query(1,i-1)+query(1,j-1);
    aa=ans;
    if(ans<=m) return 0;
    else return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        add(i,a[i]);
    }
    ll x=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=i-1;
        while(l<=r){
            ll mid=l+r>>1;
            // cnt++;
            // if(cnt==5e5){
            //     cout<<check(i,mid)<<" "<<l<<" "<<r<<" "<<i<<" "<<aa;
            //     return 0;
            // }
            if(check(i,mid)){
                l=mid+1;
            }
            else r=mid-1;
        }
        x=max(x,i-l+1);
    }
    cout<<x;
    return 0;
}//5 8 1 2 4 8 9