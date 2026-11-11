#include <bits/stdc++.h>
using namespace std;

int Tests = 1;

constexpr int N = 5e2 + 10;
constexpr int M = 5e5 + 10;
constexpr int Q = 1e5 + 10;

int case_, m, n, d, q;
int w[M];
int k[N], a[N][M], t[N][M];
int x[Q], y[Q];



void solve(istream &in, ostream &out);

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

//	cin >> Tests;
	while (Tests--) {
		solve(cin, cout);
	}
	return 0;
}

void solve(istream &in, ostream &out) {
	in >> case_ >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		in >> w[i];
	}
	for (int i = 1; i <= N; i++) {
		in >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			in >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		in >> x[i] >> y[i];
		out << w[x[i]] + t[x[i]][x[i]] + t[x[i]][y[i]] + w[y[i]] << '\n';
	}
}
