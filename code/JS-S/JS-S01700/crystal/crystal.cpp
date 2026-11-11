#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
ll ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=1,r=0,k=0;
    ans=1;
    for(r=2;r<=n;r++){
        k=k+(a[r]-a[r-1])*(r-l);
        while(k>m){
            l++;
            k=k-(a[r]-a[l]);
        }
        ans=max(r-l+1,ans);
    }
    cout<<ans<<'\n';
    return 0;
}

