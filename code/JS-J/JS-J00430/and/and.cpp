#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005];
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
        long long maxn=0;
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    else if(m==n)
    {
        long long cnt=a[1];
        for(int i=2;i<=n;i++)
        {
            cnt&=a[i];
        }
        cout<<cnt;
        return 0;
    }
    else if(m==2)
    {
        long long maxn=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    else
    {
        cout<<a[n];
    }

    return 0;
}
