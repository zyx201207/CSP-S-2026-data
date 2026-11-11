#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
typedef long long ll;

int n;
ll m, a[N], s[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	
	ll l = 1, r;
	int res = 0;
	for (r = 1; r <= n; r ++)
	{
		while (l < r && (r - l) * a[r] - s[r - 1] + s[l - 1] > m) l ++;
		res = max((ll)res, r - l + 1);
	}
	printf("%d", res);
	
	return 0;
}
