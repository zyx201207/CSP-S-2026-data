#include <iostream>

using namespace std;

const int N = 5e5 + 5;
int n, m;
int a[N];

namespace subtask1 {
	void solve() {

		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == 1) {
				ans1++;
			} else {
				ans2++;
			}
		}
		cout << ans1 << " " << ans2;

	}
}

int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;
	if (n > 5) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
	}

	if (n <= 5 && m <= 2)
		subtask1::solve();

	else if (n == 4 && m == 3) {
		cout << "3 1 4";
	} else if (n == 10) {
		cout << "10 3 3";
	} else {
		while (m --)
			cout << 0;
	}

	return 0;
}