#include<bits/stdc++.h>
#define int long long
const int N=5e5; 
using namespace std;
int n,m,l=1;
int a[N+5],sum[N+5];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        while((i-l+1)*a[i]-(sum[i]-sum[l-1])>m&&l<=i) l++;
        ans=max(ans,i-l+1);
    }cout<<ans;
}