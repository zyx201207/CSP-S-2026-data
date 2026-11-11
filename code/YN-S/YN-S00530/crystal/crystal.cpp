#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
	freopen("crystal.out", "w", stdout);
	freopen("crystal.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int c = abs(a[1] - a[2]);
	cout << m / c / 2;
}