#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
int n;
ll m;
ll a[N], S[N];

bool check(int len) {
	for (int l = 1; l + len - 1 <= n; l++) {
		int r = l + len - 1;
		if (a[r] * len - (S[r] - S[l-1]) <= m) return true;
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a+1, a+1+n);
	S[1] = a[1];
	for (int i = 2; i <= n; i++) S[i] = S[i-1] + a[i];
	
	int l = 1, r = n, ret = 1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (check(mid)) {
			l = mid + 1;
			ret = mid;
		} else {
			r = mid - 1;
		}
	}
	
	cout << ret << '\n';

	return 0;
} 
/*
int p = 2;
	int cnt = 1;
	while (cnt * (a[p] - a[p-1]) <= m && p < n) {
		m -= (a[p] - a[p-1])*cnt;
		cnt++, p++;
	}
	int l = 1;
	while (a[p-1] - a[l] >= (cnt-1) * (a[p] - a[p-1]) && p < n){
		cnt--;
		m += a[p-1] - a[l]; 
		while (cnt * (a[p] - a[p-1]) <= m && p < n) {
			m -= cnt * (a[p] - a[p-1]);
			cnt++, p++;
		}
	}
	cout << cnt << '\n';

*/
