#include<cstdio>
#include<algorithm> 
const int MAXN = 500010;
int n;
long long m;
long long a[MAXN], s[MAXN];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++ i) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for(int i = 1, l = 1; i <= n; ++ i)
	{
		while(l <= i && (i - l + 1) * a[i] - s[i] + s[l - 1] > m) l ++;
		ans = std::max(ans, i - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
