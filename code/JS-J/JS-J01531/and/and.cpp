#include <bits/stdc++.h>
using namespace std;
long long a[2*10*10*10*10*10+10];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long maxn=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (m==2)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                long long x=a[i]&a[j];
                maxn=max(maxn,x);
            }
        }
    }
    if (m==n)
    {
        maxn=a[1];
        for (int i=2;i<=n;i++)
        {
            maxn&=a[i];
        }
    }
    if (m==1)
    {
        for (int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i]);
        }
    }
    cout<<maxn;
    return 0;
}
