#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,s[500005];
bool check(int mid)
{
    for(int i=mid;i<=n;i++)
    {
        long long sum=mid*a[i]-(s[i]-s[i-mid]);
        if(sum<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    s[1]=a[1];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<r-1)
    {
        int mid=(l+r)/2;
        if(check(mid)==1) l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}
