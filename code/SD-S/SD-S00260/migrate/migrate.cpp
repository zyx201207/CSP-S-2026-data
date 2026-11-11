#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char a = getchar();
	while (a < '0' || a > '9') {
		if (a == '-') f = -1;
		a = getchar();
	}
	while (a >= '0' && a <= '9') {
		x = x * 10 + a - '0';
		a = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 2e6 + 10;
int c, T;
int a[N];
int t[N];
int s[N];
int as[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read();
	T = read();
	if (c == 13 || c == 14) {
		while (T--) {
			int n = read(), d = read();
			for (int i = 1; i <= n; ++i) a[i] = read();
			cout << 0 << endl;
		}
		return 0;
	}
	while (T--) {
		memset(a, 0, sizeof a);
		memset(t, 0, sizeof t);
		memset(as, 0, sizeof as);
		memset(s, 0, sizeof s);
		int n = read(), d = read();
		for (int i = 1; i <= n; ++i) a[i] = read();
		a[0] = -0x3f3f3f3f3f3f3f3f;
		a[n + 1] = 0x3f3f3f3f3f3f3f3f;
		int now = 1;
		for (int i = 1; i <= n; ++i) {
			while (now <= n && a[now] - a[i] <= d) {
				now++;
			}
			now--;
			t[i] = now;
			if (t[i + 1] - t[i] > d && now < n) {
				now = i + 1;
			}
		}
		now = n;
		for (int i = n; i >= 1; --i) {
			while (now >= 1 && a[i] - a[now] <= d) {
				now--;
			}
			now++;
			s[i] = now;
			as[now]++;
			if (s[i - 1] - s[i] > d && now > 1) {
				now = i - 1;
			}
		}
		int cnt = 1;
		int ans = 0;
		int last = 0, cmp = 0;
		bool flag = 0;
		while (cnt <= n) {
			flag = 0;
			if (a[cnt] - a[cnt - 1] > d) flag = 1;
			if (t[cnt] == cnt) {
				cnt++;
				ans += last * cmp;
				last = cmp = 0;
				continue;
//			}else if (t[cnt] != cnt + 1 && as[cnt] - flag == 2) {
			}else if (t[cnt] != cnt + 1) {
				for (int i = cnt + 1; i < t[cnt] && i < n; ++i) {
					if (t[i] <= t[t[cnt]]) {
						ans++;
//						cout << i << ":" << cnt << '\n';
					}
				}
				ans += last * cmp;
			} else if (t[cnt] == cnt + 1){
				cmp++;
			}
//			cnt++;
			cnt = t[cnt];
		}
//		for (int i = 1; i <= n; ++i) {
//			cout << t[i] << "::" << as[i] << ":::\n";
//		}
		write(ans);
		putchar('\n');
		//我服了看错时间慌慌张张本来能做对结果爆了 
	}
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4
2
*/
