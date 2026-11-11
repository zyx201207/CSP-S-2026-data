#include <bits/stdc++.h>
using namespace std;
int n,f1=1,f2=1;
long long m,a[500005],t,x[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            f1=0;
        }
        if(i>=3&&a[i]-a[i-1]!=t)
        {
            f2=0;
        }
        t=a[i]-a[i-1];
    }
    sort(a+1,a+n+1);
    if(f1)
    {
        long long ans;
        for(ans=1;ans<=n;ans++)
        {
            if(m<ans*(ans+1)/2)
            {
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    if(f2)
    {
        long long ans;
        for(ans=1;ans<=n;ans++)
        {
            if(m<ans*(ans+1)/2*t)
            {
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        x[i]=a[i]-a[i-1];
    }
    for(int l=1;l<=n;l++)
    {
        long long s=0;
        for(int r=l+1;r<=n;r++)
        {
            s+=(r-l)*x[r];
            if(m>=s)
            {
                ans=max(ans,r-l+1);
            }
            else
            {
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
