#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m;
bool check(ll x,vector<ll>& a){
    ll f=0;
    bool k;
    for(int i=0;i<x;i++) f+=a[x]-a[i];
    if(f<=m) return 1;
    for(int i=1;i+x-1<n;i++){
        f-=a[i+x-2]-a[i-1];
        f+=(a[i+x-1]-a[i+x-2])*(x-1);
        if(f<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int l=1,ans=1,r=n;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid,a)) l=mid+1,ans=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
