#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
const int N=5e5+5;
struct Q{
	int number;
	int line[N],time[N];
}p[505];

int c,n,m,d,q;
int w[N],dp[N][505];

inline void dfs(int u,int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p[i].number;j++){
			dp[]
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>p[i].number;
		for(int j=1;j<=p[i].number;j++){
			cin>>p[i].line[j]>>p[i].time[j];
		}
	}
	
	while(q--){
		int u,v;cin>>u>>v;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=INF;
			}
		}
		dp[u][1]=0;
		dfs(u,1);
		int mn=INF;
		for(int i=1;i<=n;i++) mn=min(mn,dp[v][i]);
		cout<<mn<<"\n";
	}
	
	return 0;
}