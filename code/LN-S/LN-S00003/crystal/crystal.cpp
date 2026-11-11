#include<bits/stdc++.h>
using namespace std;
long long a[500005],sa[500005],n,m;
bool check(long long x)
{
    for(int i = 1;i <= n-x+1;i++)
        if(x*a[i+x-1]-sa[i+x-1]+sa[i-1]<=m)
            return 1;
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++)
        sa[i]=sa[i-1]+a[i];
    long long l=1,r=n;
    while(l+1<r)
    {
        long long mid=l+r>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    cout<<l;
    return 0;
}
