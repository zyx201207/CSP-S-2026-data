#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;

struct node {
	int len;
	char zf;
	long long sum;
};

struct sop {
	long long len;
	char zf;
};
node a[N];
node ls[N], rs[N];
sop L, R;
int n;
long long maxx;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].len >> a[i].zf;
		a[i].sum = a[i].len + a[i - 1].sum;
	}
	long long len = a[n].sum / 2;
	long long l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid].sum > len) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	for (int i = 1; i <= l - 1; i++) {
		ls[i].len = a[i].len;
		ls[i].zf = a[i].zf;
	}
	ls[l].len = len - a[l - 1].sum;
	ls[l].zf = a[l].zf;
	int i_i = 1;
	for (int i = n; i >= l + 1; i--) {
		rs[i_i].len = a[i].len;
		rs[i_i].zf = a[i].zf;
		i_i++;
	}
	if (a[n].sum % 2 == 0) {
		rs[n - l + 1].len = a[l].len - ls[l].len;
	} else {
		rs[n - l + 1].len = a[l].len - ls[l].len - 1;
	}
	rs[n - l + 1].zf = a[l].zf;
	int l_i = 0, r_i = 0;
	if (ls[l_i + 1].len >= rs[r_i + 1].len) {
		l_i++;
		L.len = ls[l_i].len, L.zf = ls[l_i].zf;
	} else {
		r_i++;
		R.len = rs[r_i].len, R.zf = rs[r_i].zf;
	}
	while (l_i != l && r_i != n - l + 1) {
		if (L.len == 0) {
			l_i++;
			L.len = ls[l_i].len, L.zf = ls[l_i].zf;
		} else {
			r_i++;
			R.len = rs[r_i].len, R.zf = rs[r_i].zf;
		}
		if (L.len >= R.len) {
			if (L.zf != R.zf) {
				maxx += R.len;
				L.len -= R.len;
				R.len = 0;
			} else {
				L.len -= R.len;
				R.len = 0;
			}
		} else {
			if (L.zf != R.zf) {
				maxx += L.len;
				R.len -= L.len;
				L.len = 0;
			} else {
				R.len -= L.len;
				L.len = 0;
			}
		}
	}
	cout << maxx;
	return 0;
}