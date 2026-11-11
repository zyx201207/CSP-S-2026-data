#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1000000;
int x[N];
int sum;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, d;
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
		}
		sum = i;
		cout << sum;
	}
}