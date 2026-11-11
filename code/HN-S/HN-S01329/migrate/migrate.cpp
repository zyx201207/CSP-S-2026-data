#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans[2000005]={0},dp[2000005];
long long d,x[2000005];
void dfs(int nps,int stp){
	int nxt=nps+1;
	while(nxt<=n){
		if(x[nxt]<=x[nps]+d){
			if(stp+1==dp[nxt])ans[nxt]+=ans[nps];
			if(stp+1<dp[nxt]){
				dp[nxt]=stp+1;
				ans[nxt]=ans[nps];
			}
		}
		dfs(nxt,stp+1);
		nxt++;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=0;j<=n;j++){
			ans[j]=0;
			dp[j]=1e9+5;
		}
		for(int j=1;j<=n;j++)cin>>x[j];
		for(int j=1;j<=n;j++){
			ans[j]=1;
			dfs(j,0);
			for(int k=j+1;k<=n;k++){
				if(ans[k]==2)ans[0]++;
				ans[k]=0;
			}
		}	
		cout<<ans[0]<<endl;	
	}
	return 0;
}
