#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5;
int n,ans;
ll m,a[N],pre[N];
ll cost(int l,int r) {
    return a[r]*(r-l)-(pre[r-1]-pre[l-1]);
}
int solve(int k) {
    int l=1,r=k,mid=0,ans=-1;
    while(l<=r) {
        mid=(l+r)>>1;
        if(cost(mid,k)<=m) {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    return k-ans+1;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    pre[0]=0;
    for(int i=1;i<=n;++i) {
        pre[i]=pre[i-1]+a[i];
    }
    ans=0;
    for(int i=1;i<=n;++i) {
        ans=max(ans,solve(i));
    }
    printf("%lld",ans);
    return 0;
}
