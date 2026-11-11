#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
long long ans=0;
struct Node{
    long long dis,cnt;
}dp[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j].dis=1e9;
            }
        }
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int j=1;j<=n;j++)
        {
            dp[j][j].dis=0;
            for(int i=j-1;i>=1;i--)
            {
                if(a[j]-a[i]<=d)
                {
                    dp[i][j].cnt=1;
                    dp[i][j].dis=1;
                }
                for(int k=i+1;k<j;k++)
                {
                    if(!(a[k]-a[i]<=d&&a[j]-a[k]<=d)) continue;
                    if(dp[i][j].dis>1+dp[k][j].dis)
                    {
                        dp[i][j].dis=1+dp[k][j].dis;
                        dp[i][j].cnt=dp[k][j].cnt;
                    }
                    if(dp[i][j].dis==1+dp[k][j].dis)
                    {
                        dp[i][j].cnt+=dp[k][j].cnt;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int i=j-1;i>=1;i--)
            {
                if(a[j]-a[i]<=d)
                {
                    dp[i][j].cnt=1;
                }
                for(int k=i+1;k<j;k++)
                {
                    if(!(a[k]-a[i]<=d&&a[j]-a[k]<=d)) continue;
                    if(dp[i][j].dis==1+dp[k][j].dis)
                    {
                        dp[i][j].cnt+=dp[k][j].cnt;
                    }
                }
                if(dp[i][j].cnt==2) ans++;
            }
        }
 /*       for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=n;j++)
            {
                cout<<dp[i][j].dis<<" ";
            }cout<<"\n";
        }cout<<"\n";
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=n;j++)
            {
                cout<<dp[i][j].cnt<<" ";
            }cout<<"\n";
        }*/
        cout<<ans;
    }
    return 0;
}
