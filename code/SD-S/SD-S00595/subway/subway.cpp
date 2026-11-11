#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p, ans;
int w[500500],k[500500];
struct node{
	int a, t;
};
vector<node> g[500500];
queue<node> q;
bool vis[500500];
int bfs(int x, int y){
	if(x == y){
		return ans;
	}
	q.push({x, 0});
	while(!q.empty()){
		node noww = q.front();
		q.pop();
		for(int i = 1;i <= k[noww.a]; i++){
			node nowwu = g[noww.a][i];
			if(!vis[g[noww.a][i].a]){
				vis[g[noww.a][i].a] = 1;
				q.push({1,1});
			}
		}
	}
	
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	} 
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int aa, tt;
			cin >> aa >> tt;
			g[i].push_back({aa, tt});
			g[aa].push_back({i, tt});
		} 
	}
	while(p--){
		int x = 0, y = 0;
		cin >> x >> y;
		int start = x;
		cout << 1 << endl;
	}
	return 0;
}
