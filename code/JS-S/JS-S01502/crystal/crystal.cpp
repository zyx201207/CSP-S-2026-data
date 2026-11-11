#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,pos=0;
        while(l<=r){
            int mid=(l+r)>>1;
            long long tmp=1ll*(i-mid+1)*a[i]-sum[i]+sum[mid-1];
            if(tmp>m)
                l=mid+1;
            else
                r=mid-1,pos=i-mid+1;
        }
        ans=max(ans,pos);
    }
    printf("%d",ans);
    return 0;
}
//57min AC
