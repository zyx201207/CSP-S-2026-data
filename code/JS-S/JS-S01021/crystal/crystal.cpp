#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<ll> sum;
vector<ll> a;

bool check(int len){
    for(int i=len;i<=n;++i){
        ll s=sum[i]-sum[i-len];
        s=len*a[i]-s;
        if(s<=m) return 1;
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    a.resize(n);

    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    a.push_back(0);
    for(int i=n;i>0;--i) a[i]=a[i-1];
    sum.resize(n+3);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }

    ll l,r;
    l=0,r=5e5+10;
    ll ans=1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }else r=mid-1;
    }

    cout<<ans<<endl;
    return 0;
}