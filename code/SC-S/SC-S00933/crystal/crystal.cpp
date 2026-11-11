#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long
#define f(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);

const int N = 5e5 + 5;
int n, m, a[N];
int idx, maxx = 0, cost = 0, ans = 0, cnt = 0;

void add(int x)
{
	cost += cnt * (a[x] - maxx);
	maxx = max(maxx, a[x]);
	cnt ++;
}

void sub(int x)
{
	cost -= maxx - a[x];
	cnt --;
}

void reg(int x)
{
	cnt --;
	cost += cnt * (a[x - 1] - maxx);
	maxx = min(maxx, a[x - 1]);
}

signed main()
{
	f(crystal);
	scanf("%lld%lld", &n, &m);
	
	for (int i = 1; i <= n; ++ i)
		scanf("%lld", a + i);
	
	sort(a + 1, a + 1 + n);
	
	int i = 1, j = 1;
	maxx = a[i], cnt = 1;
	
	while (i < n)
	{
		while (j <= n && cost <= m) 
			add(++ j);
		reg(j --);
		ans = max(ans, cnt);
		sub(i ++);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}