#include<cstdio>
#include<algorithm>
const int MAXN = 200010, MAXM = MAXN << 1;
int n, a[MAXN];
char c[MAXN];
char t[3];
long long tmp[MAXM];
struct rec{long long l, r; char c;};
rec r[MAXM], rr[MAXM], input[MAXN], rinput[MAXN];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	long long sum = 0;
	for(int i = 1; i <= n; ++ i) scanf("%d%s", &a[i], t), c[i] = t[0], input[i] = {sum, sum + a[i], c[i]}, sum += a[i];
	sum = 0;
	for(int i = n; i >= 1; -- i) rinput[n - i + 1] = {sum, sum + a[i], c[i]}, sum += a[i];
	long long s = 0;
	int m = 0;
	for(int i = 1; i <= n; ++ i)
	{
		tmp[++ m] = s;
		s += a[i];
	}
	tmp[++ m] = sum;
	s = 0;
	for(int i = n; i >= 1; -- i)
	{
		tmp[++ m] = s;
		s += a[i];
	}
	tmp[++ m] = sum;
	std::sort(tmp + 1, tmp + m + 1);
	m = std::unique(tmp + 1, tmp + m + 1) - tmp - 1;
	for(int i = 1, j = 1; i < m; ++ i) 
	{
		while(j <= n && !(input[j].l <= tmp[i] && tmp[i + 1] <= input[j].r)) j ++;
		r[i] = {tmp[i], tmp[i + 1], input[j].c};
	}
	for(int i = 1, j = 1; i < m; ++ i) 
	{
		while(j <= n && !(rinput[j].l <= tmp[i] && tmp[i + 1] <= rinput[j].r)) j ++;
		rr[i] = {tmp[i], tmp[i + 1], rinput[j].c};
	}
	long long ans = 0;
	for(int i = 1; i < m; ++ i)
	{
		if(r[i].l + 1 > sum / 2) break;
		if(r[i].c != rr[i].c) ans += r[i].r - r[i].l;
	}
	printf("%lld\n", ans);
	return 0;
}
