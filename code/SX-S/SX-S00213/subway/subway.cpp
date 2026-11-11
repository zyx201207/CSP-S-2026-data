#include <bits/stdc++.h>
using namespace std;
int c, n, m, dd, q;
int head[500010], cnt = 0;

struct edge {
	int v, w, next;
	int ln = -1, le;
} a[500010];
int fro[510];

//int minn[510][510];
void add(int uu, int vv, int ww, int ne) {
	a[++cnt] = {vv, ww, head[uu], ne, uu};
	head[uu] = cnt;
}
int time_jc[500010];
int qwe[500010];

int d[510][510];

int fi(int sta, int x, int y) {
	edge xe, ye;
	bool xeb = 1, yeb = 1;
	for (int i = head[sta]; i != 0; i = a[i].next) {
//		cout <<	"(())" << a[i].v << endl;
		if (a[i].v == x && xeb) {
			xe = a[i];
			xeb = 0;
		}
		if (a[i].v == y && yeb) {
			ye = a[i];
			yeb = 0;
		}
		if (xeb == 0 && yeb == 0) {
			break;
		}
	}
	if (xeb == 1 || yeb == 1) {
		return 1e7;
	} else {
		return xe.w + ye.w;
	}

}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> dd >> q;
	for (int i = 1; i <= m; i++) {
		cin >> time_jc[i];
	}
	for (int i = 1; i <= n; i++) {
		int k, t;
		cin >> k;
//		cout << "((" << k << endl;
		qwe[0] = 0;
		cin >> qwe[1];
		cin >> t;
		fro[i] = cnt + 1;
		for (int j = 2; j <= k ; j++) {
//			cout << "**" << t << endl;
			cin >> qwe[j];
			add(qwe[j - 1], i, t, cnt + 2);
//			cout << endl << a[cnt].v << " " << a[cnt].w << " " << a[cnt].next << " " << a[cnt].ln << " " << a[cnt].le << " " <<
//			     endl;
			cin >> t;
		}
		add(qwe[k], i, t, 0);
//		cout << endl << a[cnt].v << " " << a[cnt].w << " " << a[cnt].next << " " << a[cnt].ln << " " << a[cnt].le << " " <<
//		     endl;
	}
	memset(d, 0x3f, sizeof(d));
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
//		cout << "((((((" << k << endl;
		for (int stat = fro[k]; stat != 0 && stat != -1; stat = a[stat].ln) {

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i != j) {
						int g = d[i][k] + fi(a[stat].le, k, j);
//						cout << a[stat].le << " " << k << " " << j << endl;
//						cout << g << endl;
						if (d[i][j] > g) {
							d[i][j] = g;
						}

					}
				}
			}
		}
	}
	for (int k = n; k >= 1; k--) {
//		cout << "((((((" << k << endl;
		for (int stat = fro[k]; stat != 0 && stat != -1; stat = a[stat].ln) {

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i != j ) {
						int g = d[i][k] + fi(a[stat].le, k, j);
//						cout << a[stat].le << " " << k << " " << j << endl;
//						cout << g << endl;
						if (d[i][j] > g) {
							d[i][j] = g;
						}

					}
				}
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << d[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << d[1][3];
	while (q--) {
		int x, y, minn = 1e9;
		cin >> x >> y;
		for (int lix = head[x]; lix != 0; lix = a[lix].next) {
			for (int liy = head[y]; liy != 0; liy = a[liy].next) {
				minn = min(minn, time_jc[x] + time_jc[y] + a[lix].w + a[liy].w + d[a[lix].v][a[liy].v]);
			}
		}
		cout << minn << endl;
	}

	return 0;
}
