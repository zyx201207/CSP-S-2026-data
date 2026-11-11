#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int,int>
const int N = 500, M = 500005;
int c, n, m, d, Q, w[M], k[N], a, t, s[M], x, y;
LL ans;
vector<PII> r[M], g[M];
bool st[M], vis[N];
void dfs(int u, int z, LL sum, int nw){
	vis[nw] = 1;
	if(ans != -1 && sum > ans) return;
	for(PII o:r[nw]){
		if(o.first == u){
			sum += o.second;
			break;
		}
	}
	for(PII o:r[nw]){
		int v = o.first;
		if(v == z){
			if(ans == -1){
				ans = sum + o.second;
			}else{
				ans = min(ans, sum + o.second);
			}
			return;
		}
		if(st[v]){
			for(PII O:g[v]){
				int V=O.second;
				if(!vis[V]){
					dfs(v, z, sum + o.second, V);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a >> t;
			r[i].push_back({a, t});
			g[a].push_back({t, i});
			s[a]++;
			if(s[a] > 1) st[a] = 1;
		}
	}
	for(int i = 1; i <= Q; i++){
		cin >> x >> y;
		ans = -1;
		for(PII o:g[x]){
			for(int i = 1; i <= n; i++) vis[i] = 0;
			dfs(x, y, 0, o.second);
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}