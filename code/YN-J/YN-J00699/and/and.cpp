#include <bits/stdc++.h>
using namespace std;
int a[10000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int j = 0;
		while (a[j] < a[j + 1]) {
			swap(a[j], a[j + 1]);
			j++;
		}

	}

	for (int i = 0; i < n ; i++) {
		if (i == m) {
			cout << a[i];
		}
	}
	return 0;
}