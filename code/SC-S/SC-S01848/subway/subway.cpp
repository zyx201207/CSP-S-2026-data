#include <bits/stdc++.h>
using namespace std;
#define int long long
int c , n , m , d , q; 
int mk;
int mt;
int w[500005];
int a[505][50005] , t[505][50005];
void search (int st , int ed) {
	int way = 1;//多少种方法 
	int h[500005]; //几号线 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= mk; j++) {
			if (st == a[i][j]) {
				mt += t[i][j];
				h[way] = i;
				way++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= mk; j++) {
			if (ed == a[i][j]) {
				for (int o = 1; o <= way; o++) {
					if (h[o] == i) {
						mt += t[i][j] * 2;
						mt += w[ed];
						cout << mt << endl;
						return ;
					}
				}
				search (a[i][j] , ed);
			}
		}
	}
}
void solve (int x , int y) {
	mt += w[x];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= mk; j++) {
			if (a[i][j] == x) {
				mt += t[i][j];
			}
		}
	}
	search (x , y);
} 
signed main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	freopen ("subway.in" , "r" , stdin);
	freopen ("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;cin >> k;
		mk = max (mk , k);
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x , y;
		cin >> x >> y;
		mt += w[x];
		mt += w[y];
		cout << mt;
	}
}