#include <bits/stdc++.h>
using namespace std;
struct e{
	int v, cost;
};
priority_queue<e, vector<e>, greater<e>> q; 
int c, n, m, d, q, vis[510];
vector <e> k[510];
vector <e> a[500010];
vector <e> arr[500010];
int tai[510];
void dfs(int x, bool d){
	if (d){
		int siz = a[x].size();
		for (int i = 0; i < siz; i ++){
			int m = a[x][i].v;
			
		}
	}
	
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++){
		cin >> tai[i];
	}
	for (int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++){
			int x, y;
			cin >> x >> y;
			k[i].push_back({x, y});
			a[x].push_back({i, y});
		}
	}
	dfs(1, 0);
	
	return 0;
}
