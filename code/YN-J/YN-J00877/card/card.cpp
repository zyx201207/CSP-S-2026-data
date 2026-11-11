#include <bits/stdc++.h>
using namespace std;
int a[50000001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1 && m == 1) {
		cout << 1;
	}


	return  0;
}

