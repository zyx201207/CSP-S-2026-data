#include<bits/stdc++.h>
using namespace std;
long long last[300001],dp[5005][5005];
long long n,m,a[500001],dp2[500005][5];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(last[a[i]]==0)
        {
            last[a[i]]=i;
        }
    }
    if(n<=5000)
    {
        for(int i=n;i>=1;i--)
        {
            if(last[a[i]]==i)
            {
                for(int j=1;j<=m;j++)
                {
                    dp[i][j]=dp[i+1][j];
                }
                dp[i][a[i]]++;
            }
            else
            {
                for(int j=1;j<=m;j++)
                {
                    dp[i][j]=dp[last[a[i]]+1][j];
                }
                dp[i][a[i]]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            long long sum=0;
            for(int j=1;j<=n;j++)
            {
                sum+=dp[j][i];
            }
            cout<<sum<<' ';
        }
        return 0;
    }
    for(int i=n;i>=1;i--)
    {
        if(last[a[i]]==i)
        {
            for(int j=1;j<=m;j++)
            {
                dp2[i][j]=dp2[i+1][j];
            }
            dp2[i][a[i]]++;
        }
        else
        {
            for(int j=1;j<=m;j++)
            {
                dp2[i][j]=dp2[last[a[i]]+1][j];
            }
            dp2[i][a[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        long long sum=0;
        for(int j=1;j<=n;j++)
        {
            sum+=dp2[j][i];
        }
        cout<<sum<<' ';
    }
    return 0;
}
