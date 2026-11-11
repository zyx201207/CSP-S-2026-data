#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int n, m;
int sc[N];
int q[N], head, tail = -1;

class SegmentTree {
public:
	SegmentTree(int _n) {
		n = 4 * _n + 5;
		tr = lz = vector<int>(n);
		build(1, 1, n);
	}
	
	void updateR(int l, int r, int k) {
		updatesr(1, 1, n, l, r, k);
	}
	
	int query(int p) {
		return queryp(1, 1, n, p);
	}
private:
	void build(int node, int l, int r) {
		if (l == r) {
			tr[node] = -1;
			return;
		}
		int mid = (l + r) >> 1;
		build(node << 1, l, mid);
		build(node << 1 | 1, mid + 1, r);
		push_up(node);
		
	}
	
	void push_up(int node) {
		tr[node] = tr[node << 1] + tr[node << 1 | 1];
	}
		
	void updatesr(int node, int l, int r, int lt, int rt, int k) {
		if (lt <= l && r <= rt) {
			tr[node] = k * (r - l + 1);
			lz[node] = k;
			return;
		}
		int mid = (l + r) >> 1;
		push_down(node, l, r);
		if (lt <= mid) updatesr(node << 1, l, mid, lt, rt, k);
		if (rt > mid) updatesr(node << 1 | 1, mid + 1, r, lt, rt, k);
		push_up(node);
	}
	
	void push_down(int node, int l, int r) {
		int mid = (l + r) >> 1;
		if (lz[node]) {
			tr[node << 1] = lz[node] * (mid - l + 1);
			tr[node << 1 | 1] = lz[node] * (r - mid);
			
			lz[node << 1] = lz[node << 1 | 1] = lz[node];
			lz[node] = 0;
		}
	}
	
	int queryp(int node, int l, int r, int p) {
		if (p <= l && r <= p) {
			return tr[node];
		}
		int mid = (l + r) >> 1;
		int result = 0;
		push_down(node, l, r);
		if (p <= mid) result += queryp(node << 1, l, mid, p);
		if (p > mid) result += queryp(node << 1 | 1, mid + 1, r, p);
		return result;
	}
	
	vector<int> tr, lz;
	int n;
};

inline int read() {
	char ch = getchar();
	int ans = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		ans = 10 * ans + ch - '0';
		ch = getchar();
	}
	return ans * f;
}

int answer[N];
int pos[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		sc[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		tail = -1;
		for (int i = 1; i <= m; i++) pos[i] = -1;
		
		for (int j = i; j <= n; j++) {
			if (pos[sc[j]] != -1) {
				int tmp = tail;
				tail = pos[sc[j]];
				for (int k = tmp; k > pos[sc[j]]; k--) pos[sc[k]] = -1;
			} else {
				pos[sc[j]] = tail + 1;
				q[++tail] = sc[j];
			}
		}
		
		for (int j = 0; j <= tail; j++) {
			answer[q[j]]++;
		}
	}
	
	for (int i = 1; i <= m; i++) cout << answer[i] << ' ';
	return 0;
}

