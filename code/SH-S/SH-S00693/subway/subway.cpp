#include <bits/stdc++.h>
using namespace std;
int c, n, m, dis, q;
int k[505];
//vector<int> cnt[500005];
//vector<int> e[500005];
//int d[55][55];
//int ccnt[500005];
//void getfa(int u){
//	
//}
//int dijkstra(int s){
//	
//}
vector<int> cnt[500005];
vector<int> e[500005];
int main(){
	int w[500005], a[503][500002], t[502][500002];
//	vector<int> cnt[500005];
//	vector<int> e[500005];
	int d[505][505];
	int ccnt[500005];
	cin >> c >> n >> m >> dis >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			cnt[a[i][j]].push_back(i);
			if(ccnt[a[i][j]])	continue;
			ccnt[a[i][j]] = i;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			d[i][j] = 500005;
		}
	}
	for (int i = 1; i <= n; i++){
		d[i][i] = 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k[i]; j++){
			for (int p : cnt[a[i][j]]){
				if(p != i)	d[i][p] = min(d[i][p], t[i][a[i][j]] + t[p][a[i][j]]);
			}
			
		}
	}
	for (int kk = 1; kk <= n; kk++){
		for (int i = 1; i <= n; i++){
			if(d[i][kk] > 500005 / 2){
				continue;
			}
			for (int j = 1; j <= n; j++){
				if(d[kk][j] > 500005 / 2){
					continue;
				}
				d[i][j] = min(d[i][j], d[i][kk] + d[kk][j]); 
			}
		}
	}
	cout << d[1][2];
	while(q--){
		int x, y;
		cin >> x >> y;
		int l = ccnt[x], r = ccnt[y];
		cout << w[x] + t[l][x] + w[y] + t[r][y] + d[l][r];
	}
}
