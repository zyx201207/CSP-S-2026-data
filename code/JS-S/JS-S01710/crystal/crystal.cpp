#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,m,c[500005],b[500005];
long long bf()
{
    long long mid,l=1,r=n,i;
    while(l<=r)
    {
        mid=(l+r)/2;
        bool flag=0;
        for(i=1;i<=n-mid+1;i++)
        {
            if(c[i+mid-1]-c[i]-(i-1)*(a[i+mid-1]-a[i])<=m)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            l=mid+1;
        else
            r=mid-1;
    }
    return r;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        c[i]=(i-1)*(a[i]-a[i-1]);
        c[i]+=c[i-1];
    }/*
    cout<<c[i]<<' ';
    for(int i=2;i<=n;i++)
    {
        c[i]+=c[i-1];
        cout<<c[i]<<' ';
    }
    */
    cout<<bf();
    return 0;
}
