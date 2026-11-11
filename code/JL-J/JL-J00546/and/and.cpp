#include <bits/stdc++.h>
using namespace std;
long long n,m,f[200001],ans=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
    }
    sort(f+1,f+1+n);
    long long k=4294967295;
    if(m==1)
        cout<<f[n];
    else
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            k=k&f[i];
        }
        cout<<k;
    }
    else
    if(m==n-1)
    {
        for(int i=1;i<=n;i++)
        {
            k=4294967295;
            for(int l=1;l<=n;l++)
            {
                if(i!=l)
                    k=k&f[l];
            }
            ans=max(ans,k);
        }
        cout<<ans;
    }
    else
    if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int l=i+1;l<=n;l++)
            {
                ans=max(ans,f[i]&f[l]);
            }
        }
        cout<<ans;
    }
    else
    {
        cout<<f[n-m+1];
    }
    return 0;
}
