#include <bits/stdc++.h>
using namespace std;
bool Mst;
double Tst = clock();

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n, m, a[N], ans[M], cnt[M], b[N];
map<int, int>mp;

bool Med;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	int sum = 0;

	for (int i = n ; i >= 1; i--) {

		cnt[a[i]]++;
		sum++;
		b[sum] = a[i];

		if (cnt[a[i]] % 2 == 0) {
			int f = 0;

			for (int i = 1; i <= sum; i++) {

				if (b[i] == a[i]) {
					f == 1;
				}

				if (f == 1) {
					b[i] = -1;
				}

				if (f == 0 && b[i] != a[i])
					ans[b[i]]++;

			}
		}

		else {
			for (int i = 1; i <= sum; i++) {

				ans[b[i]]++;
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}
