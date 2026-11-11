#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500067];ll s[500067];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]-a[i-1];
    }
    for(int i=n;i>0;i--){
        s[i]=s[i+1]+s[i];
    }
    ll val=0;int r=n;int ans=0;
    for(int l=n;l>0;l--){
        val+=s[l+1]-s[r+1];
        while(val>m){
            val-=(a[r]-a[r-1])*(r-l);
            r--;
        }
        if(val<=m){
            ans=max(ans,r-l+1);
        }
    }
    cout<<ans;
}
