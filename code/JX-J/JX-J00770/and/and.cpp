#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    if(n==m)
    {
        long long ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
            return 0;
        }
    }
    if(m==2)
    {
        long long maxn=-1234567;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                long long t=a[i]&a[j];
                maxn=max(t,maxn);
            }

        }
        cout<<maxn;
        return 0;
    }
   /* long long maxn=-123456;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            long long t=a[i]&a[j];
            maxn=max(t,maxn);
        }
    }
    */
    return 0;
}
