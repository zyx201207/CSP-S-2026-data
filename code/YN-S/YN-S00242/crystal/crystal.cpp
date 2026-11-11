#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 10;
ll n, m, a[MAXN], cf[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {

		cf[i] = a[i] - a[i - 1];
	}

	int mid = a[(1 + n) / 2], pos = (1 + n) / 2;

	for (pos = pos + 1; a[pos] == mid; pos++);

	cout << --pos;
	return 0;
}