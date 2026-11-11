#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, j = 0, size = 1, ans = 1;
	cin >> n >> m;

	vector<int> e(n);
	vector<int> prefix(n+3);
	

	for (int i = 0; i < n; i++) {
		cin >> e[i];
	}

	sort(e.begin(), e.end());
	prefix[1] = e[0];
	int cost = 0;

	for (long i = 2; i < n; i++) {
		prefix[i] = prefix[i - 1] + e[i];
	}

	int i = 0;
	while (j < n) {
		j++;
		cost += size * (e[j] - e[j - 1]);
		while (cost > m) {
			cost -= prefix[j + 1] - prefix[i];
			i++;
		}
		size = j - i + 1;
		ans = max(ans, size);
	}

	cout << ans;

	return 0;
}