#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n, m, a[N];
bool check(long long num)
{
	int sum = 0;
	for (int i = 1; i < num; i++) {
		sum += abs(a[num] - a[i]);
	}
	if (sum <= m) return true;
	else return false;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if (n <= 5000) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = 1; j < i; j++) {
				sum += (a[i]-a[j]);
			}
			if (sum <= m) ans = i;
			else break;
		}
		cout << ans;
		return 0;
	}
	long long l = 0, r = n+1;
	while (l < r)
	{
		long long mid = (l+r)/2;
		if (check(mid)) {
			if (l == mid) break;
			l = mid;
		} else {
			r = mid-1;
		}
	}
	cout << l;
}