#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

//const int MAXN = ;

void solve() {
	int n; cin >> n;
	
	vector<long long> a(n + 1);
	vector<char> b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	
	int l = 1, r = n;
	long long ans = 0;
	while (l < r) {
		if (a[l] == a[r]) {
			if (b[l] != b[r]) {
				ans += a[l];
			}
			l++;
			r--;
		} else if (a[l] > a[r]) {
			if (b[l] != b[r]) {
				ans += a[r];
			}
			a[l] -= a[r];
			r--;
		} else {
			if (b[l] != b[r]) {
				ans += a[l];
			}
			a[r] -= a[l];
			l++;
		}
	}
	
	cout << ans << endl;
	return ;
}

int main () {
	ios::sync_with_stdio();
	cin.tie(nullptr);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int T = 1; //cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}

