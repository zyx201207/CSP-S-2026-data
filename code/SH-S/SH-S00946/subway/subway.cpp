#include <bits/stdc++.h>
using namespace std;
int t, s, n, K, T;
struct node {
	int v, w;
};
int d[500510], a[500510];
bool vis[500510];
vector <node> ve[500510];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> t >> s >> n >> K >> T;
	for(int i = 1; i <= n; i ++){
		long long xx; 
		cin >> xx;
		a[i] = xx;
	}
	for(int i = 1; i <= s; i ++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++){
			int x, y;
			cin >> x >> y;
			ve[n + i].push_back({x, y});
			ve[x].push_back({n + i, y});
		}
	}
	while(T --){
		for(int i = 0; i <= s + n; i ++){
			d[i] = 1e9;
			vis[i] = 0;
		}
		int S, E;
		cin >> S >> E;
		d[S] = a[S];
		for(int i = 1; i < s + n; i ++){
			int u = 0;
			for(int j = 1; j <= s + n; j ++){
				if(!vis[j] && d[j] < d[u]){
					u = j;
				}
			}
			if(!u){
				break;
			}
			vis[u] = 1;
			for(int j = 0; j < ve[u].size(); j ++){
				d[ve[u][j].v] = min(d[ve[u][j].v], d[u] + ve[u][j].w);
			}
		}
		cout << d[E] + a[E] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
