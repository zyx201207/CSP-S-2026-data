#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	int sum = 0;
	sort(a, a + n);
	int tmp = m;
	int maxx = 0;

	for (int j = n - 1; j >= 0; j--) {

		for (int i = 0; i < j; i++) {

			if (a[j] - a[i] < tmp) {
				sum++;
				tmp -= (a[j] - a[i]);
			}
		}

		maxx = max(maxx, sum);
	}

	cout << maxx + 1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
