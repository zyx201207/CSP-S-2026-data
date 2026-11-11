#include <bits/stdc++.h>
using namespace std;
long long n,k,ans=1,a[500010],pre[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&k),pre[0]=0;
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(long long i=1;i<=n;i++)
        {
            long long L=1,R=i-1,AS=-1;
            while(L<=R)
                {
                    long long mid=(L+R)>>1,res,num;
                    res=pre[i-1]-pre[mid-1];
                    num=a[i]*(i-1-mid+1);
                    if(res+k>=num)AS=mid,R=mid-1;
                        else L=mid+1;
                }
            if(AS!=-1)ans=max(ans,i-AS+1);
        }
    printf("%lld\n",ans);
    return 0;
}
