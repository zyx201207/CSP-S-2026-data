#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll a[MAXN];
int n,m;
int cnt;
ll check(ll x){
    int c=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=x){
            ans+=1LL*(x-a[i]);
            c++;
        }
    }
    if(ans<=m) cnt=max(cnt,c);
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    ll mx=0,mn=INF;
    bool ok=true;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
        if(a[i]!=a[i-1]) ok=false;
    }
    if(ok){
        printf("%d\n",n);
        return 0;
    }
    ll l=mn,r=mx;
    while(l<=r){
        ll mid=(r-l)/2+l;
        if(check(mid)<=m) l=mid+1;
        else r=mid-1;
    }
    printf("%d",cnt);
    return 0;
}
