#include <bits/stdc++.h>
#define ll long long
#define int long long
#define mid ((l + r) >> 1)
#define lowbit(x) ((x) & -(x))

using namespace std;

namespace Fread {
	static constexpr int SIZE = 1 << 20;
	char buf[SIZE], *S, *T;
	inline char getchar() {
		if (S == T) {
			T = (S = buf) + fread(buf, 1, SIZE, stdin);
			if (S == T) return '\n';
		}
		return *S++;
	}
} // namespace Fread
namespace Fwrite {
	static constexpr int SIZE = 1 << 20;
	char buf[SIZE], *S = buf, *T = buf + SIZE;
	inline void flush() {
		fwrite(buf, 1, S - buf, stdout);
		S = buf;
	}
	inline void putchar(char c) {
		*S++ = c;
		if (S == T) flush();
	}
	struct Flush {
		~Flush() { flush(); }
	} f;
} // namespace Fwrite
#define getchar Fread::getchar
#define putchar Fwrite::putchar

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x == 0) { putchar('0'); return; }
	if (x < 0) { putchar('-'); x = -x; }
	static int sta[45];
	int top = 0;
	while (x) { sta[++top] = x % 10; x /= 10; }
	while (top) { putchar(sta[top--] + '0'); }
}

constexpr int N = 2e6 + 5;

int C, T, n, d;
int a[N], posl[N], posr[N], wl[N], wr[N], cntr[N];
vector<int> vecl[N], vecr[N];

void clear() {
	fill(posl, posl + n + 2, 0);
	fill(posr, posr + n + 2, 0);
	fill(wl, wl + n + 2, 0);
	fill(wr, wr + n + 2, 0);
	fill(cntr, cntr + n + 2, 0);
	for (int i = 1; i <= n; ++i) {
		vecl[i].clear();
		vecr[i].clear();
	}
}

void Solve() {
	clear();
	n = read(), d = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	
	for (int i = 1; i <= n; ++i) {
		auto check = [&](int i, int j) -> bool {
			return abs(a[i] - a[j]) <= d;
		};
		
		int l = 1, r = i;
		while (l <= r) {
			if (check(i, mid)) {
				posl[i] = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		
		l = i, r = n;
		while (l <= r) {
			if (check(i, mid)) {
				posr[i] = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (posl[i] != i) {
			vecl[posl[i]].push_back(i);
		}
		if (posr[i] != i) {
			vecr[posr[i]].push_back(i);
		}
		++cntr[posr[i]];
	}
	
	for (int i = 1; i <= n; ++i) {
		wl[i] = 1;
		if (i == 1 || posr[posl[i]] != i) {
			continue;
		}
		wl[i] += wl[posl[i]];
		
		auto check = [&](int pos) -> bool {
			return pos > posl[i];
		};
		
		sort(vecr[i].begin(), vecr[i].end());
		int l = 0, r = vecr[i].size() - 1, p = vecr[i].size();
		while (l <= r) {
			if (check(vecr[i][mid])) {
				p = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		wl[i] += (vecr[i].size() - p);
	}
	for (int i = n; i > 0; --i) {
		wr[i] = 1;
		if (i == n || posl[posr[i]] != i) {
			continue;
		}
		wr[i] += wr[posr[i]];
		
		auto check = [&](int pos) -> bool {
			return pos < posr[i];
		};
		
		sort(vecl[i].begin(), vecl[i].end());
		int l = 0, r = vecl[i].size() - 1, p = -1;
		while (l <= r) {
			if (check(vecl[i][mid])) {
				p = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		wr[i] += p + 1;
	}
	
//	cerr << "debug:\n";
//	for (int i = 1; i <= n; ++i) {
//		cerr << posl[i] << " \n"[i == n];
//	}
//	for (int i = 1; i <= n; ++i) {
//		cerr << posr[i] << " \n"[i == n];
//	}
//	cerr << "end\n";
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (i - posl[i] <= 1) {
			continue;
		}
		ans += cntr[posl[i] + 1];
	}
	for (int u = 1; u <= n; ++u) {
		int v = posr[posr[u]];
		if (v != posr[u] && posr[u] - posl[v] == 1) {
//			cerr << "case v: " << u << ' ' << v << '\n';
			ans += wr[v] - 1;
		}
	}
	for (int v = 1; v <= n; ++v) {
		int u = posl[posl[v]];
		if (u != posl[v] && posr[u] - posl[v] == 1) {
//			cerr << "case u: " << u << ' ' << v << ' ' << wl[u] - 1 << '\n';
			ans += wl[u] - 1;
		}
	}
//	cerr << "ans: " << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		int p = posl[posl[i]];
		if (posr[posr[p]] == i && posr[p] - posl[i] == 1 && posr[p] < i && posl[i] > p) {
			ans += (wl[p] - 1) * (wr[i] - 1);
		}
	}
	
	write(ans);
	putchar('\n');
}
/*
len(u, v) = 2 且 (u, v) 合法：
posr[u] - posl[v] = 1, u < posl[v]

可以往 v 那边扩展，就再限制 v = posr[posr[u]]
*/

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	
	C = read(), T = read();	
	while (T--) {
		Solve();
	}
	
	cerr << "time: " << (double)clock() / CLOCKS_PER_SEC << '\n';
	
	return 0;
}
/*
就是，首先最短路径，是可以贪心求的吗

最短路径恰好为 2，是何意味啊

先别急，我是不是可以做 O(n^3)，就是，固定右端点，然后从后往前枚举左端点，算最短路径长度和数量，每次转移是 O(n) 的

哦，然后注意到，相同的最短路径长度一定是一个区间，然后可以记录后缀和，这样单次转移就是 O(1) 了

谔谔，感觉这个肯定是没啥办法在移动右端点的时候整体转移了，那咋办

-----

能不能再刻画一下合法的对啊

就是，首先最短路径有两种贪心方法：从两端分别贪心地跳

合法的对肯定满足，这两种贪心方法求出的路径不同

然后同时就没有其他的合法对了

哦哦

这个的本质是不是

就是路径上存在两个点 (u, v)，起点到 u 和终点到 v 的路径都只能贪心地最大限度地走，u 到 v 的最短路径长度为 2，且恰好有两条

那就是 u 到 v 必须经过 k 或者 k + 1，(u, k + 1) 和 (k, v) 都合法，(u, k + 2) 和 (k - 1, v) 都错了

额，这真的已经描述清楚合法对的刻画了吗

算了，大概就是，求出所有的 (u, v) 是容易的？就是 v 往前贪心地跳两步，然后 check 那个 u 就行了 
*/
// 16:31，怎么通过所有大样例了，太令人感动了
