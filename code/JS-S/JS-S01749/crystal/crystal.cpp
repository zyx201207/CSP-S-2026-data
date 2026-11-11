#include<bits/stdc++.h>
#define ll long long
#define PI pair<int,int>
using namespace std;
int n;
ll m;
ll a[500005],sum[500005];
bool check(int x)
{
    for(int i=1;i+x-1<=n;i++)
    {
        ll use=a[i+x-1]*x-(sum[i+x-1]-sum[i-1]);
        if(use<=m)return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}
