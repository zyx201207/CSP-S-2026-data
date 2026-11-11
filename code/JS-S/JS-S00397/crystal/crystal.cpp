#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=5e5+5;
int n;
LL m,a[N],pfx[N];
bool check(int x,int t)
{
    if(t-x-1<0) return 1;
    if((x+1)*a[t]-pfx[t]+pfx[t-x-1]>m) return 1;
    return 0;
}
LL fds(int s)
{
    int l=1,r=s;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid,s)) r=mid;
        else l=mid+1;
    }
    return l;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        pfx[i]=pfx[i-1]+a[i];
    LL ans=1;
    for(int st=n;st>=1;st--)
    {
        LL k=fds(st);
        ans=max(ans,k);
    }
    cout<<ans;
    return 0;
}
