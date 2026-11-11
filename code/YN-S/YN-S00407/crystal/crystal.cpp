#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
ll n, m, cnt = 0, h;
ll a[N], d[N];


int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1 ; i <= n ; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1 ; i <= n ; i++) {

		d[i] = a[i] - a[i - 1];
	}

	sort(d + 1, d + n + 1);


	for (int i = 1 ; i <= n ; i++) {

		if (m > 0) {
			m -= i * d[i];
			cnt++;
			h = a[i] + d[i];
		}

	}

	for (int i = 1 ; i <= n ; i++) {

		if (h == a[i])
			cnt++;
	}

	cout << cnt;

	return 0;
}