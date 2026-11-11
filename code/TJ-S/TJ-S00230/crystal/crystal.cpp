#include<bits/stdc++.h>
using namespace std;
long long a[500000];
long long ab[6000][6000];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long bb = 0;
	for(int i = n; i >= 1; i--) {
		bb = abs(a[n] - a[i]);
		if(m - bb >= 0) {
			m -= bb;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
