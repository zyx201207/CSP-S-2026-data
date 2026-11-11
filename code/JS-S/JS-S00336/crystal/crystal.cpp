#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5e5;
ll n=0,m=0;
ll a[N+5];

bool check(ll x){
    ll s=1e18+5,sum=0;
    for(ll i=1;i<=n;i++){
        sum+=a[i];
        if(i>=x){
            s=min(s,a[i]*x-sum);
            sum-=a[i-x+1];
        }
    }
    return (s<=m);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll l=1,r=n,ans=1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
