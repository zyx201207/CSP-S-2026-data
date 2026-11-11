#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int a[N];
vector<int> b;
int cnt[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int tmp = 0;

	for (int i = 0; i < n; i ++) {

		cin >> a[i];
		tmp = max(tmp, a[i]);
	}

	for (int i = 0; i < n; i ++) {

		for (int j = i; j < n; j ++) {

			int st = 0;

			for (int k = b.size() - 1; k >= 0; k --)

				if (b[k] == a[j])
					st = k;

			if (st)
				b.erase(b.begin() + st, b.end());
			b.push_back(a[j]);
		}

		for (int j = 0; j < b.size(); j ++) {

			cnt[b[j]] ++;
		}

		b.clear();
	}

	for (int i = 0; i < tmp || i < m; i ++) {

		if (cnt[i])
			cout << cnt[i] << " ";
	}

	return 0;
}
