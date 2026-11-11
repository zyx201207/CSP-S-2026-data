#include <bits/stdc++.h>
using namespace std;
int a[1000008],s[1000008],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            ans=max(a[i],ans);
        }
        cout<<ans;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=2;j<=n;j++)
            {
                if(j!=i)
                {
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
        cout<<ans;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==n-1)
    {
        for(int i=1;i<=n;i++)
        {
            int b=1;
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    b&=a[j];
                }
            }
            ans=max(ans,b);
        }
        cout<<ans;
    }
    return 0;
}
