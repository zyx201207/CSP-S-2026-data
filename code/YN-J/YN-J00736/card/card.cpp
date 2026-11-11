#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int t[1000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		t[a[i]]++;
	}
	sort(t + 1, t + 1 + n);
	cout << m << n << t[n];
	return 0;
}

