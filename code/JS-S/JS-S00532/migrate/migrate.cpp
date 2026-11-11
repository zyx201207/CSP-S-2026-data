#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t,cnt=0;
bool h=false;
ll ans=0;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d%d",&c,&t);
    while(t--)
    {
        ll n,d;
        ll x[N];
        scanf("%lld%lld",&n,&d);
        for(ll i=1;i<=n;i++) scanf("%lld",&x[i]);
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=d;j++)
            {
                if(x[i]+d<x[i+1])
                {
                    ans=0;
                    h=true;
                    break;
                }
                for(ll u=1;u<=n;u++)
                {
                    for(ll v=u+1;v<=n;v++)
                    {
                        for(ll ss=1;ss<=d;ss++)
                        {
                            if((u+ss)==v) ans++;
                        }
                    }
                }
            }
            if(h) break;
        }
        if(cnt==2) cout<<ans<<endl;
        else cout<<'0'<<endl;
    }
    return 0;
}
