#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define piii pair<int, pii>

//#define DEBUG

/*
	Consider Dijkstra with conditions
	Failed, reconsider later
*/

const int N = 510, M = 5e3 + 10;
int w[M];
int t[N][M];
vector<int> st[M];
int h[M];
int cnt;
bool vis[M][N];
int dis[M][N];

struct Edge{
	int to, l, nxt;
} e[M * 100];

struct Node{
	int dis, u, l;
};

bool cmp(Node a, Node b){
	return a.dis > b.dis;
}

void ae(int u, int v, int l){
	e[cnt].to = v;
	e[cnt].l = l;
	e[cnt].nxt = h[u];
	h[u] = cnt ++;
}

inline void tmn(int a, int &b){
	if (a < b) b = a;
}

void dij(int s){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	for(int i : st[s]){
		dis[s][i] = w[s] + t[i][s];
		pq.push({dis[s][i], {s, i}});
	}
	while(!pq.empty()){
		int u = pq.top().second.first;
		int l = pq.top().second.second;
		pq.pop();
		if(vis[u][l]) continue;
		vis[u][l] = true;
		for(int i = h[u]; ~i; i = e[u].nxt){
			int v = e[u].to; int l_v = e[u].l;
			if(l == l_v) dis[v][l_v] = dis[u][l];
			else tmn(dis[u][l] + t[l][u] + t[l_v][u], dis[v][l_v]);
			pq.push({dis[v][l_v], {v, l_v}});
		}
	}
}



signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	#ifdef DEBUG
	cout << "Completed 1 !\n";
	#endif
	
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	memset(h, -1, sizeof(h));
	
	for(int i = 1; i<=m; i++) cin >>w[i];
	for(int i = 1; i<=n; i++){
		int k; cin >> k;
		int cur=0, lst;
		while(k--){
			lst = cur;
			int station, time; cin >> station >> time;
			cur = station;
			if(lst){
				ae(lst, cnt, i);
				ae(cnt, lst, i);
			}
			t[i][station] = time;
			st[station].push_back(i);
		}
	}
	
	while(q--){
		int xx, yy;
		cin >> xx >> yy;
		dij(xx);
		int ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1; i<=n; i++){
			ans = min(ans, dis[yy][i] + t[i][yy] + w[yy]);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
