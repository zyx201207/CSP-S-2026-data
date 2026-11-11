#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;
long long n, m;
int a[N];
int c = 0;

const int M = 1e5 + 10;
int sx = -M, sn = M;
int d[2 * M];
int ans;
int x[2 * M];
int len = 0;
int s;
void solve1() {
	
	s = m;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i] + sx;
		if (a[i] < sn) {
			sn = a[i];
		}
		d[a[i]]++;
		if (ans < d[a[i]]) {
			ans = d[a[i]];
		}
	}
	sx = sx * 2;
	for (int i = 1; i <= sx; i++) {
		if (d[i] == ans) {
			len++;
			x[len] = i;
		}
	}
	int mdx, flag = 1;
	for (int i = 2; i <= len; i++) {
		if (x[i] > (sx + sn) / 2) {
			mdx = i - 1;
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		mdx = len;
	}
	int l = x[mdx] - 1, r = x[mdx] + 1;
	mdx = x[mdx];
	bool ok = 0;
	while (l > 0 || r < sx) {
		if (d[l] != 0) {
			cout << s ;
			if (s - (mdx - l) >= 0) {
				s -= mdx - l;
				ans++;
				d[l]--;
			} else {
				ok = 1;
			}
		}
		if (d[l] == 0 && l > 0) {
			l--;
		}
		if (d[r] != 0) {
			if (s - (r - mdx) >= 0) {
				s -= r - mdx;
				ans++;
				d[r]--;
			} else {
				ok = 1;
			}
		}
		if (d[r] == 0) {
			r++;
		}
		
		if (ok) {
			break;
		}
    }
	cout << ans << "\n";
	
}

void solve2() {
	s = m;
	ans = 1;
	bool ok = 1;
	int now = c;
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= 2; i++) {
			if (s - now >= 0) {
				s -= now;
				ans++;
			} else {
				ok = 0;
			}
		}
		now += c;
		if (ok == 0) {
			cout << ans;
			break;
		}
	}
}
void solve3() {
	
}

void S() {
	
	cin >> n >> m;
	bool A = 1, B = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > sx) {
			sx = a[i];
		}
		if (i == 2) {
			c = a[2] - a[1];
		}
		if (i > 1) {
			if (a[i] != a[i - 1]) {
				A = 0;
			}
			if (a[i] - a[i - 1] != c) {
				B = 0;
			}
		}
	}
	if (n <= 5000) {
		solve1();
	} else {
		if (A) {
			cout << n << "\n";
		} else if (B) {
			solve2();
		} else {
			
		}
	}
	
	return;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	S();
	
	return 0;
}
