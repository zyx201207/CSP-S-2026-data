#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=2e6+10;
int c,t;
int n,d;
int x[maxn];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&c,&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&d);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&x[i]);
        }
        int delta=x[2]-x[1];
        int dis=d/delta;
        if(d<=delta)
        {
            printf("0\n");
            continue;
        }
        int pos=2*dis;
        if(pos>n)
            printf("0\n");
        else
            printf("%lld\n",n-pos+1);
    }
    return 0;
}