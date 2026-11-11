#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll a[500005];

//哦对了，关注luogu uid 1998043谢谢喵
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (long long i = 1; i <= m; i++) {
		long long minn = LONG_LONG_MAX, xb;
		for (int j = 1; j <= n; j++) {
			if (minn > a[j]) {
				xb = j;
			}
			minn = min(a[j], minn);
		}
		a[xb]++;
	}
	sort(a + 1, a + n + 1);
	long long ans = 1, z = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			ans++;
		} else {
			z = max(z, ans);
			ans = 1;
		}
	}//什么都不会,暴力多拿点吧
	cout << z;
	return 0;
}