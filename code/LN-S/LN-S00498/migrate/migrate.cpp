#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int cnt[1000001];
int x[1000001];
int main()
{
    //freopen("migrate.in","r",stdin);
   // freopen("migrate.out","w",stdout);
    int c;
    cin>>c;
    int t;
    cin>>t;
 //   cout<<c<<t;
    while(t--)
    {
        memset(x,0,sizeof(x));
        int n;
        long long d;
        long long ans=0;
        cin>>n>>d;
        cout<<n<<d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int j=1;j<n;j++)
        {
            memset(dp,0x7f7f7f7f,sizeof(dp));
            dp[j]=0;
            memset(cnt,0,sizeof(cnt));
            int xx=j;
            for(int k=j;k<=n;k++)
            {
                while(x[k]-x[j]>d)xx++;
                for(int l=xx;l<k;l++)
                {
                    if(dp[k]>dp[l]+1)
                    {
                        dp[k]=dp[l]+1;
                        cnt[k]=0;
                    }
                    else if(dp[k]==dp[l]+1)cnt[k]++;
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(cnt[j]==2)ans++;
        }
        cout<<ans;
    }
    return 0;
}
