#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000];

int main() {
	freopen("card.in", "r", sidin);
	freopen("card.out", "w", sidout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> a[j];
			if (a[i] == a[i] - a[j]) {
				a[0] = a[i];
			} else {
				cout << a[i];
			}
		}
	}
	cout << n;

	return 0;
}