#include<bits/stdc++.h>
using namespace std;
long long n,c,t,d,x[2000005],ans;
long long dp[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];


        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)dp[i][j]=1e9;
        dp[1][1]=0;
        for(int j=2;j<=n;j++)
        {
            int cnt=0;
            for(int i=1;i<j;i++)
            {

                for(int k=1;k<=d;k++)
                {
                    if(x[j]-x[j-k]<=d){
                        if(dp[i][j]==dp[i][j-k]+1)cnt+=2;
                        else {
                            dp[i][j]=min(dp[i][j],dp[i][j-k]+1);

                        }
                    }

                    else break;
                }

            }
            if(cnt==2)ans++;
        }

        cout<<ans/2<<endl;
    }

    return 0;
}
