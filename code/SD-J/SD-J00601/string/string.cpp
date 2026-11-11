#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 11;
///|S| = 2e14;
int n, l=1;
char c[N];
ll a[N], ans;///20min

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	int r=n;
	while(l < r) {
		if(c[l] != c[r]) ans += min(a[l], a[r]);
		if(a[l] >= a[r]) {
			a[l] -= a[r];
			r--;
		}
		else {
			a[r] -= a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}

