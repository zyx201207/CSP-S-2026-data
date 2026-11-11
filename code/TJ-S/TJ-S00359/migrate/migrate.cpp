#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[5001];
pair<long long,long long>dp[5001][5001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(;t--;){
    	scanf("%d%lld",&n,&d);
    	for(int i=1;i<=n;i++)
    		scanf("%lld",&x[i]);
    	for(int i=1;i<=n;i++)
    		for(int j=i+1;j<=n;j++)
    			dp[i][j].first=1 << 30;
    	for(int i=1;i<=n;i++)
    		dp[i][i].first=0,dp[i][i].second=1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++)
				for(int k=j;k>=i;k--){
					if(abs(x[j]-x[k])<=d){
						if(dp[i][k].first+1<dp[i][j].first){
							dp[i][j].first=dp[i][k].first+1;
							dp[i][j].second=dp[i][k].second;
						}else if(dp[i][k].first+1==dp[i][j].first){
							dp[i][j].second+=dp[i][k].second;
						}
					}else{
						break;
					}
				}
			
		}
		int cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j].second==2)
					cnt++;
			}
		}
		printf("%d\n",cnt);
	}
}
