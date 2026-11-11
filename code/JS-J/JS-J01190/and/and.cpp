#include <iostream>
#include <climits>
using namespace std;
int n,m;
int dp[200005],a[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0]=INT_MAX;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            dp[j]=max(dp[j],dp[j-1]&a[i]);
    cout<<dp[m]<<endl;
    return 0;
}

