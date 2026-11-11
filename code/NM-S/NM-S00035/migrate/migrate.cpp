#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2000006;
ll a[maxn]={0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ll c=0;
    ll t=0;
    cin>>c>>t;
    while(t--)
    {
        ll n=0;
        ll d=0;
        cin>>n>>d;

        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        ll ans=0;

        for(ll i=1;i<=n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                if(i+1==j) continue;
                ll t=0;
                for(ll k=j-i;k>0;k--)
                {
                    //cout<<"k= "<<k<<endl;
                    bool p=false;
                    if(abs(a[i+k]-a[i])<=d&&i+k<j)
                    {
                        t++;
                        p=true;
                        //cout<<"i="<<i<<" j="<<j<<" "<<abs(a[i+k]-a[i])<<endl;
                        //cout<<i+k<<endl;
                    }
                    if(abs(a[j-k]-a[j])<=d&&j-k>i&&i+k!=j-k)
                    {
                        t++;
                        p=true;
                        //cout<<"i="<<i<<" j="<<j<<" "<<abs(a[j-k]-a[j])<<endl;
                        //cout<<j-k<<endl;
                    }
                    if(p) break;
                }
                if(t==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
