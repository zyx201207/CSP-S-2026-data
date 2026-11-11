#include<bits/stdc++.h>
using namespace std;
long long m;
long long a[500010],q[500010];
bool check(int x,int y)
{
    long long sum=a[x]*((long long)(x-y))-(q[x-1]-q[y-1]);
    if(sum<=m)return 1;
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,l,r,mid,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        q[i]=q[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        l=1,r=i-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(i,mid))r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
