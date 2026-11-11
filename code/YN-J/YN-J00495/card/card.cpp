#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int a[N], cnt[M], ncnt[M], n, m;
int cnts[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	int ans = 0;
	int d = n;

	for (int i = 0; i < n; i++) {

		cout << a[i];
	}

	while (d--) {

		for (int i = ans; i < n ; i++) {



			if (ncnt[a[i]] == 0) {
				ncnt[a[i]]++;
				//cout << a[i] << endl;
				//cnts[i] = ans;
			} else {
				for (int j = 0; j < i; j++) {


					ncnt[a[j]] = 0;
				}
			}
		}

		for (int i = 0; i < m; i++) {

			cnt[i] += ncnt[i];
		}

		ans++;
	}

	for (int i = 0; i < m; i++) {

		cout << cnt[i] << " ";
	}

	return 0;
}