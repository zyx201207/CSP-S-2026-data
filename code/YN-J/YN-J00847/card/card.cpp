#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	int sum = 0;
	int b[100010];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (b[i] == b[j])
				cout << i;
		}
	}
	return 0;
}