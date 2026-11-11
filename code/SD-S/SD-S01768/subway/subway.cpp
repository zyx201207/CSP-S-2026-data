#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

bool ok[N];
long long c, n, m, d, p; 
long long w[N], cnt[N], di[N];
int h[N];
struct G{
	long long x, y;
}q[N][30];
map<pair<long long, long long>, long long> a, t;
vector<pair<long long, long long>> g[N];
void dij(int s){
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	memset(ok, 0, sizeof ok);
	memset(di, 0x3f3f, sizeof di);
	di[s] = w[1];
	pq.push({0, s});
	while(!pq.empty()){
		auto b = pq.top();
		long long u = b.second;
		for(int i = 0; i < g[u].size(); i++){
			long long v = g[u][i].first, w = g[u][i].second;
			if(ok[v]) continue;
			if(u == s){
				h[v] = 	w;
				di[v] = di[s] + di[t[{h[v], s}]];
				pq.push({di[h[v], s], v});
				h[v] = w;
			}
			else if(h[u] == w){
				di[v] = di[u] + di[t[{w, v}]];
				pq.push({di[v], v});
				h[v] = w;
			}
			else{
				if(di[u] + t[{w, v}] + t[{h[u], v}] < di[v]){
					di[v] = di[u] + t[{w, v}] + t[{h[u], v}];
					pq.push({di[v], v});
					h[v] = w;
				}
			}
			ok[v] = 1;
		}
	}
}

int main(){
	freopen("subway.in", "r" , stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		long long k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[{i, j}];
			cin >> t[{i, a[{i, j}]}];
			if(j != 1){
				g[a[{i, j}]].push_back({{a[{i, j - 1}]}, i});
				g[a[{i, j - 1}]].push_back({{a[{i, j}]}, i});
			}
		}
	}
	for(int i = 1; i <= p; i++){
		int s, e;
		cin >> s >> e;
		dij(s);
		cout << di[e] + w[e] << '\n';
	}
	return 0;
}

