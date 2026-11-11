#include<bits/stdc++.h>
#define int long long
#define ys ios::sync_with_stdio(0);
#define mc cin.tie(0);
#define zmdNB cout.tie(0);
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1000+10,inf=1e18;
int n,m,C,d,q,w[N],k,x,y,dp[N*N],cnt,u,v,a[N][N],t[N][N];
bool is[N*N];
struct edge{
	int v,w;
};
vector<edge>g[N*N];
int getid(int x,int y){
	return x*m+y;
}
int dj(int st,int ed){
	for(int i=1;i<=cnt;i++){
		dp[i]=inf;
		is[i]=0;
	}
	dp[st]=0;
	priority_queue<pii,vector<pii>,greater<pii>> d;
	d.push({0,st});
	while(!d.empty()){
		int u=d.top().second;
		d.pop();
		if(u==ed)return dp[u];
		if(is[u])continue;
		is[u]=1;
		for(auto vv:g[u]){
			int v=vv.v,w=vv.w;
			if(dp[u]+w<dp[v]){
				dp[v]=dp[u]+w;
				d.push({dp[v],v});
			}
		}
	}
	return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ys mc zmdNB
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			if(j>1){
				u=getid(i,a[i][j]),v=getid(i,a[i][j-1]);
				g[u].push_back({v,0});
				g[v].push_back({u,0});
			}
		}
	}
	cnt=(n+1)*m;
	for(int i=1;i<=m;i++){
		cnt++;
		for(int j=0;j<=n;j++){
			u=getid(j,i),v=cnt;int w=t[j][i];
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dj(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
