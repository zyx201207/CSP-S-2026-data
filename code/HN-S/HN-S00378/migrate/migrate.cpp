#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e6 + 50;

struct Info {
	int dis, cnt;
};

Info operator + (const Info& a, const Info& b) {
	if (a.dis < b.dis) {
		return a;
	} else if (a.dis > b.dis) {
		return b;
	} else {
		return {a.dis, min(3, a.cnt + b.cnt)};
	}
}

#define ls u << 1
#define rs u << 1 | 1

Info tag[N << 2];

void build(int u, int l, int r) {
	tag[u] = {N, 0};
	if (l == r) {
		return ;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

void update(int u, int l, int r, int L, int R, Info v) {
	if (L <= l && r <= R) {
		tag[u] = tag[u] + v;
		return ;
	}
	int mid = l + r >> 1;
	if (L <= mid) {
		update(ls, l, mid, L, R, v);
	}
	if (mid + 1 <= R) {
		update(rs, mid + 1, r, L, R, v);
	}
}

Info query(int u, int l, int r, int i) {
	if (l == r) {
		return tag[u];
	}
	int mid = l + r >> 1;
	if (i <= mid) {
		return tag[u] + query(ls, l, mid, i);
	} else {
		return tag[u] + query(rs, mid + 1, r, i);
	}
}

int c, t, n, L[N], R[N];
ll d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (c > 10 || n > 5000) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1, j = 1; i <= n; i++) {
			for (; j <= i && x[i] - x[j] > d; j++) {}
			L[i] = j;
		}
		for (int i = n, j = n; i >= 1; i--) {
			for (; j >= i && x[j] - x[i] > d; j--) {}
			R[i] = j;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			build(1, i, n);
			update(1, i, n, i, i, {0, 1});
			for (int j = i; j <= n; j++) {
				Info v = query(1, i, n, j);
				ans += v.cnt == 2;
				if (j < R[j]) {
					update(1, i, n, j + 1, R[j], {v.dis + 1, v.cnt});
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}