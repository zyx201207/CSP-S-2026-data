#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 1);

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 1; i <= n; i++)

		cout << a[n];
	return 0;
}