#include <iostream>

using namespace std;

#define N 200005
#define M 100005

int n, m, a[N], cnt[M];


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (j != i && a[j] != a[j - 1]) {
				++cnt[a[j]];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}

