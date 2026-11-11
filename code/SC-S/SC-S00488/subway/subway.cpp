#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
long long w[N];
vector<int> sta[N];
vector<int> sub[505];
vector<int> nxt[505];
long long dp[505][505];
unordered_map<long long,long long> cst[505];
bool vis[505];
void dfs(int now){
	for(int x:sub[now]){
		for(int v:sta[x]){
			if(v==now)continue;
			dp[now][v]=min(dp[now][v],cst[now][x]+cst[v][x]);
			dp[v][now]=dp[now][v];
			nxt[now].push_back(v);
		}
	}
}
void fu(int rt,int u){	
	for(int i:nxt[u]){	
 	if(vis[i])continue;
		dp[rt][i]=min(dp[rt][i],dp[rt][u]+dp[u][i]);
		dp[i][rt]=dp[rt][i];
		vis[i]=1;
		fu(rt,i);
		vis[i]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dp[i][j]=1e18;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		int k;cin>>k;
		for(int j=1;j<=k;j++){	
			int num,t;cin>>num>>t;
			sub[i].push_back(num);
			sta[num].push_back(i);
			cst[i][num]=t;
		}
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i);
		vis[i]=0;
	}	
	for(int i=1;i<=n;i++){
		vis[i]=1;
		fu(i,i);
		vis[i]=0;
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		long long mi=1e18;
		for(int x:sta[a]){
			for(int y:sta[b]){
				mi=min(mi,dp[x][y]+cst[x][a]+cst[y][b]);
			}
		}
		cout<<w[a]+w[b]+mi<<"\n";
	}
	return 0;
} 