#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 100;
int a[N];
stack <int> b;
int c[N];
int d[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		//cout << "i";
		int num = 1;
		for (int j = i; j <= n; j++) {
			//cout << '1';
			if (c[a[j]] == 0) {
				c[a[j]] = num;
				b.push(a[j]);
				num++;
			} else {
				num = c[a[j]] + 1;
				while (b.top() != a[j]) {
					//cout << 'k';
					int t = b.top();
					c[t] = 0;
					b.pop();
				}
			}
		}
		for (int j = 1; j <= m; j++) {
			//cout << '2';
			if (c[j] != 0) {
				d[j]++;
				c[j] = 0;
			}
		}
		while (b.empty() == 0) {
			//cout << '3';
			b.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << d[i] << " ";
	}
	return 0;
}