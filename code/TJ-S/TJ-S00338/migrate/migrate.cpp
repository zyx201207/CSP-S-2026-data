#include <bits/stdc++.h>

#define int long long 
#define PII pair<int, int>

using namespace std;

const int N = 2e6 + 10, M = 5010, INF = 1e18;
int n, d;
int x[N], f_1[M], sz_1[M];

bool check(int l, int r) {
	return x[r] - x[l] <= d;
}

struct TREE {
	struct tr {
		int l, r;
		int minx, sz;
	}tr[M << 2]; 
	
	void push_up(int u) {
		if(tr[u * 2].minx < tr[u * 2 + 1].minx) {
			tr[u].minx = tr[u * 2].minx;
			tr[u].sz = tr[u * 2].sz;
		}
		else if(tr[u * 2].minx > tr[u * 2 + 1].minx) {
			tr[u].minx = tr[u * 2 + 1].minx;
			tr[u].sz = tr[u * 2 + 1].sz;
		}
		else if(tr[u * 2].minx == tr[u * 2 + 1].minx) {
			tr[u].minx = tr[u * 2].minx;
			tr[u].sz = tr[u * 2].sz + tr[u * 2 + 1].sz;
		}
	}
	
	void build(int u, int l, int r) {
		if(l == r) {
			tr[u] = {l, r, INF, 1};
		}
		else {
			tr[u] = {l, r, INF, r - l + 1};
			int mid = (l + r) >> 1;
			build(u * 2, l, mid);
			build(u * 2 + 1, mid + 1, r);
		}
	}
	
	PII query(int u, int l, int r) {
		if(tr[u].l >= l && tr[u].r <= r) {
			return make_pair(tr[u].minx, tr[u].sz);
		}
		else {
			int mid = (tr[u].l + tr[u].r) >> 1;
			int ans = INF, sz = 0;
			if(l <= mid) {
				PII T = query(u * 2, l, r);
				if(T.first < ans) {
					ans = T.first;
					sz = T.second;
				}
				else if(T.first == ans){
					sz += T.second;
				}
			}
			if(r > mid) {
				PII T = query(u * 2 + 1, l, r);
				if(T.first < ans) {
					ans = T.first;
					sz = T.second;
				}
				else if(T.first == ans){
					sz += T.second;
				}
			}
			return make_pair(ans, sz);
		}
	}
	
	void modify(int u, int x, int c) {
		if(tr[u].l == x && tr[u].r == x) {
			tr[u].minx = c;
			tr[u].sz = 1;
		}
		else {
			int mid = (tr[u].l + tr[u].r) >> 1;
			if(x <= mid) modify(u * 2, x, c);
			if(x > mid) modify(u * 2 + 1, x, c);
			push_up(u);
		}
	}
}tr1, tr2;

void solve_1() {
	int ans = 0;
	for(int i = 1; i <= n; i ++ ) {
		tr1.build(1, 1, n);
		tr2.build(1, 1, n);
		tr1.modify(1, i, 0);
		for(int j = i + 1; j <= n; j ++ ) {
			int L, R = j;
			int l = i, r = j;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(check(mid, j)) r = mid;
				else l = mid + 1;
			}
			L = l;
			
			PII T1 = tr1.query(1, L, R);
			PII T2 = tr2.query(1, L, R);
			if(min(T1.first, T2.first) > INF / 2) break;
			
			if(T1.first < T2.first) {
				if(T1.second == 1) {
					tr1.modify(1, j, T1.first + 1);
				}
				if(T1.second == 2) {
					ans += 1;
					tr2.modify(1, j, T1.first + 1);
				}
			}
			if(T2.first < T1.first) {
				if(T2.second == 1) {
					ans += 1;
					tr2.modify(1, j, T1.first + 1);
				}
			}
		}
	}
	cout << ans << "\n";
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t -- ) {
		cin >> n >> d;
		for(int i = 1; i <= n; i ++ ) 
			cin >> x[i];
		if(c <= 10) solve_1();
	} 
	return 0;
}
