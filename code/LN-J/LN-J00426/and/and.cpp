#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N];
int dp[N];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(j==1) dp[j] = max(dp[j],a[i]);
            dp[j] = max(dp[j],dp[j-1] & a[i]);
        }
    }
    cout<<dp[m];

    return 0;
}
