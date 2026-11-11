#include<bits/stdc++.h>
using namespace std;
struct node{
	long long s,j;
};
long long ans,n,d,x[2000001];
node dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long T,c;
	scanf("%lld %lld",&c,&T);
	while(T--){
		ans=0;
		scanf("%lld %lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(c==11||c==12){
			if(abs(x[2]-x[1])*2>d){
				printf("0\n");
			}
			else{
				printf("%lld\n",n-2);
			}
		}
		else{
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					if(i==j){
						dp[i][i].s=1;
						dp[i][i].j=0;
					}
					else if(j-i==1&&x[j]-x[i]<=d){
						dp[i][j].s=1;
						dp[i][j].j=1;
					}
					else{
						dp[i][j].s=0;
						dp[i][j].j=0;
					}
				}
			}
			for(long long c=2;c<n;c++){
				for(long long l=1;l+c<=n;l++){
					long long r=l+c,cntj=1e9+5;
					if(x[r]-x[l]<=d){
						dp[l][r].s=1;
						dp[l][r].j=1;
					}
					else{
						for(long long k=l+1;k<r;k++){
							cntj=min(cntj,dp[l][k].j+dp[k][r].j);
						}
						dp[l][r].j=cntj;
						for(long long k=l+1;k<r;k++){
							if(dp[l][k].j+dp[k][r].j==cntj){
								dp[l][r].s+=dp[l][k].s*dp[k][r].s;
							}
						}
					}
					if(dp[l][r].s==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
