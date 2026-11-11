#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;

ll cnt=0,minx=LLONG_MAX,_sum=0;
vector<ll> a(1,0);

void DFS(ll x,ll y,ll d,ll sum)
{
    if(x>y) return;
    if(x==y)
    {
        if(sum==minx)
        {
            _sum++;
            return;
        }
        else if(sum<minx)
        {
            minx=sum,_sum=1;
            return;
        }
        return;
    }
    for(ll i=x+1;a[i]-a[x]<=d&&i<=y;i++) DFS(i,y,d,sum+1);
    return;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    scanf("%lld %lld",&c,&t);
    while(t--)
    {
        ll n,d;
        scanf("%lld %lld",&n,&d);
        a.clear();
        for(ll i=1;i<=n;i++)
        {
            ll v;
            scanf("%lld",&v);
            a.push_back(v);
        }
        for(ll i=1;i<=n;i++)
            for(ll j=i+2;j<=n;j++)
            {
                _sum=0,minx=LLONG_MAX;
                DFS(i,j,d,0);
                if(_sum==2) cnt++;
            }
        printf("%lld\n",cnt);
    }
    return 0;
}
