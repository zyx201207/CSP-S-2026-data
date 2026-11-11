#include <bits/stdc++.h>
#define int int64_t

const int maxn = 2097152;

int c, t;
int n, d, pos[maxn], bound[maxn];

struct segment {
	int minval, cnt;
	
	segment() {
		minval = 0;
		cnt = 0;
	}
	
	segment(int min, int c) {
		minval = min;
		cnt = c;
	}
	
	segment operator+(
		const segment& e) const& {
			segment ans;
			ans.minval = std::min(minval, e.minval);
			if (ans.minval == minval) ans.cnt += cnt; 
			if (ans.minval == e.minval) ans.cnt += e.cnt;
			ans.cnt = std::min(ans.cnt, (int)3);
			return ans;
		}
} dp[maxn], T[maxn * 4];

void maintain(int node) {
	T[node] = 
		T[node << 1] + T[node << 1 | 1];
}

void build(int node, int l, int r) {
	if (l == r) {
		T[node] = segment(n * n, 0);
	} else {
		int mid = (l + r) / 2;
		build(node << 1, l, mid);
		build(node << 1 | 1, mid + 1, r);
		maintain(node);
	}
}

void modify(int node, int l, int r, 
	const int &pos, const segment &seg) {
		if (l == r) {
			T[node] = seg;
			dp[pos] = seg;
		} else {
			int mid = (l + r) / 2;
			if (pos <= mid) modify(node << 1, l, mid, pos, seg);
			else modify(node << 1 | 1, mid + 1, r, pos, seg);
			maintain(node);
		}
	}

segment query(int node, int l, int r,
	int ll, int rr) {
		if (ll > rr) return segment(n * n, 0);
		if (ll <= l && r <= rr) return T[node];
		else {
			int mid = (l + r) / 2;
			if (rr <= mid)
				return query(node << 1, l, mid, ll, rr);
			if (mid < ll)
				return query(node << 1 | 1, mid + 1, r, ll, rr);
			return query(node << 1, l, mid, ll, rr)
				+ query(node << 1 | 1, mid + 1, r, ll, rr);
		}
	}

void dp_solve(int x) {
	build(1, 1, n);
	modify(1, 1, n, x, segment(0, 1));
	
	for (int i = x + 1; i <= n; i++) {
		segment seg = query(1, 1, n, bound[i], i - 1);
		modify(1, 1, n, i, segment(seg.minval + 1, seg.cnt));
	}
}

int read() {
	char ch = '@';
	int ans = 0, sign = 1;
	while (true) {
		ch = getchar();
		if (ch == '-') sign = -1;
		if ('0' <= ch && ch <= '9') break;
	}
	
	while (true) {
		ans = ans * 10 + ch - '0';
		ch = getchar();
		if (!('0' <= ch && ch <= '9')) break;
	}
	
	return ans * sign;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	c = read(); t = read();
	
	for (int test = 1; test <= t; test++) {	
		n = read();
		d = read();
		for (int i = 1; i <= n; i++) 
			pos[i] = read();
			
		int id = 1;
		for (int i = 1; i <= n; i++) {
			while (pos[id] + d < pos[i]) id += 1;
			bound[i] = id;
		}
			
		if (n == 1) {
			std::cout << "0\n";
			continue;
		}
		
		bool flag = true;
		for (int i = 1; i <= n; i++)
			if (pos[i] != pos[1] + (i - 1) * (pos[2] - pos[1]))
				flag = false;
		
		if (flag) {
			int diff = pos[2] - pos[1];
			dp_solve(1);
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (dp[i].cnt == 2)
					ans += n - i + 1;
			std::cout << ans << "\n";
		} else if (n <= 5000) {		
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				dp_solve(i);
				for (int j = i + 1; j <= n; j++) 
					if (dp[j].cnt == 2) 
						ans += 1;	
			} std::cout << ans << "\n";
		} else std::cout << "0\n";
	}
	
	return 0;
}
