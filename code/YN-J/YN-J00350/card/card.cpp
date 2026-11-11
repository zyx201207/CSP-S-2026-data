#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int n, m, a[MAXN];
vector <int> vec[MAXN];

int main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		for (int j = i; j <= n; j++) {

			bool flag = false;
			int pos = 0;

			for (int k = 0; k < vec[i].size(); k++) {

				if (a[j] == vec[i][k]) {
					flag = true;
					pos = k;
					break;
				}
			}

			if (vec[i].empty() || !flag) {
				vec[i].push_back(a[j]);
			} else {
				vec[i].erase(vec[i].begin() + pos + 1, vec[i].end());
			}
		}
	}

	int cnt[MAXN] = {0};

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < vec[i].size(); j++) {

			cnt[vec[i][j]]++;
		}
	}

	for (int i = 1; i <= m; i++)

		cout << cnt[i] << ' ';

	return 0;
}
