#include<bits/stdc++.h>
using namespace std;
long long sx,t,n,m,s[5005],dp[305][305][305];
void dfs(long long f,long long d,long long x){
	if(d>n)return;
	for(int i=d+1;i<=n;i++){
		if(s[i]-s[d]>m)break;
		dp[f][i][x+1]+=dp[f][d][x];
		dfs(f,i,x+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>sx>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>s[i];
		long long ans=0;
		for(int i=1;i<=n;i++){
			
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++)dp[i][j][k]=0;
			}
			dp[i][i][0]=1;
			dfs(i,i,0);
		}
		for(int k=1;k<=n;k++){
			for(int i=k+1;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(dp[k][i][j]!=0){
					if(dp[k][i][j]==2)ans++;	
					
					break;
				}
			}
		}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}//rp--;