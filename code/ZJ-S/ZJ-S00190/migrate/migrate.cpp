#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        vector<int> a(n+1);
        for(int i=1;i<=n;++i) cin>>a[i];
        vector<int> dp(n+1,0);
        for(int i=4;i<=n;++i)
        {
            if(a[i]-a[i-3]>d&&a[i]-a[i-3]<2*d) dp[i]=dp[i-1]+1;
            else dp[i]=dp[i-1];
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}