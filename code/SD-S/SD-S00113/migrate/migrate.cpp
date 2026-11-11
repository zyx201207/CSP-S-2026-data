#include<bits/stdc++.h>
using namespace std;
long long arr[2000005];
int dp[2000005];
struct node{
	int x,y;
}dp1[505][505];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
		}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(arr[j]-arr[i]>d)
						break;
					dp1[i][j].y=1,dp1[i][j].x=1;
				}
			}
			int ans=0;
			for(int i=1;i<n;i++){
				for(int t=i+1;t<n;t++){
					for(int j=t+1;dp1[t][j].y>0;j++){
						if(dp1[i][j].y==0){
							dp1[i][j].y=dp1[i][t].y+dp1[t][j].y;
							dp1[i][j].x=dp1[i][t].x*dp1[t][j].x;
						}else if(dp1[i][j].y>dp1[i][t].y+dp1[t][j].y){
							dp1[i][j].y=dp1[i][t].y+dp1[t][j].y;
							dp1[i][j].x=dp1[i][t].x*dp1[t][j].x;
						}else if(dp1[i][j].y==dp1[i][t].y+dp1[t][j].y){
							dp1[i][j].y=dp1[i][t].y+dp1[t][j].y;
							dp1[i][j].x+=dp1[i][t].x*dp1[t][j].x;
						}
					}
				}
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(dp1[i][j].y&&dp1[i][j].x==2){
						ans++;
					}
					dp1[i][j].x=0,dp1[i][j].y=0;
				}
			}
			printf("%d\n",ans);
	}
	return 0;
}

