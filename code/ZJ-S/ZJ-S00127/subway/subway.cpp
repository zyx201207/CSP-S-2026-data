#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e17 + 100;
const int M = 440;
const int N = 220;
int w[N];
int k[N];
int a[N][M],t[N][M];
struct Eg{
	int v,id;
};
vector<Eg> E[M];
struct Node{
	int dis,x,id;
	bool operator >(const Node& xx) const{
		return xx.dis < dis;
	}
}; 
bool vis[M][N];
int dis[M][N];//到站台i,路线为j的最小步行时间
//不去站台,直到到终点
void Dijkstra(int s){
	memset(vis,false,sizeof(vis));
	for(int i = 0; i <= N; ++i) dis[s][i] = 0;
	priority_queue<Node,vector<Node>,greater<Node> > q;
	Node start; start.dis = 0,start.id = 0,start.x = s;
	q.push(start);
	while(!q.empty()){
		Node top = q.top(); q.pop();
		//cout << top.dis << ' ' << top.id << ' ' << top.x << '\n';
		if(vis[top.x][top.id]) continue;
		vis[top.x][top.id] = true;
		for(int i = 0; i < E[top.x].size(); ++i){
			int v = E[top.x][i].v,id = E[top.x][i].id;
			if(id != top.id){
				int dd = top.dis + t[top.id][top.x] + t[id][top.x];
				//if(v == 3 && top.id == 1) cout << dd << ' ' << top.x << ' ' << top.dis << ' ' << top.id << ' ' << id << ' ' << v << ' ' << t[top.id][top.x] << ' ' << t[id][top.x] << '\n';
				if(dd < dis[v][id]){
					dis[v][id] = dd;
					Node news;
					news.dis = dd,news.id = id,news.x = v;
					q.push(news);
				}
			}else{
				int dd = top.dis;
				if(dd < dis[v][id]){
					dis[v][id] = dd;
					Node news;
					news.dis = dd,news.id = id,news.x = v;
					q.push(news);
				}
			}
		}
	}
} 
signed main(){
	//subway
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	if(!(cin >> c >> n >> m >> d >> q)) return 0;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i){
		cin >> k[i];
		for(int j = 1; j <= k[i]; ++j){
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			//cout << a[i][j] << ' ' << j << '\n';
			if(j > 1){
				//cout << "OK?\n";
				Eg xx; xx.id = i;
				xx.v = a[i][j]; E[a[i][j-1]].push_back(xx);
				xx.v = a[i][j-1]; E[a[i][j]].push_back(xx);
			}
		}
	}
	//cout << t[1][2] << ' ' << t[2][2] << '\n';
	while(q--){
		memset(dis,0x3f,sizeof(dis));
		int x,y; cin >> x >> y;
		Dijkstra(x);
		int mn = INF;
		//cout << dis[2][1] << '\n';
		for(int i = 1; i <= n; i++) mn = min(mn,dis[y][i]+t[i][y]);
		cout << mn+w[x]+w[y] << '\n';
	}
}
