#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
const int N=5e5+10;
int n,ans=0;ll m,s[N],a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    for(int i=1,res=1;i<=n;++i,res=1)
        for(int l=1,r=i,mid=(l+r)>>1;l<=r;mid=(l+r)>>1)
            a[i]*mid-(s[i]-s[i-mid])<=m?ans=max(ans,mid),l=mid+1:r=mid-1;
    printf("%d",ans);
    return 0;
}