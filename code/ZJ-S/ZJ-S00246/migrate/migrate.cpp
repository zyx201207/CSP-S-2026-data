#include <iostream>
#define NAME "migrate"

using namespace std;
typedef long long ll;

int c;

namespace mian {

int n;
ll d;
ll xs[200008];
ll dist[304][304], cnts[304][304];

void main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> xs[i];
	}
	if (c == 11 || c == 12) {
		if (d == 1 || n == 1) {
			cout << "0\n";
			return;
		}
		ll delta = xs[1] - xs[0];
		if (d < delta * 2) {
			cout << "0\n";
			return;
		}
		ll rc = d / delta;
		cout << max(0ll, n + 1 - rc * 2) << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(xs[i] - xs[j]) <= d) {
				dist[i][j] = 1;
				cnts[i][j] = 1;
			} else {
				dist[i][j] = 0x3fefffffffffff3f;
				cnts[i][j] = 0;
			}
		}
		cnts[i][i] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ll nd = dist[i][k] + dist[k][j];
				if (nd == dist[i][j]) {
					cnts[i][j] += cnts[i][k] * cnts[k][j];
				} else if (nd < dist[i][j]) {
					cnts[i][j] = cnts[i][k] * cnts[k][j];
					dist[i][j] = nd;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (cnts[i][j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
}

}

int main() {
	freopen(NAME ".in", "r", stdin);
	freopen(NAME ".out", "w", stdout);

	int t; cin >> c >> t;
	while (t--) mian::main();

	fclose(stdin);
	fclose(stdout);

	return 0;
}
