#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005];
long long cnt[500005];
long long sum[500005];
long long ans=0;

bool cmp(int x,int y)
{
    return x>y;
}

long long solve(int x)
{
    int l=x,r=n+1,now=cnt[x];
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(sum[mid]-(mid-x+1)*now-sum[x-1]<=m)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    return (l-x+1);
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        cnt[i]=a[1]-a[i];
        sum[i]=sum[i-1]+cnt[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,solve(i));
    }
    cout<<ans;
    return 0;
}
