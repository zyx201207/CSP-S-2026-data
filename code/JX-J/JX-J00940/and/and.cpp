#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long dp[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=m;i++)
        dp[i]=0;
    sort(a+1,a+n+1);
    dp[1]=a[1];
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            dp[j]=max(dp[j],(dp[j-1]&a[i]));
        }
        dp[1]=a[i];
    }
    cout<<dp[m];
    return 0;
}
