/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Info {
	ll len, l, r;
	char c;
} a[200011];

int n;
ll ans, cnt[26], len, s[26][200011], su[200011];
char c[200011];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		cin >> a[i].len >> a[i].c;
	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		a[i].l = cur + 1;
		a[i].r = cur + a[i].len;
		cur += a[i].len;
	}
	len = cur;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 26; j++)
			s[j][i] = s[j][i];
		s[a[i].c - 'a'][i] += a[i].len;
		su[i] = su[i + 1] + a[i].len;
	}
	ll pre = 0;
	a[n + 1].l = 1e18;
	for (int i = 1; i <= n; i++) {
		pre += a[i].len;
		if (len - pre + 1 <= pre) {
			
		}
		memset(cnt, 0, sizeof(cnt));
		int L1 = i, R1 = n + 1;
		while (L1 + 1 < R1) {
			int M1 = (L1 + R1) / 2;
			if (a[M1].l <= len - pre + 1)
				L1 = M1;
			else
				R1 = M1;
		}
		int L2 = i, R2 = n;
		while (L2 + 1 < R2) {
			int M2 = (L2 + R2) / 2;
			if (a[M2].l <= len - (pre - a[i].len + 1) - 1)
				L2 = M2;
			else
				R2 = M2;
		}
		for (int j = 0; j < 26; j++) {
			cnt[i] = s[j][L1] - s[j][R2];
		}
		cnt[a[L1].c - 'a'] -= su[L1] - pre;
		cnt[a[R2].c - 'a'] -= su[R2] - pre + a[i].len;
		ans += a[i].len - cnt[a[i].c  - 'a'];
	}
	printf("%lld\n", ans);
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

int n, ans;
char s[20000011];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "W", stdout);
	scanf("%d", &n);
	int len = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		for (int i = 1; i <= a; i++)
			s[++len] = c ;
	}
	for (int i = 1; i <= len / 2; i++)
		if (s[i] != s[len - i + 1])
			++ans;
	printf("%d\n", ans);
}
