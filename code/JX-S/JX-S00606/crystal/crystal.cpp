#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+8;
int n;
ll m,a[N],sum[N];
bool check(ll mid){
    ll ans=0;
    for(int i=mid;i<=n;i++){
        if(i==mid) ans=mid*a[i]-sum[i];
        else ans=min(ans,mid*a[i]-(sum[i]-sum[i-mid]));
    }
    if(ans>m) return false;
    else return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll l=0,r=n;
    while(l<r){
        ll mid=(l+r)>>1;
        if(!check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l-1;
    return 0;
}
