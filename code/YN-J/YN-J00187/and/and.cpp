#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	cout << a[n];
	return 0;
}