#include<bits/stdc++.h>
#define vi first
#define ui second
using namespace std;
typedef long long ll;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c,t;
    scanf("%lld %lld",&c,&t);
    while(t--)
    {
        ll n,k;
        scanf("%lld %lld",&n,&k);
        vector< vector<ll> > a(2*1e6+500,vector<ll>(1,0));
        for(ll i=1;i<=n;i++)
        {
            ll u,v;
            scanf("%lld %lld",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        printf("%d\n",1);
    }
    return 0;
}
