#include<bits/stdc++.h>
using namespace std;
int n,last=0,ans=0;
long long m,a[500005],sum[500005];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=n;i++) {
        while (a[i]*(i-last)-(sum[i]-sum[last])>m) last++;
        ans=max(ans,i-last);
    }
    printf("%d",ans);
    return 0;
}
