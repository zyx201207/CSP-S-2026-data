#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN=5e5+5;
ll n,m;
ll a[MN];
ll s[MN];

ll cost(ll idx,ll l,ll r){
    ll cnt=0;
    cnt-=(ll)(r-idx)*a[idx];
    cnt+=(ll)(idx-l+1)*a[idx];
    cnt-=s[idx]-s[l-1];
    cnt+=s[r]-s[idx];
    return cnt;
}

bool check(ll l,ll r){
    ll len=r-l+1;
    ll sum=s[r]-s[l-1];
    ll ave=sum/(len);
    ll idx=upper_bound(a+l,a+r+1,ave)-a;
    if(cost(idx,l,r)<=m){
        return 1;
    }
    if(idx-1>=l&&cost(idx-1,l,r)<=m){
        return 1;
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    ll l=1,ans=1;
    for(int i=2;i<=n;i++){
        while(l<i&&!check(l,i)){
            l++;
        }
        if((i-l+1)>ans) ans=i;
    }
    printf("%lld",ans);
    return 0;
}
