#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN=5e5+10;
long long a[MAXN];
long long sum[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        while(ans<i&&a[i]*(ans+1)-(sum[i]-sum[i-ans-1])<=m)ans++;
    }
    cout<<ans;
}