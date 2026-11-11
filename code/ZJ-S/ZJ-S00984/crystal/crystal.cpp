//Oct31==Dec25?
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;

int n;
ll m,a[N];

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int ans=0;
    int l=1;
    ll s=0;
    for(int i=1;i<=n;i++) {
        s+=a[i];
        while((i-l+1)*a[i]-s>m) s-=a[l++];
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
    return 0;
}
//14:35