#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	if (m == 1) {
		int maxn = -1;
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			maxn = max(maxn, k);
		}
		cout << maxn;
	} else if (m == 2) {
		int maxn = -1;
		int arr[n + 5];
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxn = max(maxn, arr[i] & arr[j]);
			}
		}
		cout << maxn;
	} else if (m == n) {
		int a;
		cin >> a;
		for (int i = 1; i < n; i++) {
			int t;
			cin >> t;
			a = a & t;
		}
		cout << a;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}