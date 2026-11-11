#include <iostream>
#include <algorithm>

#define Ls(p) ((p) << 1)
#define Rs(p) ((p) << 1 | 1)

struct Node {
	long long step;
	long long cnt;
	
	Node operator +(const Node& node) const {
		if (step == node.step) {
			return {step, cnt + node.cnt};
		} else if (step < node.step) {
			return *this;
		}
		return node;
	}
} tr[4000001];

long long pos[1000001] = {};

void build(int p, int l, int r) {
	if (l == r) {
		tr[p] = {(long long)1e18, 0};
		return ;
	}
	
	int mid = (l + r) >> 1;
	build(Ls(p), l, mid);
	build(Rs(p), mid + 1, r);
	
	tr[p] = tr[Ls(p)] + tr[Rs(p)];
}

void modify(int p, int l, int r, int x, const Node& v) {
	if (l == r) {
		tr[p] = v;
		return ;
	}
	
	int mid = (l + r) >> 1;
	
	if (mid >= x) {
		modify(Ls(p), l, mid, x, v);
	} else {
		modify(Rs(p), mid + 1, r, x, v);
	}
	
	tr[p] = tr[Ls(p)] + tr[Rs(p)];
}

Node query(int p, int l, int r, int x, int y) {
	if (l >= x && r <= y) {
		return tr[p];
	}
	
	int mid = (l + r) >> 1;
	Node res = {(long long)1e18, 0};
	
	if (mid >= x) {
		res = res + query(Ls(p), l, mid, x, y);
	}
	if (mid < y) {
		res = res + query(Rs(p), mid + 1, r, x, y);
	}
	
	return res;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int test = 0;
	int t = 0;
	std::cin >> test >> t;
	
	while (t--) {
		int n = 0;
		long long d = 0;
		std::cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			std::cin >> pos[i];
		}
		
		long long ans = 0;
		
		if (test >= 13 || test <= 14) {
			for (int i = 1; i < n; ++i) {
				int p = int(std::upper_bound(pos + i, pos + n + 1, pos[i] + d) - pos);
				
				--p;
				if (p - i >= 2) {
					int l = int(std::upper_bound(pos + p + 1, pos + n + 1, pos[p - 2] + d) - pos);
					int r = int(std::upper_bound(pos + p + 1, pos + n + 1, pos[p - 1] + d) - pos);
					ans += r - l;
				}
			}
			std::cout << ans << '\n';
		} else {
			for (int i = 1; i < n; ++i) {
				build(1, 1, n);
				modify(1, 1, n, i, {0, 1});
				for (int j = i + 1; j <= n; ++j) {
					int p = int(std::lower_bound(pos + i, pos + n + 1, pos[j] - d) - pos);
					if (p < j) {
						Node tmp = query(1, 1, n, p, j - 1);
						if (tmp.cnt == 2) {
							++ans;
						}
						++tmp.step;
						modify(1, 1, n, j, tmp);
					}
				}
			}
			
			std::cout << ans << '\n';
		}
	}
	
	return 0;
}