#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010];
long long l,r,mid,ans;
bool check(long long x){
    long long ll=1,rr=x;
    while(rr<=n){
        if(a[rr]*x-(sum[rr]-sum[ll-1])<=m)
            return true;
        ll++;rr++;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    l=0,r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)==true){
            ans=max(ans,mid);
            l=mid+1;
        }else r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}
