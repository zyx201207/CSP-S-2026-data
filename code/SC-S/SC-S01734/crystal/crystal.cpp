#include<bits/stdc++.h>
#define int lld
typedef long long lld;
using namespace std;
int n,m,a[500005],A[500005],ans;
__int128 f(int l,int r){
    return (__int128)(a[r]*(r-l+1))-(A[r]-A[l-1]);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        A[i]=A[i-1]+a[i];
    for(int l=1,r=1;r<=n;r++)
        while(f(l,r)>m)
            l++,ans=max(ans,r-l+1);
    printf("%lld",ans);
}