#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int arr[N] = {0};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << n << ' ';
	for (int i = 0; i < m - 1; i++) {
		cout << arr[i + 2] << ' ';
	}

	return 0;
}