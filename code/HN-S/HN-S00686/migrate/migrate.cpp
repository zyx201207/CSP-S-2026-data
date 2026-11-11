#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long dp[2000005];
long long c,t;
long long cost[2000005];
long long num=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++){
		num=0;
		for(int j=1;j<=n;j++){
			dp[j]=0;
		}
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&cost[i]);
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(abs(cost[k]-cost[j])<=d){
					dp[k]++; 
				}
				else continue;
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i]>=2){
				num++;
			}
		}
		printf("%lld\n",num-1);
	}
	return 0;
} 
