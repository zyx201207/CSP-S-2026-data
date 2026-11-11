#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

long long n, k, a[N], ii, lc, s[N], sc[N], ans = 1;
bool pa = 1, pb = 1;

map <long long, int> m;

int findl(int i)
{
	int fl = 1, fr = i;
	while (fl < fr) {
		int mid = ((fr - fl) >> 1) + fl;
		if (sc[i] - ((mid-1) * a[i] - s[mid-1]) <= k) fr = mid;
		else fl = mid + 1;
	}
	return fl;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i], m[a[i]] ++;
	}
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; ++ i) {
		s[i] = s[i-1] + a[i];
		if (i > 1) {
			if (a[i] - a[i-1] != 1) pa = 0;
			if (i > 2) {
				if (a[i] - a[i-1] != a[i-1] - a[i-2]) pb = 0;
			}
		}
	}
	
	ii = 1;
	for (auto x : m) {
		sc[ii] = (lc * x.first - s[lc]);
		lc = ii;
		ii += x.second;
	}
	for (int i = 2, last = 1; i <= n; ++ i) {
		if (sc[i] == 0) sc[i] = sc[i-1];
	}
	
	if (pa == 1 || pb == 1) {
		for (int i = n; i >= 1; -- i) {
			if (sc[i] <= k && k < sc[i + 1]) {
				cout << i;
				return 0;
			}
		}
	} else {
		for (long long i = 1; i <= n; ++ i) {
			int j = findl(i);
			ans = max(ans, i - j + 1);
		}
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
}