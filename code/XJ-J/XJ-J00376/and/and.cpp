#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
struct node {
	int x, sum;
}a[N];
int one (int x)
{
	int cnt = 0;
	while (x)
	{
		x &= x - 1;
		cnt ++;
	}
	return cnt;
}
bool cmp (node q, node h)
{
	return q.sum > h.sum;
}
int main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%lld", &a[i].x);
		a[i].sum = one (a[i].x);
	}
	sort (a + 1, a + n + 1, cmp);
	int ans = a[1].x;
	for (int i = 2; i <= m; i ++) ans &= a[i].x;
	printf ("%d", ans);
	return 0;
}