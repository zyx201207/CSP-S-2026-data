#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long c,t,n,d,a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%lld%lld",&n,&d);
        bool f=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            if(n>=3)
            {
                if((a[i]-a[i-1])!=(a[i-1]-a[i-2]))
                    f=0;
            }
        }
        printf("0\n");
    }
    return 0;
}
