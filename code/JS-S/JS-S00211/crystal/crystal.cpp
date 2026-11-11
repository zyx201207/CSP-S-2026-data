#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],ans,cnt=0,mx=0,b[N],flash,d,mid;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=2;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
        if(b[i]!=b[i-1])
        {
            flash=1;
        }
    }
    if(flash)
    {
        for(ll i=2;i<=n;i++)
    {
        ans=0;
        cnt=0;
        for(ll j=i;j<=n;j++)
        {
            cnt+=b[j]*(j+1-i);
            if(cnt<=m)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        ans++;
        mx=max(ans,mx);
    }
    cout<<mx;
    }
    else
    {
        d=b[2];
        ll l=1;
        ll r=n-1;
        while(l<r)
        {
            mid=(l+r)/2;
            if(mid*(mid-1)*d*1.0/2<=m)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        cout<<mid;
    }
    return 0;
}
