#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0,mx=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }
    else if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==n-1)
    {
        ans=a[1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;i++)
            {
                if(j==i) continue;
                ans=ans&a[j];
            }
        }
        cout<<ans;
    }
    return 0;
}
