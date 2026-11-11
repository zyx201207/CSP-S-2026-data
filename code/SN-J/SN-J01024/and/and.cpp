#include <bits/stdc++.h>
using namespace std;

int a[200000];

bool cmp(int x, int y) {
	if(x > y) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int n, m;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n, cmp);
	int sum = a[0];
	for(int i = 1; i < m; i++) {
		sum = sum & a[i];
	}
	cout << sum;
	return 0;
}
