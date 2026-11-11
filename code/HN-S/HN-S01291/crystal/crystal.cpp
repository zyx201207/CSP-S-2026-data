#include <iostream>
#include <random>
#include <cstring>
#include <algorithm>
#define popcount __builtin_popcount
#define stop_sync do { ios::sync_with_stdio(false); cin.tie(nullptr); } while (0)
#define fileio(s) do { freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout); } while (0)
#define rep(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define repl(i, a, b) for (int i = (int) (a); i < (int) (b); i++) 
#define per(i, a, b) for (int i = (int) (a); i >= (int) (b); i--)
#define nocpy const auto &
#define all(iter) (iter).begin(), (iter).end()
#define pred(it, expr) [&] (nocpy it) { return (expr); }
#define comp(lhs, rhs, expr) [&] (nocpy lhs, nocpy rhs) { return (expr); }
#define update_v(v, expr, func) (v) = func((v), (expr))
#define zeroize(v) memset(v, 0x00, sizeof(v))

// 我真求你了 
#define int long long
 
using namespace std;

using i64 = long long;

constexpr int MAXN = 5e5 + 10;

i64 n, m;
i64 a[MAXN];
i64 delta[MAXN], diff[MAXN];


struct SegmentTree {
	#define lc (idx << 1)
	#define rc (idx << 1 | 1)
	#define mid ((l + r) >> 1)
	i64 val[MAXN << 2], lazy[MAXN << 2];
	
	void pushup(int idx) { val[idx] = val[lc] + val[rc]; }
	
	// 因为 mid 宏都是一个算法, 所以没必要传进来 
	void pushdown(int idx, int l, int r) {
		lazy[lc] += lazy[idx], val[lc] += 1ll * (mid - l + 1) * lazy[idx];
		lazy[rc] += lazy[idx], val[rc] += 1ll * (r - mid) * lazy[idx];
		lazy[idx] = 0;
	}
	
	void build(int idx, int l, int r) {
		if (l == r) { val[idx] = delta[l]; return; }
		build(lc, l, mid);
		build(rc, mid + 1, r);
		pushup(idx);
	}
	
	void build() { return build(1, 1, n); }
	
	void update(int L, int R, i64 v, int idx, int l, int r) {
		if (L <= l && r <= R) {
			val[idx] += 1ll * (r - l + 1) * v;
			lazy[idx] += v;
			return;
		}
		pushdown(idx, l, r);
		if (L <= mid)     update(L, R, v, lc, l, mid);
		if (mid + 1 <= R) update(L, R, v, rc, mid + 1, r);
		pushup(idx);
	}
	
	void update(int L, int R, int v) { return update(L, R, v, 1, 1, n); }
	
	
	int query(int pos, int idx, int l, int r) {
		if (l == r) return val[idx];
		pushdown(idx, l, r);
		if (pos <= mid) return query(pos, lc, l, mid);
		else			return query(pos, rc, mid + 1, r);
	}
	
	int query(int pos) { return query(pos, 1, 1, n); }
	
	int query_pos(i64 sum, int idx, int l, int r) {
//		printf("query_pos(%lld, %d, %d, %d)\n", sum, idx, l, r);
		if (l == r) { return l - (sum < val[idx]); } // 需要另外判断最后一个能不能选 
		pushdown(idx, l, r);
		i64 sum_l = val[lc];
		if (sum >= sum_l) return query_pos(sum - sum_l, rc, mid + 1, r);
		else			  return query_pos(sum, lc, l, mid);
	}
	
	int query_pos(i64 sum) { return query_pos(sum, 1, 1, n); }
	
	#undef lc
	#undef rc
	#undef mid
} st;


void input() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];

}

void preprocess() {
	sort(a + 1, a + n + 1, greater<i64>());
	rep(i, 2, n) delta[i] = a[1] - a[i];
	rep(i, 2, n) diff[i] = a[i - 1] - a[i];
	st.build(1, 1, n);
} 

i64 greedy() {
	// 因为我们只能增加水晶的值, 所以肯定存在一个最优解是以某个数字为瓶颈的
	// 我们可以枚举这个瓶颈, 然后统计一下它下面最多能选进来多少个水晶并且不会超过范围
	// 首先第一步肯定是排序, 从大到小 
	// 然后问题就转变成要怎么样才能使得我们能在 log 级别的时间统计出来左边可以选进来多少了
	// 求你了线段树别爆炸, 我甚至感觉主席树比线段树好写
	i64 ret = 0;
	
//	rep(j, 1, n) cout << st.query(j) << " "; cout << endl;
//	rep(i, 1, n) cout << diff[i] << " "; cout << endl;
	rep(i, 1, n) {
		st.update(i, n, -diff[i]);
//		rep(j, 1, n) cout << st.query(j) << " "; cout << endl;
//		printf("Calling st.query_pos(%lld)\n", m);
		i64 pos = st.query_pos(m) - (i - 1);
//		printf("ret = %lld\n", st.query_pos(m));
		update_v(ret, pos, std::max);
	}
	return ret; 
}

i64 brute() {
	i64 ret = 0;
	repl(state, 1, (1 << n)) {
		i64 max_elem = LLONG_MIN;
		rep(i, 1, n) if (state & (1 << (i - 1))) update_v(max_elem, a[i], std::max);
		i64 cost = 0;
		rep(i, 1, n) if (state & (1 << (i - 1))) cost += max_elem - a[i];
		if (cost <= m) update_v(ret, (i64) popcount(state), std::max);
	}
	return ret;
}

struct Random {
	mt19937 rng;
	i64 randint(i64 l, i64 r) { return uniform_int_distribution<i64>(l, r)(rng); }
} r;

void gen() {
	n = r.randint(1, 4);
	m = r.randint(1, 5) * 10000000000000LL;
	rep(i, 1, n) a[i] = r.randint(-2, 2) * 10000000000000LL;
}

signed main() {
	stop_sync;
	fileio("crystal");
	input();
	preprocess();
	cout << greedy() << endl;
//	cout << brute() << endl;
//	while (true) {
//		zeroize(st.lazy), zeroize(st.val);
//		zeroize(a), zeroize(diff); 
//		gen();
//		preprocess();
//		if (brute() != greedy()) {
//			cout << n << " " << m << endl;
//			rep(i, 1, n) cout << a[i] << " ";
//			cout << endl;
//			printf("exp = %lld, got = %lld\n", brute(), greedy());
//		}
//	}
	return 0;
} 
