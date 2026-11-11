#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

namespace PTqwq {
	
i64 readqwq() {
	i64 x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

const int N = 2e6 + 50;

i64 n, dis, a[N], pre[N], nxt[N], dpL[N], dpR[N], cntQ[N], cntL[N], cntR[N];

i64 queryAns(i64 l, i64 r) {
	i64 ans = 0;
	for (i64 i = l; i <= r; ++ i) {
		cntQ[i] = 0;
	}
	for (i64 i = l; i <= r; ++ i) {
		dpL[i] = cntQ[i];
		cntL[i] = cntQ[i];
		if (i > l) {
			if (nxt[i - 1] == i) {
				cntL[i] --;
			}
		}
		if (pre[i] < i) {
			if (nxt[pre[i]] == i) {
				dpL[i] += dpL[pre[i]];
			}
		}
		cntQ[nxt[i]] ++;
	}
	for (i64 i = l; i <= r; ++ i) {
		cntQ[i] = 0;
	}
	for (i64 i = r; i >= l; -- i) {
		dpR[i] = cntQ[i];
		cntR[i] = cntQ[i];
		if (i < r) {
			if (pre[i + 1] == i) {
				cntR[i] --;
			}
		}
		if (nxt[i] > i) {
			if (pre[nxt[i]] == i) {
				dpR[i] += dpR[nxt[i]];
			}
		}
		cntQ[pre[i]] ++;
	}
	for (i64 i = l; i < r; ++ i) {
		if (nxt[i + 1] > i + 1 && pre[i] < i) {
			if (pre[nxt[i + 1]] == i) {
				if (nxt[pre[i]] == i + 1) {
					ans = ans + dpL[pre[i]] * dpR[nxt[i + 1]];
				}
			}
		}
	}
	for (i64 i = l; i < r; ++ i) {
		if (nxt[i] > i + 1) {
			i64 p = nxt[i];
			if (nxt[p] > p) {
				if (pre[nxt[p]] == p - 1) {
					ans += dpR[nxt[p]];
				}
			}
		}
	}
	for (i64 i = r; i > l; -- i) {
		if (pre[i] < i - 1) {
			i64 p = pre[i];
			if (pre[p] < p) {
				if (nxt[pre[p]] == p + 1) {
					ans += dpL[pre[p]];
				}
			}
		}
	}
	for (i64 i = l; i < r; ++ i) {
		ans = ans + cntL[i + 1] * cntR[i];
	}
	return ans;
}

void solveQry() {
	n = readqwq();
	dis = readqwq();
	for (i64 i = 1; i <= n; ++ i) {
		a[i] = readqwq();
	}
	for (i64 i = 1, p = 1; i <= n; ++ i) {
		while (p < i && a[i] - a[p] > dis) {
			p ++;
		}
		pre[i] = p;
	}
	for (i64 i = n, p = n; i >= 1; -- i) {
		while (p > i && a[p] - a[i] > dis) {
			p --;
		}
		nxt[i] = p;
	}
	i64 ans = 0;
	i64 pos = 1;
	while (pos <= n) {
		i64 cur = pos;
		while (cur < n && a[cur + 1] - a[cur] <= dis) {
			cur ++;
		}
		ans += queryAns(pos, cur);
		pos = cur + 1;
	} 
	printf("%lld\n", ans);
}

void Solve() {
	i64 curC = readqwq();
	i64 T = readqwq();
	for (i64 i = 1; i <= T; ++ i) {
		solveQry();
	}
}
	
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	PTqwq::Solve();
	
	return 0;
}
