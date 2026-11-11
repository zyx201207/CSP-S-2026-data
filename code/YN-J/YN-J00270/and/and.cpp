#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int n, m;
ll a[N];
ll ans = -1;

void pai() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] < a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	pai();
	if (m == 1) {
		cout << a[0];
		return 0;
	}
	if (m == 2) {
		ans = a[0] & a[1];
		cout << ans;
		return 0;
	}
	ans = a[0];
	for (int i = 2; i <= m; i++) {
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
