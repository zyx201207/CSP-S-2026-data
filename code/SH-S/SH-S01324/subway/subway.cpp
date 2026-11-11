#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505, K = 5e5+5, M = 5e5+5;
int n, m, c, dd, q;
ll k, w[M], cnta[N];
ll a[K], totf;
ll ans, t[K];
ll d[2*K];
bool vis[2*K];
vector<pair<int, ll> > f[M];
int nn[M*2], lst[N];
int tot, head[2*K], nxt[4*K], twd[4*K];
ll val[4*K];

void add(int u, int v, ll ww){
	nxt[++tot] = head[u];
	head[u] = tot;
	twd[tot] = v;
	val[tot] = ww;
	return;
}

priority_queue<pair<ll, int> > p;
void dijkstra(int ss, int tt){
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[ss] = 0;
	p.push(make_pair(0, ss));
	while(!p.empty()){
		int u = p.top().second; p.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = nxt[i]){
			int v = twd[i], ww = val[i];
			if(vis[v]) continue;
			if(d[v] > d[u]+ww){
				d[v] = d[u]+ww;
				p.push(make_pair(-d[v], v));
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> dd >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[j] >> t[j];
			f[a[j]].push_back(make_pair(i, t[j]));
		}
	}
//	cout << "aaa\n";
	totf = m;
	memset(lst, -1, sizeof(lst));
	for(int i = 1; i <= m; i++){
		int qqq = f[i].size();
		for(int j = 0; j < qqq; j++){
			totf++;
			ll iii = f[i][j].first, jjj = f[i][j].second;
			add(i, totf, jjj);
			add(totf, i, jjj);
			if(lst[iii] != -1){
				add(lst[iii], totf, 0);
				add(totf, lst[iii], 0);
			}
			lst[iii] = totf;
		}
	}
//	cout << "bbb\n";
	int x, y;
	ans = 0;
	while(q--){
		cin >> x >> y;
		dijkstra(x, y);
		cout << d[y]+w[x]+w[y] << "\n";
	}
	return 0;
}
