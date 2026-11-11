#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<ll>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), cmp);
	ll sum = vec[0];
	for (int i = 1; i < m; i++) {
		sum = (sum & vec[i]);
	}
	cout << sum;
	return 0;
}