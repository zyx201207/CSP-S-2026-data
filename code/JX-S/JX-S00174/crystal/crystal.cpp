#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,ans=1,cha,ch=1;
ll a[N],sum[N];
bool pd(ll l,ll r,ll len)
{
    if ((sum[r]-sum[l-1]+m)/len>=a[r]) return 1;
    else return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cha=a[2]-a[1];
    for (int i=2;i<n;i++)
    {
        if (cha!=a[i+1]-a[i])
        {
            ch=0;
            break;
        }
    }
    if (ch)
    {
        if (cha==0) ans=n;
        else
        {
            ll c=m/cha;
            ans=sqrt(c*2);
        }
        cout<<ans<<"\n;
        return 0;
    }
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (ll len=2;len<=n;len++)
    {
        for (ll l=1;l+len-1<=n;l++)
        {
            ll r=l+len-1;
            if (pd(l,r,len))
            {
                ans=len;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
