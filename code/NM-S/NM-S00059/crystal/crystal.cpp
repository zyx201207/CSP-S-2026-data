#include<bits/stdc++.h>
using namespace std;
long long a[500001],s[500001],ans=1,m,n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
    for(long long i=2;i<=n;i++)if(a[i]*(i-1)-s[i-1]<=m)ans=max(ans,i);
    cout<<ans;
    return 0;
}
