#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long

const int N = 1.2e6+ 5;
const ll inf = 4e18;
const int mod = 998244353;

int c,n,m,d,q;
ll w[N];
int k[N];

int head[N],tot;
struct edge{
	int v,nxt;
	ll w;
}e[N];

void add_edge(int u,int v,int w){
	e[++tot].v = v;
	e[tot].w = w;
	e[tot].nxt = head[u];
	head[u] = tot;
}

ll dis[505][505];

void dijkstra(int s){
	vector<ll> dist(n + m + 1,inf);
	dist[s] = 0;
	bitset<(int)(6e5 + 5)> vis;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	q.push({0,s});
//	vis[s] = 1;
	while(!q.empty()){
		int u = q.top().second;
//		cout << u << ' ' << q.top().first << ' ';
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u];i;i = e[i].nxt){
			int v = e[i].v;
			ll w = e[i].w;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				q.push({dist[v],v});
			}
		}
	}
	for(int i = m + 1;i <= m + n;i++){
//		cout << d.ist[i] << ' ';
		dis[s - m][i - m] = min(dis[s - m][i - m],dist[i]);
	}
//	cout << "\n";
//	cout << s << '\n';
//	for(int i = 1;i <= n + m;i++){
//		cout << dist[i] << ' ';
//	}
//	cout << "\n";
}

void bfs(int st){
	queue<int> q;
	q.push(st);
	vector<int> dist(n + m + 1,0);
	bitset<N> vis;
	vis[st] = 1;
	while(!q.empty()){
		int u = q.front();
//		cout << u << ' ';
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			int v = e[i].v;
			if(vis[v]) continue;
			vis[v] = 1;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	for(int i = 1;i <= n;i++){
		dis[st - m][i] = min((ll)dist[i + m],dis[st - m][i]);
	}
//	cout << "\n";
}

void sol(){
	bool subB = 1;
	cin >> c >> n >> m >> d >> q;
	int cnt = m;
//	vector<vector<int>> ot(m + 1,vector<int>);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			dis[i][j] = dis[j][i] = inf;
		}
	}
	for(int i = 1;i <= m;i++){
		cin >> w[i];		
	} 
	ll lst = 0;
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		++cnt; 
		
		for(int j = 1;j <= k[i];j++){
			int a,t;
			cin >> a >> t;
			if(i == 1 && j == 1){
				lst = t;
			}
			else if(lst != t){
				subB = 0;
			}
//			cout << a << ' ' << cnt << '\n';
			add_edge(a,cnt,t);
			add_edge(cnt,a,t);
//			ot[a].push_back(cnt);
		} 
	}
	if(subB){
		for(int i = 1;i <= n;i++){
			int st = i + m;
			bfs(st);
		}
//		cout << dis[1][2] << ' ' << dis[2][1] << '\n';
		while(q--){
			int u,v;
			cin >> u >> v;
			ll ans = inf;
			for(int i = head[u];i;i = e[i].nxt){
				for(int j = head[v];j;j = e[j].nxt){
					int tou = e[i].v;
				    int tov = e[j].v;
				    ll wu = e[i].w;
				    ll wv = e[j].w;
					tou -= m;
					tov -= m;
					ans = min(ans,w[u] + w[v] + dis[tou][tov] * lst + wu + wv);
				}
			}
			cout << ans << "\n";
		}
		return ;
	}
//	for(int i = head[7];i;i = e[i].nxt){
//		cout << e[i].v << ' ';
//	}
	for(int i = m + 1;i <= n + m;i++){
	    dijkstra(i);
	}
//	cout << dis[1][2] << ' ' << dis[2][1] << '\n';
	while(q--){
		int u,v;
		cin >> u >> v;
		ll ans = inf;
		for(int i = head[u];i;i = e[i].nxt){
			for(int j = head[v];j;j = e[j].nxt){
			    int tou = e[i].v;
			    int tov = e[j].v;
			    ll wu = e[i].w;
			    ll wv = e[j].w;
				tou -= m;
				tov -= m;
				ans = min(ans,w[u] + w[v] + dis[tou][tov] + wu + wv);
			}
		}
		cout << ans << "\n";
	}
}

//#define LOCAL


signed main(){
	#ifndef LOCAL
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--){
		sol();
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 2 5 20 2
4 1 9 2 5
3 1 5 2 5 4 5
3 2 5 3 5 5 5
1 3
1 2

*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

