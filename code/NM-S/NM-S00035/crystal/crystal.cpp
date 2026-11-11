#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=500020;
ll a[maxn][maxn]={0};
ll b[maxn]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ll n=0;
    ll m=0;
    cin>>n>>m;

    for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    sort(b+1,b+n+1);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            a[i][j]=b[j]-b[i];
        }
    }

    /*for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/

    ll ans=0;
    for(ll i=n;i>=1;i--)
    {
        ll t=0;
        ll cishu=m;
        for(ll j=i;j>=1;j--)
        {
            if(cishu>=a[j][i])
            {
                t++;
                cishu-=a[j][i];
            }
            else
            {
                break;
            }
            //cout<<"i= "<<i<<" j= "<<j<<endl;
            //cout<<t<<" cishu= "<<cishu<<" a[j][i]= "<<a[j][i]<<endl;
        }
        ans=max(t,ans);
    }
    cout<<ans<<endl;
    return 0;
}
