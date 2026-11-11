#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long c,T;
long long n,k;
vector <long long> pq[N];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while (T--)
    {
        scanf("%lld%lld",&n,&k);
        for (long long i=1;i<n;++i)
        {
            long long u,v;
            scanf("%lld%lld",&u,&v);
            pq[u].push_back(v);
            pq[v].push_back(u);
        }
        printf("%lld\n",n/k-1);
    }
    return 0;
}
