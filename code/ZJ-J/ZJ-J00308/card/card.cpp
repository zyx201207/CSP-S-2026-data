#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], dis[N];
int cnt;

bool check(int x, int y) {
	for (int i = x; i < y; i++) {
		if (a[i] == a[y]) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int sum = i;
		for (int j = i; j <= n; j++) {
			if (check(sum, j)) {
				sum = j;
			}
		}
		for (int j = sum; j <= n; j++) {
			dis[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << dis[i] << " ";
	}
	return 0;
}