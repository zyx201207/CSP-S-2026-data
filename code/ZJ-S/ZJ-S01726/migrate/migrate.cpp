#include <bits/stdc++.h>
int n, tl[2097152], tr[2097152], rl[2097152], rr[2097152], fl[2097152], fr[2097152];
long long d, x[2097152];
int main() {
	freopen("migrate.in", "rb", stdin);
	freopen("migrate.out", "wb", stdout);
	int T;
	for(scanf("%*d%d", &T); T--; ) {
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		for(int i = 1, j = 1; i <= n; tr[i] = j, i++)
			while(j < n && x[i] + d >= x[j + 1])
				j++;
		for(int i = n, j = n; i >= 1; tl[i] = j, i--)
			while(j > 1 && x[i] - d <= x[j - 1])
				j--;
		for(int i = n; i >= 1; i--)
			rl[i] = i < n && tr[i] == tr[i + 1] ? rl[i + 1] : i;
		for(int i = 1; i <= n; i++)
			rr[i] = i > 1 && tl[i] == tl[i - 1] ? rr[i - 1] : i;
		for(int i = 1; i <= n; i++)
			fl[i] = fr[i] = 0;
		for(int i = 1; i <= n; i++)
			if(tr[i] > i) {
				fl[tr[i]]++;
				if(tl[tr[i]] == i)
					fl[tr[i]] += fl[i];
			}
		for(int i = n; i >= 1; i--)
			if(tl[i] < i) {
				fr[tl[i]]++;
				if(tr[tl[i]] == i)
					fr[tl[i]] += fr[i];
			}
		long long ans = 0;
		for(int i = 1; i < n; i++) {
			int x = tl[i + 1], y = tr[i];
			if(x < i && y > i + 1 && tr[x] == i + 1 && tl[y] == i) {
				int	xl = tl[i] == x ? fl[x] : 0,
					xr = tr[i + 1] == y ? fr[y] : 0,
					yl = rl[x] - x + 1, yr = y - rr[y] + 1;
				ans += 1LL * (xl + yl) * (xr + yr);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

