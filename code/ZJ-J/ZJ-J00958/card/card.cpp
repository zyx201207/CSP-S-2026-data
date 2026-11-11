#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;

int a[maxn];
int b[maxn];
int cnt[maxn];
int c[maxn];
bool add[maxn];

int n, m, l;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		c[i] = a[i];
	}
	
	bool ok = 1;
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i ++) if (a[i] != c[i]) {
		ok = 0;
		break;
	}
	if (ok) {
		int ans = 0, res = 0;
		memset(c, 0, sizeof c);
		for (int i = 1; i <= n; i ++) c[a[i]] ++, cnt[a[i]] = 1;
		for (int i = 1; i < n; i ++) {
			c[a[i]] --;
			for (int j = 1; j <= n; j ++) add[a[j]] = 0;
			for (int j = 1; j <= n; j ++) {
				if (c[a[j]] && !add[a[j]]) {
					cnt[a[j]] ++;
					add[a[j]] = 1;
				}
			}
		}
		for (int i = 1; i <= m; i ++) cout << cnt[i] << ' ';
		return 0;
	}
	
	for (int t = 1; t <= n; t ++) {
		l = 0;
		for (int i = t; i <= n; i ++) {
			int found = 0;
			for (int j = 1; j <= l; j ++) {
				if (b[j] == a[i]) {
					found = j;
					break;
				}
			}
			if (found) l = found;
			else b[++ l] = a[i];
		}
		for (int i = 1; i <= l; i ++) cnt[b[i]] ++;
	}
	
	for (int i = 1; i <= m; i ++) cout << cnt[i] << ' ';
	return 0;
}

