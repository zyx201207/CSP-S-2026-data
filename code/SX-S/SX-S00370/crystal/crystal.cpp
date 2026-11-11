#include <bits/stdc++.h>
using namespace std;
long long n, m, e, minn = INT_MAX, w, ans, q, p, k = 1, a[5000005], s[5000005], cnt;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

	}
	for (int i = 1; i < n; i++) {
		s[i] = a[i + 1] - a[i];
	}
	for (int i = 1; i < n; i++) {
		if (s[i] < minn) {
			p = i;
			e = p;
			minn = s[i];
		}
	}
	m -= minn;
	ans+=2;
	if (s[p - 1] > s[p + 1]) {
		w = 1;
	} else if(s[p+1]>=s[p-1]){
		w = -1;
	}
	if(p+1>n) w=-1;
	else if(p-1<=0) w=1;
	for (int i = 1; i <= n; i++) {
		if (s[p + w] > n || s[p + w] <= 0) {
			if (w == 1)
				w = -1;
			else
				w = 1;
			p = e + w;
		}
		p += w;
		q = s[p] + s[p - w];
		if (m - q < 0)
			break;
		m -= q;
		ans += i;
	}
	cout << ans;
	return 0;
}