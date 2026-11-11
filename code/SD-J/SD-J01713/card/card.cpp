#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005], t[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int j = 0;
	for (int i = n; i >= 1; i--) {
		if (i < j) {
			b[i] = 1 + b[j + 1];
			continue; 
		}
		if (a[i] == a[i] + 1) {
			j = i;
			b[i] = 1 + b[i + 1];
			continue;
		}
		b[i] = 1 + b[i + 1];
	}
	for (int i = 1; i <= n; i++) 
		cout << b[i]; 
}

