#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int RP=1e18+7;
const int N=507,M=5e4+17;
const int N2=5,M2=5e5+17;
int c,n,m,d,q,w[M2];
int dis[N][N+M];
int dis2[N2][N2+M2];
bool vis[N+M];
bool vis2[N2+M2];
bool vis3[N];
struct node{
	int id,val;
	friend bool operator<(node x,node y){
		return x.val>y.val;
	}
};
vector<node> g[N+M];
priority_queue<node> pq;
void Dijkstra(int s){
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n+m;i++){
		dis[s][i]=RP;
		vis[i]=0;
	}
	dis[s][m+s]=0;
	pq.push({m+s,0});
	while(!pq.empty()){
		node t=pq.top();
		pq.pop();
		int u=t.id;
		if(vis[u]) continue;
		vis[u]=1;
		for(node tt : g[u]){
			int v=tt.id,w=tt.val;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				pq.push({v,dis[s][v]});
			}
		}
	}
}
vector<node> g2[N2+M2];
priority_queue<node> pq2;
void Dijkstra2(int s){
	while(!pq2.empty()) pq2.pop();
	for(int i=1;i<=n+m;i++){
		dis2[s][i]=RP;
		vis2[i]=0;
	}
	dis2[s][m+s]=0;
	pq2.push({m+s,0});
	while(!pq2.empty()){
		node t=pq2.top();
		pq2.pop();
		int u=t.id;
		if(vis2[u]) continue;
		vis2[u]=1;
		for(node tt : g2[u]){
			int v=tt.id,w=tt.val;
			if(dis2[s][v]>dis2[s][u]+w){
				dis2[s][v]=dis2[s][u]+w;
				pq2.push({v,dis2[s][v]});
			}
		}
	}
}
int g3[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==20 || c==21){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a,t;
				cin>>a>>t;
				g2[m+i].push_back({a,t});
				g2[a].push_back({m+i,t});
			}
		}
		for(int i=1;i<=n;i++){
			Dijkstra2(i);
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			int ans=RP; 
			for(node t : g2[x])
				ans=min(ans,t.val+dis2[t.id-m][y]);
			ans+=w[x]+w[y];
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c==22 || c==23){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a,t;
				cin>>a>>t;
				g[m+i].push_back({a,t});
				g[a].push_back({m+i,t});
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g3[i][j]=(i==j)?0:RP;
		for(int i=1;i<=m;i++){
			if(g[i].size()==2){
				int u=g[i][0].id-m;
				int v=g[i][1].id-m;
				int w=g[i][0].val+g[i][1].val;
				g3[u][v]=g3[v][u]=min(g3[u][v],w);
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					g3[i][j]=min(g3[i][j],g3[i][k]+g3[k][j]);
		while(q--){
			int x,y;
			cin>>x>>y;
			int ans=RP; 
			for(node t1 : g[x])
				for(node t2 : g[y])
					ans=min(ans,t1.val+t2.val+g3[t1.id-m][t2.id-m]);
			ans+=w[x]+w[y];
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[m+i].push_back({a,t});
			g[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=n;i++){
		Dijkstra(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=RP; 
		for(node t : g[x])
			ans=min(ans,t.val+dis[t.id-m][y]);
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}


