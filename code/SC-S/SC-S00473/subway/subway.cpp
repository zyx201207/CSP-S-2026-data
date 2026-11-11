#include<bits/stdc++.h>
using namespace std;
long long dp[505][505],w[500005],dis[505][505];
map<long long,long long>t[500005];
vector<long long>vis[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long ai,ti;
			cin>>ai>>ti;
			vis[ai].push_back(i);
			t[ai][i]=ti;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			dp[i][j]=1e18;
		}
	}
//	cout<<'!'<<'\n'; 
	for(long long k=1;k<=m;k++){
		for(long long i:vis[k]){
			for(long long j:vis[k]){
				dp[i][j]=min(dp[i][j],t[k][i]+t[k][j]);
			}
		}
	}
//	cout<<'!'<<'\n';
//	cout<<'!'<<'\n';
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			} 
		}
	}
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++){
//			cout<<dp[i][j]<<' '; 
//		}
//		cout<<'\n';
//	}
//	cout<<'!'<<'\n';
	while(q--){
		long long x,y,an=1e18;
		cin>>x>>y;
		for(long long i:vis[x]){
			for(long long j:vis[y]){
				an=min(an,dp[i][j]+t[x][i]+t[y][j]+w[x]+w[y]);
			}
		} 
		cout<<an<<'\n';
	}
//	cout<<'!'<<'\n';
	return 0;
}
//代码敲慢一点！！！
//注意freopen
//注意数组大小
//注意函数返回值
//注意取模


