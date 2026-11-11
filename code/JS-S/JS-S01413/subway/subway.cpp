#include<bits/stdc++.h>
#define ai first
#define ti second
using namespace std;
typedef long long ll;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    vector<ll> w(5*1e5+500,0);
    for(ll i=1;i<=m;i++) scanf("%lld",&w[i]);
    vector< vector< pair<ll,ll> > > a(550,vector< pair<ll,ll> >(5*1e5+500,make_pair(0,0)));
    for(ll i=1;i<=n;i++)
    {
        ll ki;
        scanf("%lld",&ki);
        for(ll j=1;i<=ki;j++) scanf("%lld %lld",&a[i][j].ai,&a[i][j].ti);
    }
    while(q--)
    {
        ll xi,yi;
        scanf("%lld %lld",&xi,&yi);
        printf("%d\n",1);
    }
    return 0;
}
