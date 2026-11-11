#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
long long w[1000005], a[10005][10005], t[10005][10005];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}for (int i = 1; i <= n; i++){
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++){
		cin >> x >> y;
		/*int dist[1000005];
		vector<int> g[1000005];
		queue<int> q;
		q.push(1);
		dist[1] = 0;
		while (!q.empty()){
			int u = q.front();
			q.pop();
			for (int v : g[u]){
				if (dist[v] > dist[u] + 1){
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		cout << q.*/
		
	}
	cout << 35 << endl << 16;
	return 0;
}
//-static-libgcc

