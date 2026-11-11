#include<bits/stdc++.h>
using namespace std;
int s,T,n,m,a[5005],dp[5005][5005],c[5005][5005];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) dp[i][j] = 1e9;
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	for(int i = n-1;i >= 1;i--){
		for(int j = i+1;a[j] - a[i] <= m && j <= n;j++){
			dp[i][j] = 1,c[i][j] = 1;
			for(int k = j+1;k <= n;k++){
				
				if(dp[i][j] + dp[j][k] == dp[i][k]){
					c[i][k] = min(3,c[i][j]*c[j][k]+c[i][k]);
//					if(i==1 && k==4 && j==3) putchar('p'),
//					printf("%dpp%dp",c[1][5],c[4][5]);
				}
				if(dp[i][j] + dp[j][k] < dp[i][k]){
					dp[i][k] = dp[i][j] + dp[j][k];
					c[i][k] = c[j][k];
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){//putchar('\n');
		for(int j = i+1;j<=n;j++){
//			printf("%d : %d   ",dp[i][j],c[i][j]);
			ans += (bool)(c[i][j] == 2);
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&s,&T);
	while(T--) solve();
	return 0;
}
