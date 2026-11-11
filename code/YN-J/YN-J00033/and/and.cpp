#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200001];
int main() {
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	cin >> n >> m;
	const int N = n + 1;
	long long x[N];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (m == 1) {
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		long long maxx = 0;
		for (int i = 1; i < n; i++) {
			long long x = a[i];
			for (int j = i + 1; j <= n; j++) {
				x &= a[j];
				maxx = max(maxx, x);
			}
		}
		cout << maxx;
		return 0;
	}
	//ÌØÊâÐÔÖÊ£Â

	cout << a[n];

	return 0;
}