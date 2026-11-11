#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;
ll n,m;
ll a[N];
ll dp[N],pre[N],c[N];
ll sum;

ll binary(){
    ll l=0;
    ll r=n-1;
    ll mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(pre[mid]<=m) l=mid+1;
        else r=mid;
    }
    return l;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    c[0]=0;
    for(ll i=1;i<n;i++){
        c[i]=a[i]-a[i-1];
    }

    pre[0]=c[0];
    for(ll i=1;i<n;i++)
        pre[i]=c[i]+pre[i-1];

    sum=binary();
    cout<<sum;
    return 0;
}
