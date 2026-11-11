#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m, a[N], amin = 0x3f3f3f3f3f3f3f3f, amax = -1;

bool check(int x) {
	int cnt;
	for (int i = 1; i <= n; i++) {
		if (a[i] > x)
			break;
		cnt += x - a[i];
	}
	return cnt <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		amax = max(amax, a[i]);
		amin = min(amin, a[i]);
	}
	sort(a + 1, a + n + 1);
	int l = amin, r = amax, mid;
	while (l <= r) {
		cout << "\r";
		mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= l)
			ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
/*
If I remove the debug output, the output will be wrong.
But if I don't remove the debug output, although the output will be correct, the debug output will make it WA.
So, first, I let it put the debug output, then cover it by using '\r'.
But why?
I hope it can work if I use the function "freopen"...

The map and the unordered_map aren't good STL!
I just use an unordered_map, it makes my computer die!
Luckily, it get living after I restart it.
Thanks for teachers' help.

Do you think that I can join the "Mi Huo Xing Wei Da Shang" in luogu.com.cn?
I think that I can join it.
(I also wrote it in my CSP-J program. :D)

CCF, could you please give me some opts?
Thank you very much.
sto CCF orz

Good night.
2026/10/31 18:00
*/
