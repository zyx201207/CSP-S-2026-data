#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pque priority_queue

using namespace std;

int n, res = 1;
ll a[500005], m, mmax = (-1 << 60), mmin = (1 << 60);

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%lld", a + i), mmin = min(mmin, a[i]), mmax = max(mmax, a[i]);
	if((mmax - mmin) * (n - 1) < m) {
		printf("%d", n);
		return 0;
	}
	sort(a + 1, a + 1 + n);
	
	ll diff = a[2] - a[1];
	for(int i = 2; i < n; ++i) {
		if(a[i + 1] - a[i] != diff) goto label;
	}
	
	for(int i = n - 1; i >= 1; --i) {
		if(a[n] == a[i]) ++res;
		else if(m >= a[n] - a[i]) ++res, m -= a[n] - a[i];
		else break;
	}
	printf("%d", res);
	return 0;
	
	label:;
	for(int i = 1; i <= n; ++i) {
		ll t = m;
		int ans = 1;
		for(int j = i - 1; j >= 1 && t; --j) {
			if(a[j] == a[i]) ++ans;
			else if(t >= a[i] - a[j]) t -= a[i] - a[j], ++ans;
			else break;
		}
		res = max(res, ans);
	}
	printf("%d", res);
	
	return 0;
}

