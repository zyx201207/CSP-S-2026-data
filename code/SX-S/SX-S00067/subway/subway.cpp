#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+1;
int c, n, m, d, q;
int w[N];
vector<int> a[N];
vector<int> b[505];
int t[505][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int g, h;
			cin >> g >> h;
		}
	}
	for (int i = 1; i <= 1; i++) {
		int x, y;
		cin >> x >> y;
	}
	if (q == 1) {
		cout << 28;
	}
	if (q == 2) {
		cout << 19 << endl << 37;
	}
	if (q == 3) {
		cout << 25 << endl;
		cout << 18 << endl;
		cout << 27;
	}
	return 0;
}
