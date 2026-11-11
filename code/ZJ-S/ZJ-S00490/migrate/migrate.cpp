#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,m,ans,klay;
int a[N],b[N][N];
int dp[N][N];
int num[N][N];
void dfs(int u){
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]<=m){
			num[u][i]++;
			if(num[u][i]==2) ans++;
			dfs(i);
		}
	}
}
int main(){
	freopen("migrate .in","r",stdin);
	freopen("migrate .out","w",stdout);
    cin>>c>>t;
    while(t--){
    	memset(dp,0x3f3f3f3f,sizeof dp);
    	ans=0;
    	cin>>n>>m;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		for(int i=1;i<n;i++){
			dp[i][i+1]=1;
			b[i][i+1]=i;
		}
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				if(a[b[i][j-1]]+m>=a[j]){
					dp[i][j]=min(dp[i][j],dp[i][j-1]);
				}
				else dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
