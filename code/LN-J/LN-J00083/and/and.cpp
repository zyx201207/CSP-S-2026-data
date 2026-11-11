#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int dp[200005],a[200005];
int yu(int x,int y)
{
    return x&y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i]=a[i];
    }
    for(int k=1;k<=m;k++)
    {

        for(int i=1;i<=n;i++)
        {
            for(int j=n-i;j>=1;j--)
            {
                dp[i+j]=max(dp[i+j],yu(dp[i],a[i+j]));
            }
        }
    }
    cout<<dp[n];
    return 0;
}

