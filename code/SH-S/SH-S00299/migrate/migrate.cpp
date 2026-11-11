#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int k;
int a[5005];
int dp[5005][5005];
int g[5005][5005];
int bfs(int s,int e){
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().first;
		int num=q.front().second;
		if(u==e){
			return num;
		}
		q.pop();
		for(int i=u+1;i<=e;i++){
			if(a[i]-a[u]<=k){
				q.push({i,num+1});
			} 
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(g,0x3f,sizeof(g));
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dp[i][i]=1;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=k){
					dp[i][j]=1;
				}
				g[i][j]=bfs(i,j);
			}
		}
		for(int Len=1;Len<=n;Len++){
			for(int i=1,j=i+Len;i<=n&&j<=n;i++){
				for(int k=i+1;k<j;k++){
					if(g[i][k]+g[k][j]==g[i][j]){
//						cout<<k<<endl;
						dp[i][j]+=dp[i][k]+dp[k][j]-1;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<i<<"->"<<j<<' '<<dp[i][j]<<endl;
				if(dp[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//si lu : DP
//dan cuo le
//ze me ban!!!!
