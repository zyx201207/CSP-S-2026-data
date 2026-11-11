#include <bits/stdc++.h>
using namespace std;
int maxand = INT_MIN;

bool cmp(int t1, int t2) {
	return t1 < t2;
}
int a[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		int cc = 0;
		for (int j = i + 1 ; j < i + m; j++) {
			cc = a[i] & a[j];
		}
		maxand = max(cc, maxand);
	}
	cout << maxand << endl;
	return 0;
}