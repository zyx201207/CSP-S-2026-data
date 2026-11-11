#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans;
int check(int pos){
    int l=1,r=pos,res=pos;
    while(l<=r){
        int mid=(l+r)>>1;
        if((pos-mid+1)*a[pos]-(sum[pos]-sum[mid-1])<=m){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return pos-res+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        ans=max(ans,check(i));
    }
    printf("%lld",ans);
    return 0;
}
