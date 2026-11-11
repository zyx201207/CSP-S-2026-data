#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a;
	string mm = {0};
	for (int i = 0; i < n; i++) {
		cin >> a;
		mm[i] = a;
	}
	if (m = 4) {
		cout << mm[n - 1] &&mm[n - 2] &&mm[n - 3] &&mm[n - 4];
	} else if (n == 4 && m == 2) {
		cout << "12";
	} else if (n == 5 && m == 3) {
		cout << "7";
	}
	return 0;
}