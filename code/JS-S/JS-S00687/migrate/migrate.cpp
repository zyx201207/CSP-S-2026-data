#include<bits/stdc++.h>
using namespace std;
int c,n,t;
pair<int,int> dp[5005][5005];
long long d,x[5005],p;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int e=1;e<=t;e++){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                dp[i][j].first=-1;
                dp[i][j].second=0;
            }
        }
        p=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            if(i>=2 && x[i]-x[i-1]<=d) dp[i-1][1].first=1,dp[i-1][1].second=1;
            else dp[i-1][1].first=1e9;
        }
        for(int j=2;j<n;j++){
            for(int i=1;i<=n-j;i++){
                if(x[i+j]-x[i]<=d) dp[i][j].first=1,dp[i][j].second=1;
                else{
                    for(int k=1;k<j;k++){
                        if(dp[i][k].first==1e9 || dp[i+k][j-k].first==1e9) dp[i][j].first=1e9;
                        else{
                            if(dp[i][j].first>dp[i][k].first+dp[i+k][j-k].first || dp[i][j].first==-1) dp[i][j].first=dp[i][k].first+dp[i+k][j-k].first,dp[i][j].second=dp[i][k].second*dp[i+k][j-k].second;
                            else if(dp[i][j].first==dp[i][k].first+dp[i+k][j-k].first) dp[i][j].second+=dp[i][k].second*dp[i+k][j-k].second;
                        }
                    }
                    if(dp[i][j].second==2) p++;
                }
            }
        }
        cout<<p<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
