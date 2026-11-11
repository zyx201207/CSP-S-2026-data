#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510005],mx,sum,o,k;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(n<=5100)
    {
        sort(a+1,a+n+1);
        for(long long i=n;i>=1;i--)
        {
            sum=0;
            o=m;
            for(long long j=i-1;j>=1;j--)
            {
                if(o>=a[i]-a[j])
                {
                    sum++;
                    o-=a[i]-a[j];
                    // cout<<o<<" ";
                }
                else
                {
                    break;
                }
            }
            mx=max(sum,mx);
            // cout<<'\n';
        }
        mx++;
        printf("%lld\n",mx);
    }
    else
    {
        bool f=0;
        for(long long i=1;i<=n;i++)
        {
            if(a[i]!=i)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            sum=0;//10 8 1 2 3 4 5 6 7 8  9 10
            for(long long i=1;i<n;i++)
            {
                if(m>=i*(i-1)-sum)
                {
                    k=i;
                }
                else
                {
                    break;
                }
                sum+=i;
            }
            cout<<k;
        }
        else
        {
                sum=0;
                o=m;
                for(long long j=n-1;j>=1;j--)
                {
                    if(o>=a[n]-a[j])
                    {
                        sum++;
                        o-=a[n]-a[j];
                        // cout<<o<<" ";
                    }
                    else
                    {
                        break;
                    }
                }
            sum++;
            printf("%lld\n",sum);
        }
    }
    return 0;
}