#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,T;
int n,d;
int a[N];
int dp[N][N];
void dfs(int y,int x){
	if(y==n){
		return ;
	}
	for(int i=y;i<=n;i++){
		
		if(i==y||(a[i]-a[y])!=d)continue;
		dp[i][x]++;
		dp[x][i]++;
		dfs(i,x);
	}
}
void dfs1(int dep,int y){
	for(int i=dep;i<=n;i++){
		if(a[n]-a[i]<d){
			dp[dep][y]++;
			dp[y][dep]++;
			return ;
		}
	}
	for(int i=dep;i<=n;i++){
		if(i==dep||(a[i]-a[dep])!=d)continue;
		dp[i][dep]++;
		dp[dep][i]++;
		dfs(i,y);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int u=1;u<=n;u++)
			for(int v=u;v<=n;v++){
				if(a[u]-a[v]<=d){
					for(int i=v;i<=n;i++){
						if(a[i]-a[v]==d){
							dp[u][i]++;
							dp[i][u]++;
							dp[v][i]++;
							dp[i][v]++;
						}
					}
				}
			}	
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(a[i]-a[j]==d){
						dp[i][j]++;dp[j][i]++;
						i=j;
						break;
					}
				}
				if(a[n]-a[i]<d){
					dp[n][i]++;
					dp[i][n]++;
					break;
				}
			}
		
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(dp[i][j]==2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


