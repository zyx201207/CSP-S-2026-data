#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,ans=0;
    cin>>n>>m;
    vector<int> a(n+1,0);
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
    int l=0,r=0;
    while(r<=n)
    {
        if(sum[r]-sum[l-1]+m>=(r-l+1)*a[r])
        {
            ans=max(ans,r-l+1);
            r++;
        }
        else l++,r++;
    }
    cout<<ans;
    return 0;
}