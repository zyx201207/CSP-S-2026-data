#include<bits/stdc++.h>
#define pre(i, l, r)	for(int i = (l); i <= (r); ++i)
#define fpre(i, r, l)	for(int i = (r); i >= (l); --i)
#define ll long long

using namespace std;

const int maxn = 1e6 + 5;
const int inf = 1e9;
const ll lnf = 2e18;

int n;
ll m, a[maxn], s[maxn];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	pre(i, 1, n)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	pre(i, 1, n)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	pre(i, 1, n)
	{
		int L = 0, R = i + 1;
		while(L + 1 < R)
		{
			int M = (L + R) / 2;
			if(a[i] * M - (s[i] - s[i - M]) <= m)
				L = M;
			else
				R = M;
		}
		ans = max(ans, L);
	}
	printf("%d\n", ans);
	return 0;
} 
