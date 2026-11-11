# include <cstdio>
# include <algorithm>

# define maxn 500010
long long n, m, l, r, mid, id, ans, a[maxn], s[maxn];

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	scanf("%lld %lld", &n, &m);

	for (long long i = 1; i <= n; i++)
		scanf("%lld", &a[i]);

	std::sort(a + 1, a + n + 1);

	for (long long i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		l = 1, r = i, id = i;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) -
			        s[i] + s[mid - 1] <= m) {
				id = mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}
		if (i - id + 1 > ans)
			ans = i - id + 1;
	}

	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);

	return 0;

}
