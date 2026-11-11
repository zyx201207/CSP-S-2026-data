#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500050;
ll a[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[0]=a[1];
    ll ans=0,res=0,l=1,r=1,flag=0;
    while(l<n)
    {
        if(a[r]!=a[r-1])flag=r-1;
        if(flag<l)flag=l;
        if(res<=m)
        {
            if(r==n)
            {
                break;
            }
            res+=(a[r]-a[r-1])*(flag-l+1);
            if(res<=m)ans=max(ans,r-l+1);
            r++;
        }
        else
        {
            while(res>m)
            {
                res-=a[r-1]-a[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
