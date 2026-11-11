#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 5e5 + 10, inf = 0x3f3f3f3f3f3f3f3fLL;
ll a[maxn], b[maxn];
int c[maxn], lsh[maxn];
int n, ans = 0;
ll m;

bool check(int cnt) {
	ll head = 1, tail = cnt, len = cnt, nw = 0, w = inf;
	for (int i = 1; i <= cnt; i ++ ) {
		nw += (a[cnt] - a[i]);
	}
	w = min(w, nw); 
	ll maxw = a[cnt];
	for (int r = cnt + 1; r <= n; r ++ ) {
		int l = r - len + 1;
		nw -= maxw - a[l - 1];
		nw += (a[r] - maxw) * (len - 1);
		maxw = a[r];
		w = min(nw, w);
	}
	if (w <= m) return true;
	else return false;
} 

void lshua() {
	sort(b + 1, b + 1 + n);
	int cnt_ = unique(b + 1, b + 1 + n) - (b + 1);
	for (int i = 1; i <= n; i ++ ) {
		lsh[i] = lower_bound(b + 1, b + 1 + cnt_, a[i]) - b;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		b[i] = a[i];
	}
	lshua();
	for (int i = 1; i <= n; i ++ ) {
		c[lsh[i]] ++;
	}
	int tmp = 0;
	for (int i = 1; i <= n; i ++ ) {
		tmp = max(tmp, c[i]);
	}
	sort(a + 1, a + 1 + n);
	int l = tmp, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	} 
	cout << ans << "\n";
	return 0;
}