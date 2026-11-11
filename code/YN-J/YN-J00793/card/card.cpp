#include <bits/stdc++.h>
using namespace std;
#define int long long
int n[500005];
int m[500005];
int c[500005];

signed main() {
	freopen("card.in", "r", "stdin");
	freopen("card.out", "w", "stdout");
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> n[i];
		c[i] = n[i];
	}
	for (int i = 1; i <= a; i++) {
		for (int j = i; j <= a; j++) {
			int flag = 0;
			for (int z = i; z < j; z++) {
				if (n[j] == n[z] && n[z] != 0)
					flag = 1;
				if (flag == 1)
					n[z] = 0;
			}
		}
		for (int j = i; j <= a; j++) {
			m[n[j]]++;
		}
		for (int j = i; j <= a; j++) {
			n[j] = c[j];
		}
	}
	for (int i = 1; i <= b; i++) {
		cout << m[i] << " ";
	}
	return 0;
}