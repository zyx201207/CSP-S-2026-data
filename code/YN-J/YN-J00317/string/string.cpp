#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5 + 5;

int n;
ll a[N];
char c[N];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		
		cin >> a[i] >> c[i];
	}
	
	int l = 1, r = n;
	ll lc = a[l], rc = a[r];
	ll ans = 0;
	
	while (l != r) {
		if (c[l] == c[r]) {
			if (lc == rc) {
				l++;
				r--;
				lc = a[l];
				rc = a[r];
			} else if (lc > rc) {
				lc -= rc;
				r--;
				rc = a[r];
			} else {
				rc -= lc;
				l++;
				lc = a[l];
			}
		} else {
			if (lc == rc) {
				l++;
				r--;
				ans += lc;
				lc = a[l];
				rc = a[r];
			} else if (lc > rc) {
				ans += rc;
				lc -= rc;
				r--;
				rc = a[r];
			} else {
				ans += lc;
				rc -= lc;
				l++;
				lc = a[l];
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

