#include<bits/stdc++.h>
#define int long long
#define QwQ 0
#define debug cout << "!!!" << '\n';
using namespace std;
int c, n, m, d, q, ans;
int w[500010];
struct node{
	int v, val;
};
struct E{
	int id, val;
};
int vis[500010][510];
vector<E> a[500010];
vector<node> G[510];
void dfs(int x, int y, int cnt){
	if(cnt > ans)	return;
	if(x == y){
		ans = min(ans, cnt);
		return;
	}
	for(auto t : a[x]){
		for(auto v : G[t.id]){
			if(v.v == x || vis[v.v][t.id])	continue;
			vis[v.v][t.id] = 1;
			dfs(v.v, y, cnt + v.val + t.val);
			vis[v.v][t.id] = 0;
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int v, val;
			cin >> v >> val;
			G[i].push_back({v, val});
			a[v].push_back({i, val});
		}
	}
	if(c >= 7 && c <= 11){
		while(q--){
			int x, y;
			cin >> x >> y;
			ans = 0;
			for(auto t : a[x]){
				for(auto v : G[t.id]){
					if(v.v == y){
						ans = w[x] + w[y] + t.val + v.val;
						break;
					}
				}
				if(ans)	break;
			}
			cout << ans << '\n';
		}
		return QwQ;
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++)	vis[i][j] = 0;
		}
		dfs(x, y, 0);
		cout << ans + w[x] + w[y] << '\n';

	}
	return QwQ;
}