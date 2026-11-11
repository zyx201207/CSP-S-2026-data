#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    bool yiyang=true;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(i>=2 && a[i]!=a[i-1])
        {
            yiyang=false;
        }
    }
    if(yiyang)
    {
        printf("%lld",n);
        return 0;
    }
    sort(a+1,a+1+n);
    long long le=1;
    long long maxans=0;
    for(int i=2;i<n;i++)
    {
        long long v=a[i]-a[i-1];
        if(v*(i-le)<=m)
        {
            m=m-v*(i-le);
        }
        else
        {
            while(le<=i && m<v*(i-le))
            {
                m+=a[i-1]-a[le];
                le++;
            }
            if(m<v*(i-le))
            {
                break;
            }
            m=m-v*(i-le);
        }
        maxans=max(maxans,i-le+1);
    }
    printf("%lld",maxans);
    return 0;
}
