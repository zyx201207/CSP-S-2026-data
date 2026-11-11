#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll m, n, a[200005], b[200005], lb = 0, h = 0, maxn = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (m == 1 ) {
		cout << maxn;
		return 0;
	}
	if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((a[i]&a[j]) > h)
					h = (a[i] & a[j]);
			}
		}
	} else if (m == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int a1 = j + 1; a1 < n; a1++)
					if ((a[i]&a[j]&a[a1]) > h)
						h = (a[i] & a[j] & a[a1]);
			}
		}
	} else if (m == 4) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int a1 = j + 1; a1 < n; a1++)
					for (int b = a1 + 1; b < n; b++)
						if ((a[i]&a[j]&a[a1]&a[b]) > h)
							h = (a[i] & a[j] & a[a1] & a[b]);
			}
		}
	} else if (m == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int a1 = j + 1; a1 < n; a1++)
					for (int b = a1 + 1; b < n; b++)
						for (int c = b + 1; c < n; c++)
							if ((a[i]&a[j]&a[a1]&a[b]&a[c]) > h)
								h = (a[i] & a[j] & a[a1] & a[b] & a[c]);
			}
		}
	} else if (m == 6) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int a1 = j + 1; a1 < n; a1++)
					for (int b = a1 + 1; b < n; b++)
						for (int c = b + 1; c < n; c++)
							for (int d = c + 1; d < n; d++)
								if ((a[i]&a[j]&a[a1]&a[b]&a[c]&a[d]) > h)
									h = (a[i] & a[j] & a[a1] & a[b] & a[c] & a[d]);
			}
		}
	} else if (m == 7) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int a1 = j + 1; a1 < n; a1++)
					for (int b = a1 + 1; b < n; b++)
						for (int c = b + 1; c < n; c++)
							for (int d = c + 1; d < n; d++)
								for (int e = d + 1; e < n; e++)
									if ((a[i]&a[j]&a[a1]&a[b]&a[c]&a[d]&a[e]) > h)
										h = (a[i] & a[j] & a[a1] & a[b] & a[c] & a[d] & a[e]);
			}
		}
	} else if (m == 8) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int a1 = j + 1; a1 < n; a1++)
					for (int b = a1 + 1; b < n; b++)
						for (int c = b + 1; c < n; c++)
							for (int d = c + 1; d < n; d++)
								for (int e = d + 1; e < n; e++)
									for (int f = e + 1; f < n; f++)
										if ((a[i]&a[j]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]) > h)
											h = (a[i] & a[j] & a[a1] & a[b] & a[c] & a[d] & a[e] & a[f]);
			}
		}
	} else {
		cout << maxn;
		return ;
	}
	cout << h;
	return 0;
}