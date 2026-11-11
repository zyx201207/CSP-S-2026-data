#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500007],b[500007],s[500007];
bool check(int x)
{
    int minn=1e18+7;
    for(int i=1;i<=n-x+1;i++)
    {
        minn=min(minn,a[i+x-1]*(x-1)-(s[i+x-2]-s[i-1]));
    }
    if(minn<=m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    int l=0,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
            ans=max(ans,mid);
        }
        else
        {

            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
