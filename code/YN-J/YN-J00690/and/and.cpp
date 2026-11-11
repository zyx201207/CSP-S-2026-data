#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000001];
int m, n;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		cout << a[2];
	}
	return 0;
}
