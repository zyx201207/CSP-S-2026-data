#include<bits/stdc++.h>
using namespace std;
int cost[500005];
int x,y;
long long dp[505];
long long mi[505][505];
int c,n,m,d,q;
struct node{
	int v;
	long long w; 
	operator< (const node&__x) const{
		return w<__x.w; 
	}
};
vector<node> lu[500005];
vector<node> g[505];
long long l[505][505];
priority_queue<node> qr; 
long long tim=0;
long long dij(){
	for(int i=1;i<=n;i++){
		dp[i]=0x3f3f3f3f3f3f3f3f;
	}
	dp[x]=0;
	node st={x,0};
	qr.push(st);
	while(!qr.empty()){
		node t=qr.top();
		qr.pop();
		int u=t.v;
		for(auto v:g[u]){
			if(dp[u]+v.w<dp[v.v]){
				dp[v.v]=dp[u]+v.w;
				qr.push(node{v.v,dp[v.v]});
			}
		}
	}
	dp[x]=0;
	for(int i=1;i<=n;i++){
		l[x][i]=dp[i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mi[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>cost[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u;
			long long w;
			cin>>u>>w;
			lu[u].push_back(node{i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)lu[i].size();j++){
			for(int k=0;k<(int)lu[i].size();k++){
				node u=lu[i][j];
				node v=lu[i][k];
				if(j!=k){
					mi[u.v][v.v]=min(mi[u.v][v.v],u.w+v.w);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				g[i].push_back(node{j,mi[i][j]});
			}
		}
	}
	for(x=1;x<=n;x++){
		dij();
	}
	while(q--){
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<(int)lu[x].size();j++){
			for(int k=0;k<(int)lu[y].size();k++){
				node u=lu[x][j];
				node v=lu[y][k];
				ans=min(ans,l[u.v][v.v]+u.w+v.w);
			}
		}
		cout<<ans+(long long)cost[x]+(long long)cost[y]<<'\n';
	}
	return 0;
}