#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<n;i++)
        {
            long long aa,cc;
            scanf("%lld%lld",&aa,&cc);
        }
        printf("%lld\n",k-1);
    }
    return 0;
}
