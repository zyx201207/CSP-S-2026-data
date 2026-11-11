#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5+5;
int c, n, m, d, q;
struct point {
	int num;
	int tim;
};
int k[MAX], w[MAX];
point p[505][2] = {(0,0)};
int x, y, ans = 0;


void readd() {
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			cin >> p[i][j].num >> p[i][j].tim;
		}
	}
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(k, 0, sizeof(k));
	memset(w, 0, sizeof(w));
	readd();
	
	for (int i = 0; i < q; i++) {
	cin >> x >> y;
	ans += w[x] + w[y];
	int xx = x, yy = y;
	while(1) {
		ans += p[i][xx].tim + p[i][yy].tim;
		xx = yy;
		break;
	}
	}
	return 0;
}
