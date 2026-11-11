#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n+1);
    long long maxn=-1;
    long long mx;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(maxn<a[i])
        {
            maxn=a[i];
            mx=i;
        }
    }
    vector<bool> isy(n+1,true);
    isy[mx]=false;
    vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
    //for(int i=1;i<=n;i++)
    //{
    //   dp[i][1]=a[i];
    //}
    //vector<long long> dp(m+1,-1);
    //cout<<dp[1];
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            if(i+j-1<=n)
            {
                dp[i][j]=max(dp[i][j-1]&a[i+j-1],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }

    }
    cout<<dp[n][m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
