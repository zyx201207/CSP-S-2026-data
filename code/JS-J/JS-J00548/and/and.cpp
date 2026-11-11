#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],mx=-1;
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
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==2&&n!=m)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]&a[j]>=mx)
                    mx=a[i]&a[j];
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==n)
    {
        long long ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1)
    {
        long long mx=-1,bx=1;
        for(int i=1;i<=n;i++)
        {
            if(i!=1)
                bx=a[1];
            else
                bx=a[2];
            for(int j=1;j<=n;j++)
            {
                if(j==i)
                    bx=bx;
                else
                    bx=bx&a[i];
            }
            if(bx>mx)
            {
                mx=bx;
            }
        }
        cout<<mx;
        return 0;
    }
    else
    {
        sort(a+1,a+n+1);
        int zx=a[n];
        for(int i=n;i>=n-m+1;i--)
        {
            zx=zx&a[i];
        }
        cout<<zx;
        return 0;
    }
}
