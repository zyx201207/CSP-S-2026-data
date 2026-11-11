#include <bits/stdc++.h>
using namespace std;
const int NM = 5e5 + 5, MN = 3e5 + 5;

int n, m, a[NM], ans[MN];
int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			w = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + (ch - '0');
		ch = getchar();
	}
	return s * w;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	for (int i = 0; i < n; i++) {
		a[i] = read();
	}
	ans[a[n - 1]]++;

	for (int i = 0; i < n - 1; i++) {
		vector<int> q;
		for (int j = i; j < n; j++) { //n-i
			q.push_back(a[j]);
			bool f = 0;
			for (auto it = q.end() - 2; it >= q.begin(); it--) {
				if (*it == a[j]) {
					for (auto itt = it; itt < q.end() - 1; itt++) {
						*itt = 0;
						f = 1;
					}
				}
				if (f)
					break;
			}
		}

		for (int j = 0; j < q.size(); j++ ) {
			if (q[j] != 0)
				ans[q[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}