#include<bits/stdc++.h>
#define elif else if
#define endl '\n'
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll s[500005];
ll ans=1;

bool ch(ll x){
    for(int i=x;i<=n;i++){
        if(x*a[i]-(s[i]-s[i-x])<=m){
            return 1;
        }
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    ll l=1,r=n;
    while(l<=r){
        ll mid=(l+r)/2;
        if(ch(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
/*
5 6
1 4 6 8 11
1 5 11 19 30

3
6: 18-11=7
8: 24-(19-1)=6



*/
