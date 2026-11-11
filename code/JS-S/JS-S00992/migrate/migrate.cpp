#include<bits/stdc++.h>
using namespace std;
long long dp[2111111],a[2111111],ans[2111111];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n;
        long long d;
        cin>>n>>d;
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        ans[0]=1;
        dp[0]=1;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(a[i]-a[j]>d)
                    break;
                if(dp[i]==0)
                    dp[i]=dp[j]+1;
                else
                    dp[i]=min(dp[i],dp[j]+1);
            }
            for(int j=i-1;j>=0;j--)
            {
                if(a[i]-a[j]>d)
                    break;
                if(dp[j]+1==dp[i])
                    ans[i]+=ans[j];
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(ans[j]-ans[i]+1==2)
                    sum++;
        cout<<sum<<endl;
    }
    return 0;
}