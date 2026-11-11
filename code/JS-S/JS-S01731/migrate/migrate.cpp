#include<bits/stdc++.h>
using namespace std;
long long a[2000005],dp[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long n,d,sum=0,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dp[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dp[i][j]=a[j]-a[i];
            }
        }
        for(int len=1;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                sum=0;
                for(int k=i;k<j;k++){
                    if(dp[i][j]<dp[i][k]+dp[k][j] or dp[i][k]>d or dp[k][j]>d or dp[i][j]<=d){
                        continue;
                    }
                    if(dp[i][j]==dp[i][k]+dp[k][j]){
                        sum++;
                    }
                    else{
                        dp[i][j]=dp[i][k]+dp[k][j];
                        sum=0;
                    }
                }
                if(sum==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
