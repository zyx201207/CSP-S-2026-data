#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
const int N=5e2+5;
int c,n,m,d,Q;
int w[M];
int head[M+N],nxt[(M+N)<<1],to[(M+N)<<1],val[(M+N)<<1];
int tot=0;
void inline add(int u,int v,int w){
	nxt[++tot]=head[u];
	to[tot]=v;val[tot]=w;
	head[u]=tot;
}
const int K=2e4+5;
int dis[K+N][N];
int dp[M+5][5];
const int INF=1e18;
struct node{
	int i,v;
	bool operator<(const node &A)const{
		return v>A.v;
	}
};
priority_queue<node>q;
int mark[M+N];
void dijkstra(int s){
	while(!q.empty())q.pop();
	for(int i=1;i<=n+m;i++)dp[i][s]=INF;
	for(int i=1;i<=n+m;i++)mark[i]=0;
	dp[s][s]=0;q.push((node)<%s,dp[s][s]%>);
	while(!q.empty()){
		int u=q.top().i;q.pop();
		if(mark[u])continue;
		mark[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],t=val[i];
			if(dp[v][s]>dp[u][s]+t){
				dp[v][s]=dp[u][s]+t;
				//cout<<s<<" "<<u<<" "<<v<<" "<<dp[u][s]<<" "<<dp[v][s]<<"\n";
				q.push((node)<%v,dp[v][s]%>);
			}
		}
	}
}
void Dijkstra(int s){
	while(!q.empty())q.pop();
	for(int i=1;i<=n+m;i++)dis[i][s]=INF;
	for(int i=1;i<=n+m;i++)mark[i]=0;
	dis[s][s]=0;q.push((node)<%s,dis[s][s]%>);
	while(!q.empty()){
		int u=q.top().i;q.pop();
		if(mark[u])continue;
		mark[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],t=val[i];
			if(dis[v][s]>dis[u][s]+t){
				dis[v][s]=dis[u][s]+t;
				//cout<<s<<" "<<u<<" "<<v<<" "<<dis[u][s]<<" "<<dis[v][s]<<"\n";
				q.push((node)<%v,dis[v][s]%>);
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand((unsigned)time(0));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int ch;cin>>ch;
		for(int j=1;j<=ch;j++){
			int v,t;cin>>v>>t;
			add(i,v+n,t);add(v+n,i,t);
			//cout<<i<<" "<<j+n<<"\n";
		}
	}
	if(n<=2){
		for(int i=1;i<=n;i++)dijkstra(i);
		for(int i=1;i<=Q;i++){
			int u,v;cin>>u>>v;
			u+=n;v+=n;
			int ans=INF;
			for(int j=1;j<=n;j++){
				//cout<<"!"<<u<<" "<<v<<" "<<j<<" "<<dp[u][j]<<" "<<dp[v][j]<<" "<<ans<<"\n";
				ans=min(ans,dp[u][j]+dp[v][j]+w[u-n]+w[v-n]);
			}
			cout<<ans<<"\n";
	    }
		return 0;
	}
	for(int i=1;i<=n;i++){
		Dijkstra(i);
	}
	for(int i=1;i<=Q;i++){
		int u,v;cin>>u>>v;
		u+=n;v+=n;
		int ans=INF;
		for(int j=1;j<=n;j++){
			//cout<<"!"<<u<<" "<<v<<" "<<j<<" "<<dis[u][j]<<" "<<dis[v][j]<<" "<<ans<<"\n";
			ans=min(ans,dis[u][j]+dis[v][j]+w[u-n]+w[v-n]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/