#include<bits/stdc++.h>
#define w first 
#define v second 
using namespace std;
const int N = 5e5 + 10;
struct Node {
	int w, v, l;
};
int c, n, m, d, q, w1[N], vis[N], change_vis[N][505];
vector <pair<int, int> >w2[505]; 
vector <int>line[N]; 
long long bfs(int x, int y) {
	long long ans = 1e18;
	memset(vis, 0, sizeof vis);
	memset(change_vis, 0, sizeof change_vis);
	queue<Node>q;
	for(auto i : line[x]){
		int w = 0;
		for(auto j : w2[i]){
			if(j.v == x){
				w = j.w;
				break;
			}
		}
		//cout << x << ' ' << w1[x] + w << ' ' << i << endl;
		q.push({w1[x] + w, x, i});
	}
	while(q.size()) {
		Node f = q.front();
		//cout << f.v << ' ' << f.w << ' ' << f.l << endl; 
		if(f.v == y) {
			ans = min(ans,(long long) f.w + w1[f.v]);
			//return ans;
		}
		vis[f.v] = 1;
		q.pop();
		int mw = 0, w = 0;
		for(auto j : line[f.v]) {
			if(j == f.l){
				change_vis[f.v][j] = 1;
				continue;
			}
			for(auto k : w2[j]) {
				if(change_vis[f.v][j])break;
				if(k.v == f.v){
					change_vis[f.v][j] = 1;
					change_vis[f.v][f.l] = 1;
					q.push({f.w + k.w, f.v, j});
					break;
				}
			}
		}
		for(auto k : w2[f.l]) {
			if(vis[k.v])continue;
			q.push({f.w + k.w, k.v, f.l});
		}
	}
	return ans;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w1[i];
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int v, t;
			cin >> v >> t;
			w2[i].push_back({t, v});
			line[v].push_back(i);
		}
	}
	while (q--) {
		int s, e;
		cin >> s >> e;	
		cout << bfs(s, e) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
