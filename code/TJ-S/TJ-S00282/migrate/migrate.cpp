#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+1;
int c,t,n,d,x[N],flag[301][301];
ll dp[301][301],ans;
void dfs(int s,int u,int num){//跑一遍 
	for(int i=u+1;i<=n;i++){
		
		if(x[i]-x[u]<=d){//能够跑 
//		cout<<s<<' '<<i<<' '<<dp[s][i]<<'\n';
			if(dp[s][i]==num+1){
				flag[s][i]++;
			}else{
				if(dp[s][i]>num+1){
					dp[s][i]=num+1;
					flag[s][i]=1;
				}
			}
			dfs(s,i,num+1);
		}else return;
	} 
}
void init(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0x3f3f3f3f;
			flag[i][j]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	
		cin>>n>>d;
			init();
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){//枚举起点 
			dfs(i,i,0);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(flag[i][j]==2){
					ans++;
					
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

