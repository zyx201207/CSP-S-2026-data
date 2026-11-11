#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 500 + 5;
// 500 个站点，1e5 个计划。让我们 %%% Flowed 
const int M = 5e5 + 5;
int f[N][N];
int g[N];
int w[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	
	int c; cin >> c;
	int m; cin >> m;
	int n; cin >> n;
	int d; cin >> d;
	int q; cin >> q;
	memset(f, 0x3f, sizeof(f));
	
	for(int i = 1; i <= n; i++) {
		cin >> w[i]; 
	} 
	
	for(int i = 1; i <= m; i++) {
		int k; cin >> k;
		vector<int> a(k);
		vector<int> t(k);
		for(int j = 0; j < k; j++) {
			cin >> a[j] >> t[j];
		}
		for(int j = 0; j < k; j++) {
			for(int l = 0; l < k; l++) {
				if(j == l) continue;
				int u = a[j];
				int v = a[l];
//				cout<<"dlc666"<<u<<" "<<l<<" "<<v<<endl;
				f[u][v] = min(f[u][v], t[j] + t[l]);
				f[v][u] = f[u][v];
			}
		}
	}
	
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
//				cout<<i<<"到"<<j<<"通过"<<k<<f[k][j]<<" "<<f[i][k]<<endl;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				f[j][i] = f[i][j];
			}
		}
	}
	
	for(int i = 1; i <= q; i++) {
		int u; cin >> u;
		int v; cin >> v;
		cout << f[u][v] + w[u] + w[v] << endl;
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
