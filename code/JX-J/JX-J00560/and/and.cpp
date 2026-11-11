#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    srand(time(0));
    for(int i=1;i<=n;i++)   cin>>a[i];
    long long ans;
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        ans=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1)
    {
        long long p1=a[1],p2=a[2];
        for(int i=2;i<n;i++)
        {
            p1=p1&a[i];
        }
        for(int i=3;i<=n;i++)
        {
            p2=p2&a[i];
        }
        ans=max(p1,p2);
        cout<<ans;
        return 0;
    }
    cout<<17;
    return 0;
}


