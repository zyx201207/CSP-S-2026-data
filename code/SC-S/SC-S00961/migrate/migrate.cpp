#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
using ll = long long;
typedef pair<int, ll> valtype;
const int N = 2e6 + 6;
int n;
ll a[N], m;
valtype tag[N << 2], dp[N];

valtype merg(valtype a, valtype b) {
	if(a.first < b.first) return a;
	if(a.first > b.first) return b;
	return {a.first, a.second + b.second};
}

void bd(int u, int l, int r) {
	tag[u] = {N, 0};
	if(l == r)return ;
	int mid = l + r >> 1;
	bd(u << 1, l, mid), bd(u << 1 | 1, mid + 1, r);
}

void upd(int u, int l, int r, int v) {
	if(l == r) {
		tag[u] = dp[v];
		return ;
	}
	int mid = l + r >> 1;
	if(v <= mid)upd(u << 1, l, mid, v);
	else upd(u << 1 | 1, mid + 1, r, v);
	tag[u] = merg(tag[u << 1], tag[u << 1 | 1]);
}

valtype qry(int u, int l, int r, int ql, int qr) {
//	cout << "qry" <<l << ' ' << r << ' ' << ql << ' ' << qr << '\n';
	if(ql <= l && r <= qr) {
		return tag[u];
	}
	if(l > qr || r < ql)return {N, 0};
	int mid = l + r >> 1;
	return merg(qry(u << 1, l, mid, ql, qr), qry(u << 1 | 1, mid + 1, r, ql, qr));
}

void slv() {
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	ll cnt = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = {0, 1};
		bd(1, 1, n);
		upd(1, 1, n, i);
		for (int j = i + 1; j <= n; ++j) {
			int l = lower_bound(a + 1, a + n + 1, a[j] - m) - a;
			dp[j] = qry(1, 1, n, l, j);
			++dp[j].first;
			upd(1, 1, n, j);
			if(dp[j].second == 2)++cnt;
//			cout << i << ' ' << j << ' ' << dp[j].first << ' ' << dp[j].second << ' ' << l << '\n';
		}
	}
	printf("%lld\n", cnt);
}

int main() {
#ifndef DEBUG
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
	int T;
	scanf("%d%d", &T, &T);
	while(T--)slv();
	return 0;
}