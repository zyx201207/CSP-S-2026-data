#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],sm,mx=LONG_LONG_MIN;
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
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        long long l=1,r=i,k=0;
        while(l<r)
        {
            k=(l+r>>1);
            if(a[i]*k-m<=s[i]-s[i-k])
            {
                l=k+1;
            }
            else
            {
                r=k;
            }
        }
        mx=max(mx,l);
    }
    cout<<mx;
    return 0;
}
