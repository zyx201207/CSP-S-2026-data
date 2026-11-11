#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,ans;
ll a[N],p,cnt[N],all[N];
bool check(ll mid){
    for(ll i=mid;i<=n;i++){
        if(a[i]*mid<=all[i]-all[i-mid-1]+m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        all[i]=all[i-1]+a[i];
    }
    ll l=0,r=n;
    while(l<r){
        ll mid=l+(r-1)/2;
        if(mid>n)break;
        if(check(mid)){
            l=mid;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
