#include <bits/stdc++.h>
using namespace std;
int a[1000000];

int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int s = 0;
	int min = -99999;
	int max = 99999;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (max > min)
			max = m;
		m += 1;
		if (a[i]   == m - 1 ) {
			s++;
		}
	}
	cout << s;
	return 0;
}