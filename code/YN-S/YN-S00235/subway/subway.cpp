#include <iostream>
using namespace std;

struct sta {
	int wi;
	int a[10005];
} w[10000];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q, ans = 0;
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i].wi;
		ans += w[i].wi;
	}

	int k;

	for (int i = 1; i <= n; i++) {

		cin >> k;

		for (int j = 1; j <= k; j++) {

			cin >> w[i].a[j];
		}

	}

	int xr, yr;

	for (int i = 1; i <= q; i++) {

		cin >> xr >> yr;
	}

	for (int i = 1; i <= q; i++) {


		cout << ans << endl;
	}

	return 0;
}
