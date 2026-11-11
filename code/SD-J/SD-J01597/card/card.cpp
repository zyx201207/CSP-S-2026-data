#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100, M = 3e5 + 100;
int n, m;
int a[N], l[M], t[N], ret[M];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		l[a[i]] = i;
		t[i] = 1;
	}
	for (int i = 1; i <= n; ++ i) {
		ret[a[i]] += t[i];
		t[l[a[i]] + 1] += t[i];
	}
	for (int i = 1; i <= m; ++ i) {
		cout << ret[i] << ' ';
	}
	cout << '\n';
	return 0;
}
