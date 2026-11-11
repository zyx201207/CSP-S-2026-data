#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int n,m;
int a[MAXN];
int sum[MAXN];
bool check(int mid)
{
    int cnt=1e18;
    for(int i=mid;i<=n;i++)
    {
        cnt=min(cnt,mid*a[i]-(sum[i]-sum[i-mid]));
    }
    return cnt<=m;
}
bool cmp(int a,int b)
{
    return a<b;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        // cout<<sum[i]<<' ';
    }
    int l=1,r=n;
    int mid;
    int ans=0;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}