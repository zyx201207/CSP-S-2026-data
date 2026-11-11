#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m;
int a[N], ans, maxx = 0;

int main() {
	freopen("crystal.in", "w", stdin);
	freopen("crystal.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		ans = 1;
		int mm = m;
		for (int j = 1; j <= n; j++) {
			if (a[i] != a[j]) {
				if (a[i] > a[j] && mm - (a[i] - a[j]) >= 0)
					ans++;
			}
		}
		if (maxx < ans)
			maxx = ans;
	}
	cout << maxx;
	return 0;
}
