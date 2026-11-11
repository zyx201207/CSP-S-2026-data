//SN-J00782 李承欢 西安市铁一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200100;
char ch[N], s1[N], s2[N], q1[N], q2[N];
int n, a[N], a1[N], a2[N], sum, tot1, tot2, tot, b[N], c[N];

signed main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> ch[i];
		sum += a[i];
	}
	sum /= 2;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt + a[i] <= sum) {
			cnt += a[i];
			a1[++tot1] = a[i];
			s1[tot1] = ch[i];
		} else {
			a1[++tot1] = sum - cnt;
			s1[tot1] = ch[i];
			break;
		}
	}
	cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (cnt + a[i] <= sum) {
			cnt += a[i];
			a2[++tot2] = a[i];
			s2[tot2] = ch[i];
		} else {
			a2[++tot2] = sum - cnt;
			s2[tot2] = ch[i];
			break;
		}
	}
	cnt = 0;
	for (int i = 1; i <= tot1; i++) {
		cnt += a1[i];
		b[i] = cnt;
	}
	cnt = 0;
	for (int i = 1; i <= tot2; i++) {
		cnt += a2[i];
		b[tot1 + i] = cnt;
	}
	sort(b + 1, b + tot1 + tot2 + 1);
	for (int i = 1; i <= tot1 + tot2; i++) {
		if (b[i] != b[i - 1]) {
			c[++tot] = b[i];
		}
	}
	int now = 1, tott = 0;
	cnt = 0;
	for (int i = 1; i <= tot1; i++) {
		cnt += a1[i];
		for (int j = now; j <= tot; j++) {
			if (c[j] <= cnt) {
				q1[++tott] = s1[i];
				now++;
			} else {
				break;
			}
		}
	}
	now = 1, tott = 0, cnt = 0;
	for (int i = 1; i <= tot2; i++) {
		cnt += a2[i];
		for (int j = now; j <= tot; j++) {
			if (c[j] <= cnt) {
				q2[++tott] = s2[i];
				now++;
			} else {
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= tott; i++) {
		if (q1[i] != q2[i]) {
			ans += c[i] - c[i - 1];
		}
	}
	cout << ans;
	return 0;
}
