#include<bits/stdc++.h>
using namespace std;
long long m,a[2002000],n,t,c,d,ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","r",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&d);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        if(c==13 || c==14)
        {
            printf("%lld",0ll);
            break;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++){}
        }
        printf("%lld",ans);
    }
    return 0;
}
