#include <bits/stdc++.h>
using namespace std;
const int N=20000010;
int c,t,n;
long long d,x[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        long long k=d/(x[2]-x[1])*2-1;
        if(d<=x[2]-x[1])
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n",max(n-k,0LL));
        }
    }
    return 0;
}
