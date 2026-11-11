#include <bits/stdc++.h>
using namespace std;
int huanxian[501][501];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n , m , d ,q;
	cin >>c >> n >> m >> d >> q;
	map<int, int> w;
	map<int, int>xiandedian[501];
	vector<int> diandexian[20001];
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			huanxian[i][j] = 1000000000;
		}
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			xiandedian[i][a] = t;
			diandexian[a].push_back(i);
			
		}
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < diandexian[i].size(); j++) {
			for (int k = j + 1; k < diandexian[i].size(); k++) {
				huanxian[diandexian[i][j]][diandexian[i][k]] = min(huanxian[diandexian[i][j]][diandexian[i][k]] , xiandedian[diandexian[i][j]][i] + xiandedian[diandexian[i][k]][i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				huanxian[i][j] = min(huanxian[i][j],huanxian[k][j] + huanxian[i][k]);
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		if (y < x) {
			int temp = y;
			y = x;
			x = temp;
		}
		int ans = 100000000;
		for (int j = 0; j < diandexian[x].size(); j++) {
			for (int k = 0; k < diandexian[y].size(); k++) {
				if(diandexian[x][j] == diandexian[y][k]) {
					ans = min(ans, w[x] + w[y] + xiandedian[diandexian[x][j]][x] + xiandedian[diandexian[y][k]][y]);
				} else {
					ans = min(ans, w[x] + w[y] + xiandedian[diandexian[x][j]][x] + xiandedian[diandexian[y][k]][y] + huanxian[diandexian[x][j]][diandexian[y][k]]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}