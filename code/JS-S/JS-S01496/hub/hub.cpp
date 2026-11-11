#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6;
ll n,k;
vector<ll>g[N];
ll vi[N];
ll de[N];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c,T;
    scanf("%lld%lld",&c,&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",max(n/k/2,1));
    }
    return 0;
}
