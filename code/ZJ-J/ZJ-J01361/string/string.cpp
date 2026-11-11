#include <bits/stdc++.h>
using namespace std;
long long a[200005], ra[200005];
char ch[200005], rch[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		cin >> ch[i];
		ra[i] = a[i], rch[i] = ch[i];
	}
	reverse(ra + 1, ra + n + 1);
	reverse(rch + 1, rch + n + 1);
	ra[n] = a[1], rch[n] = ch[1];
	/*for (int i = 1; i <= n; i++)
	{
		printf("%lld%c %lld%c\n", a[i], ch[i], ra[i], rch[i]);
	}*/
	int i = 1, j = 1;
	long long la = a[1], lr = ra[1];
	long long ans = 0;
	while (i <= n || j <= n)
	{
		long long t = min(la, lr);
		if (ch[i] != rch[j]) 
		{
			/*printf("lft,(%d)%c, rgh,(%d)%c +%lld\n", i, ch[i], j, rch[j], t);*/
			ans += t;
		}
		la -= t;
		lr -= t;
		if (la == 0) i++, la = a[i];
		if (lr == 0) j++, lr = ra[j];
	}
	printf("%lld", ans / 2);
	return 0;
}
