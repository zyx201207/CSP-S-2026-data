#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
const int N=5e5;
lll a[N+5],sum[N+5],m,n,ans;
lll work(int x){
    int l=x,r=n,mid,res;
    for(;l<=r;){
        mid=l+r>>1;
        if(a[x]*(mid-x+1)-(sum[mid]-sum[x-1])<=m){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return res-x+1;
}
int main(){
    freopen("crystal.in","r",stdin);
 //   freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1,greater<lll>());

    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;++i){
        ans=max(ans,work(i));
    }
    printf("%lld",ans);
    return 0;
}
