#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500001],p;
bool t;
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
    if(n<=5000)
    {
        for(int i=1;i<=n-ans+1;i++)
        {
            p=0;
            t=1;
            for(int j=i+1;j<=n;j++)
            {
                p+=(a[j]-a[j-1])*(j-i);
                if(p>m)
                {
                    ans=max(ans,j-i);
                    t=0;
                    break;
                }
            }
            if(t)
            {
                ans=max(ans,n-i+1);
            }
        }
        cout<<ans;
    }
    else
    {
        t=1;
        for(int i=2;i<=n;i++)
        {
            p+=(a[i]-a[i-1])*(i-1);
            if(p>m)
            {
                cout<<i-1;
                t=0;
                break;
            }
        }
        if(t)
        {
            cout<<n;
        }
    }
    return 0;
}
