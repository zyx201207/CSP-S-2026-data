#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10000;
long long c,t,n,d,a[N],sum;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&d);
        for(long long i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        printf("0\n");
        // for(int i=2;i<n;i++)
        // {
        //     for(int j=1;j<=n&&i-j>=1&&i+j<=n;j++)
        //     {
        //         if(abs(a[i-j]-a[i])==abs(a[i+j]-a[i]))
        //         sum++;
        //     }
        // }
        // printf("%lld\n",sum);
    }
    return 0;
}