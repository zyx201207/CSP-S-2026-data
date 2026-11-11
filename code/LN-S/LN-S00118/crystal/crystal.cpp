#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
int q[500005]={0},ans=1,b,xb=0,l,r,mid;
bool cmp(int aa,int bb)
{
    return aa>bb;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)q[i]=a[1]-a[i]+q[i-1];
    q[0]=-1e16;
    a[0]=a[1];
    for(int i=1;i<=n;i++)
    {
        b=a[1]-a[i-1];
        if(i!=1)xb=q[i]-a[i+1]+a[i];
        l=i;
        r=n;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(q[mid]-b*(mid-i)-xb<=m)l=mid+1;
            else r=mid;
        }
        ans=max(r-i+1,ans);
    }
    cout<<ans;
    return 0;
}