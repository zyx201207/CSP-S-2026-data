#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a(500005);
ll tong[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tong[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << tong[a[i]] << endl;
	}
	return 0;
}
