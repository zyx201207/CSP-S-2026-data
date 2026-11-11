

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10000;
long long c,n,m,d,q,t[N],k,o,p,f[N],id,mn=5e9+10,to[N],head[N],ne[N],tail[N],l,r;
vector<long long> a[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=m;i++)
    {
        scanf("%lld",&t[i]);
    }
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        for(long long j=1;j<=k;j++)
        {
            scanf("%lld%lld",&p,&o);
            a[i].push_back(p);
            // add(i,p);
        }
    }
    for(long long i=1;i<=m;i++)
    {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",t[i]+o);
    }
    return 0;
}

