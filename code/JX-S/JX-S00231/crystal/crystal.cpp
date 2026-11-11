#include<bits/stdc++.h>
using namespace std;
long long arr[500005],dif[500005],sum[500005];
long long n,m,ans;
//The last update time: 15:42:15
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;++i) scanf("%lld",&arr[i]);
    sort(arr+1,arr+n+1);
    for(long long i=1;i<=n;++i) dif[i]=arr[i]-arr[i-1];
    for(long long i=1;i<=n;++i)
    {
        if(i==1) sum[i]=0;
        else if(i==2) sum[i]=dif[i];
        else
        sum[i]+=(dif[i]*(i-1)+sum[i-1]);
    }
    //for(long long i=1;i<=n;++i) printf("%lld ",sum[i]);
    //printf("\n");
    for(long long i=1;i<=n;++i)
    {
        int w=lower_bound(sum+1,sum+i+1,sum[i]-m)-sum;
        if(sum[i]-sum[w]<=m) ans=max(ans,i-w+1);
    }
    printf("%lld\n",ans);
    return 0;
}
