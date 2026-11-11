#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005],b[500005];
ll n,m,ans=0;
bool check(ll x){
    ll cnt=0;
    for(ll i=1;i<=n-x+1;i++){
        if(b[i+x-2]-b[i-1]+m>=(x-1)*a[i+x-1]) cnt++;

    }

    if(cnt>0) return 1;
    else return 0;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    ll l=1,r=1e18+4,mid=0,ans=0;

    while(l<r){
        mid=(l+r)/2+1;
        if(check(mid)){
            l=mid;
        }else{
           r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
