#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500009],d[500009],s[500009],ans;
bool check(int mid)
{
    for(int l=1;l<=n-mid+1;l++)
    {
        //[l,l+mid-1]
        int r=l+mid-1;
        int k=s[r]-s[l-1]-mid*d[r];
        if(k<=m)return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int mid=n/2;
    for(int i=1;i<=n;i++)
    {
        d[i]=a[mid]-a[i];
    }
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+d[i];
    }
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l;
}
