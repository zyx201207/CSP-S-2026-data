#include <bits/stdc++.h>
using namespace std;

vector<long long> a(500010, 0);
vector<long long> pre(500010, 0);

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long m;
	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	sort(a.begin() + 1, a.begin() + 1 + n);
	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + a[i];
	}

	for (int i = n; i >= 1; i --) {
		long long pos = (long long)i * a[i] ;
		if (m >= pos - pre[i - 1]) {
			cout << i << '\n';
			return 0;
		}
	}

	return 0;
}
