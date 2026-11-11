#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=5e5+5;
int n;
ll a[N],s[N],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i<n&&a[i]==a[i+1]) continue;
        int l=1,r=i,ret=i;
        // [ans,i]
        while(l<=r){
            int mid=(l+r)/2;
            // is [mid,i] ok?
            ll need=a[i]*ll(i-mid+1)-(s[i]-s[mid-1]);
            if(need<=m){
                // ok
                r=mid-1;
                ret=mid;
            }else l=mid+1;
        }
        ans=max(ans,i-ret+1);
    }
    printf("%d\n",ans);
    return 0;
}
