#include <iostream>
using namespace std;
int n, m;
int a[500005], b[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int t = 1; t <= m; t++) {

		for (int i = 1; i <= n; i++) {

			b[a[i]]++;

			if (b[a[i]] == 2) {
				int x = i;
				b[a[i]]--;

				while (a[x - 1] != a[i]) {
					a[x - 1] == 0;
					x--;
				}
			}
		}

		for (int i = 1; i <= n; i++) {

			if (a[i] == t)
				cout << t << " ";
		}
	}

	return 0;
}
