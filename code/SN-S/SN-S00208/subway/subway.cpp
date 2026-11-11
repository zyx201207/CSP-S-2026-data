#include <bits/stdc++.h>
using namespace std;
#define SHIH_SSU 0
typedef long long ll;
const int N = 500505;
const int M = 1e5 + 5;
const ll INF = 1e17 + 5;

int c;
int n, m, d, _q;
ll w[N], Ans[M];
ll dis[N];
int h[N], cnt;
struct EDGE{
	int to, nxt;
	ll w;
}e[N << 2];
struct QUES{
	int u, v, idx;
	bool operator < (const QUES &x) const {
		return u < x.u;
	}
}Q[M];

inline void Add(int u, int v, ll w){
	e[++ cnt] = {v, h[u], w};
	h[u]= cnt;
}

struct NODE{
	int x; ll w;
	bool operator < (const NODE &a) const {
		return w > a.w;
	}
};
priority_queue<NODE> q;

inline void Dij(int s){
	for(int i = 1; i <= n + m; i ++) dis[i] = INF;
	dis[s] = 0LL; q.push({s, dis[s]});
	
	while(! q.empty()){
		NODE tmp = q.top(); q.pop();
		int x = tmp.x;
		for(int i = h[x]; i; i = e[i].nxt){
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].w){
				dis[y] = dis[x] + e[i].w;
				q.push({y, dis[y]});
			}
		}
	}
}

int main(){
//	freopen("subway6.in", "r", stdin);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> c >> n >> m >> d >> _q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++){
		int k; cin >> k;
		for(int j = 1; j <= k; j ++){
			int to; ll w; cin >> to >> w;
			Add(m + i, to, w); Add(to, m + i, w);
		}
	}
	for(int i = 1; i <= _q; i ++){
		int u, v; cin >> u >> v;
		Q[i] = {u, v, i};
	}
	
//	Dij(1);
//	for(int i = 1; i <= n + m; i ++) cout << dis[i] << ' ';
	
	sort(Q + 1, Q + _q + 1);
	for(int i = 1; i <= _q; i ++){
		if(Q[i].u != Q[i - 1].u) Dij(Q[i].u);
		Ans[Q[i].idx] = dis[Q[i].v] + w[Q[i].u] + w[Q[i].v];
	}
	
	for(int i = 1; i <= _q; i ++) cout << Ans[i] << '\n';
	
	return SHIH_SSU;
}
