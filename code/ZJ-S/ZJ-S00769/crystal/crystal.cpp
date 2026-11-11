#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define p_b push_back

const int N = 5e5+5;
int n, l, r, res = 0;
ll m, a[N], s[N]; 

signed main() 
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	s[0] = 0; for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i];
	l = r = 1;
	while (r <= n) {
		if (-s[r-1]+s[l-1]+(r-l)*a[r] <= m) res = max(res, r-l+1), ++r;
		else ++l;
	}
	printf("%d\n", res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}