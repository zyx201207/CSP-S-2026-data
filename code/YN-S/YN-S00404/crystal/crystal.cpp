#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> sj(n + 1, 0);
	vector<int> cz(n + 1, 0);
	vector<int> qc(n + 1, 0);

	for (int i = 1; i <= n; i++) {

		cin >> sj[i];
		cz[i] = sj[i] - sj[i - 1];
	}

	sort(cz.begin(), cz.end());

	for (int i = 2; i <= n; i++) {

		qc[i] = qc[i - 1] + cz[i];
	}

	int cnt = 1;

	for (int i = 2; i <= n; i++) {

		if (m - qc[i] <= 0) {
			cout << cnt << "\n";
			break;
		}

		cnt++;
	}

	return 0;
}