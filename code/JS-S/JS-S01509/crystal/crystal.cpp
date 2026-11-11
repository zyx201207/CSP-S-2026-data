#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,m,a[500005],s[500005],ans=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    l=0;
    for(int i=2;i<=n;i++)
    {
        while(l<i&&a[i]*(i-l)-s[i-1]+s[max(0ll,l-1)]>m) l++;
        ans=max(ans,i-max(1ll,l)+1);
    }
    cout<<ans;
}
