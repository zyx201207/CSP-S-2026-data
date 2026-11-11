#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long maxn=-102,n,m,a[200086],maxn1;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    if(m==1)
    {
        cout<<maxn<<endl;
        return 0;
    }
    maxn=-10010;
    for(long long i=1;i<n;i++)
        for(long long j=i+1;j<=n;j++)
            maxn=max(maxn,a[i]&a[j]);
    if(m==2)
    {
        cout<<maxn<<endl;
        return 0;
    }
    if(m==n)
    {
        maxn1=a[1];
        for(long long i=2;i<=n;i++)
            maxn1=maxn1&a[1];
        cout<<maxn1<<endl;
        return 0;
    }
    if(m==n-1)
    {
        maxn1=-1001;
        for(long long i=1;i<=n;i++)
        {
            long long p=1073741823;
            for(long long j=1;j<=n;j++)
            {
                if(j==i)
                    continue;
                p=p&a[j];
            }
            maxn1=max(maxn1,p);
        }
        cout<<maxn1<<endl;
        return 0;
    }
    cout<<maxn<<endl;
    return 0;
}

