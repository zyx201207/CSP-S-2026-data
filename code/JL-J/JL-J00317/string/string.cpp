#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char b[200010];
long long c[200010];
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld%s",&a[i],&b[i]);
        c[i]=c[i-1]+a[i];
    }
    long long j=n;
    long long qwe=c[n];
    long long asd;
    long long q=1,i=1;
    for(;i<=c[n]/2;)
    {
        if(i>c[q])
            q++;
        if(b[q]!=b[j])
        {
            asd=a[q];
            while(i<=c[n]/2)
            {
                if((qwe-c[j-1])==asd)
                {
                    j--;
                    ans+=qwe-c[j];
                    i+=asd;
                    qwe=c[j];
                    //cout<<0<<' '<<j<<' '<<qwe<<' '<<ans<<' '<<i<<' '<<asd<<endl;
                    break;
                }
                 else if((qwe-c[j-1])>asd)
                {
                    ans+=asd;
                    qwe-=asd;
                    i+=asd;
                    //cout<<1<<' '<<j<<' '<<qwe<<' '<<ans<<' '<<i<<endl;
                    break;
                }
                else
                {
                    j--;
                    ans+=qwe-c[j];
                    asd-=(qwe-c[j]);
                    i+=qwe-c[j];
                    qwe=c[j];
                    //cout<<2<<' '<<j<<' '<<qwe<<' '<<ans<<' '<<i<<endl;
                }
            }
        }
        else
            i=c[q+1];
    }
    ans-=i-c[n]/2;
    printf("%lld",ans);
    return 0;
}
