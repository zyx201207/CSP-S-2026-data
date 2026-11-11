#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005];
int n,m;
int gs(int s,int e)
{
    //[s,e]
    return a[e]*(e-s+1)-(b[e]-b[s-1]);
}
int check(int mid)
{
    int minn=LLONG_MAX;
    for(int i=mid;i<=n;i++)
    {
        minn=min(minn,gs(i-mid+1,i));
    }
    return (minn<=m);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i];
    }
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))
        {
            l=mid;
        }
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
