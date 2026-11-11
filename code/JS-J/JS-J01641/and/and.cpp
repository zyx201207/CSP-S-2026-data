#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005][2005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    int q;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1) q=a[i];
        else q=q&a[i];
    }
    if(n==m)
    {
        cout<<q;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j!=1)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],a[i]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}

