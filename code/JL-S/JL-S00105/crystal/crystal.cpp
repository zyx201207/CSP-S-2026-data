#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
vector<ll> v;
vector<ll> d;
bool f=true,ff=true;
ll diff;
bool check(ll x){
    if(f){
        return m>=((x)*(x-1)/2);
    }
    if(ff){
        return m>=((x)*(x-1)/2)*diff;
    }
    if(x==1) return true;
    ll minn=1e8;
    ll cnt=x-1,cur=0;
    for(ll i=x-1;i<n;i++){//[i-x+1,i]
        for(ll j=i;j>i-x+1;j--){
            cur=cur+cnt*d[j];
            cnt--;
        }
        minn=min(minn,cur);
        cnt=x-1,cur=0;
    }
    return m>=minn;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    v.resize(n);
    d.resize(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(v[i]!=(i+1)) f=0;
    }
    if(!f){
        diff=v[1]-v[0];
        for(int i=2;i<n;i++){
            if((v[i]-v[i-1])!=diff) ff=0;
        }
    }
    d[0]=0;
    for(ll i=1;i<n;i++) d[i]=v[i]-v[i-1];//i-1->i d[i]
    ll l=1,r=n;
    ll ans;
    while(l<=r){
        ll mid=(r-l)/2+l;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
