#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int v,w; 
};
const int N = 505,M = 5e5+5;
int c,n,m,d,q;
int w[M];
bool vis[1005];
vector<node> G[N];
ll dis[1005][1005];
node tr[205][405];
void dijkstra(int x){
	memset(vis,0,sizeof(vis));
	for(int i = 1;i<=m+5;i++)	dis[x][i] = 1e9;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({x,0});
	dis[x][x] = 0;
	while(!q.empty()){
		int hd1 = q.top().first,hd2 = q.top().second;
		q.pop();
		vis[hd1] = 1;
		for(node i:G[hd1]){
			if(!vis[i.v] && dis[x][hd1]+i.w<dis[x][i.v]){
				dis[x][i.v]=dis[x][hd1]+i.w;
				q.push({i.v,dis[x][i.v]});
			}
		}
	}
}
ll ans = LLONG_MAX;
void dfs(int pos,int s,int step){
	if(pos == s){
		ans = min(ans,step*1LL);
		return;
	}
	step+=w[pos];
	bool viss = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;tr[i][j].v!=0;j++){
			if(tr[i][j].v == pos){
				viss = 1;
			}
		}
		if(viss == 0)	continue;
		for(int j = 1;tr[i][j].v!=0;j++){
			if(vis[tr[i][j].v])	continue;
			vis[tr[i][j].v] = 1;
			dfs(tr[i][j].v,s,step+tr[i][j].w);
			vis[tr[i][j].v] = 0; 
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++)	cin >> w[i];
	if(7<=c && c<=11){
		for(int i = 1;i<=n;i++){
			int k;cin >> k;
			if(k == 2){
				int a,b,v,size;
				cin >> a >> b >> v >> size;
				G[i].push_back({v,size+b+w[i]});
				G[v].push_back({i,size+b+w[v]});
			}
		}
		for(int i = 1;i<=m;i++)	dijkstra(i);
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=m;j++){
				cout << dis[i][j] << ' ';
			}
			cout << '\n';
		}
		while(q--){
			int a,b;
			cin >> a >> b;
			cout << dis[a][b]+w[b] << '\n';
		}
	}else if(0 <=c && c<=6){
		for(int i = 1;i<=n;i++){
			int k;cin >> k;
			for(int j = 1;j<=k;j++){
				int a,t;
				cin >> a >> t;
				tr[i][j].v = a;
				tr[i][j].w = t;
				tr[i][a].w = t;
				tr[i][a].v = j;
			}
		}
		while(q--){
			int a,b;
			cin >> a >> b;
			ans = INT_MAX;
			dfs(a,b,0);
			cout << ans << '\n';
		}
	} 	
	return 0;
}