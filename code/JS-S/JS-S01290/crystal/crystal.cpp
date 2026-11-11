#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500005
ll n,m;
ll a[N];
bool check(int x)
{
    ll cnt=0;
    for(int i=2;i<=x;i++)
    {
        cnt+=(a[i]-a[i-1])*(i-1);
    }
    for(int i=x;i<=n;i++)
    {
        if(cnt<=m)
        {
            return true;
        }
        cnt-=a[i]-a[i-x+1];
        cnt+=(a[i+1]-a[i])*x;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l;
}

