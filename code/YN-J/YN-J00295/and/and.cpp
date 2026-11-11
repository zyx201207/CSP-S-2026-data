#include <bits/stdc++.h>
using namespace std;
int w[21];
int ec[21];
bool in[200001];
vector<int>s[20];
vector<int>s2[20];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	ec[0] = 1;

	for (int i = 1; i <= 20; i++) {

		ec[i] = ec[i - 1] * 2;
	}

	for (int i = 1; i <= n; i++) {

		in[i] = true;
		int a;
		cin >> a;
		int y = ceil(log2(a));

		while (a > 0) {
			if (a >= ec[y]) {
				a -= ec[y];
				w[y]++;
				s[y].push_back(i);
			} else {
				s2[y].push_back(i);
			}

			y--;
		}
	}

	int ans = 0;

	for (int i = 20; i >= 0; i--) {

		if (w[i] < m) {
			continue;
		}

		int cnt = 0;

		for (int j : s[i]) {
			if (in[j]) {
				cnt++;
			}
		}

		if (cnt >= m) {
			ans += ec[i];

			for (int j : s2[i]) {
				in[j] = false;
			}
		}
	}

	cout << ans;
	return 0;
}