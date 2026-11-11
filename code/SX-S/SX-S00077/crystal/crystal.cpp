#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, cnt;
} a[500005], b[500005];
int fa[200005];
int fb[200005];
int k = 0;
int n;
long long m;
int N = 100000;

bool cmp(node x1, node y1) {
	return x1.cnt < y1.cnt || (x1.cnt == y1.cnt&&x1.x > y1.x);
}

bool cmp1(node x1, node y1) {
	return x1.x < y1.x;
}

int com(int st) {
	int ans = 0;
	for (int i = st; i >= 1; i--) {
		ans += a[fa[b[i].x + N]].cnt;
	}
	return ans;
}

bool cheak(int mid) {
	int x = a[mid].x;
	int st = fb[x + N];
	long long ans = 0;
	for (int i = st; i >= 1; i--) {
		ans += (x - b[i].x) * a[i].cnt;
		if (x == -58) {
		}
	}
	if (ans == m || (ans < m && st != k)) {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (fa[x + N] == 0) {
			k++;
			fa[x + N] = k;
			a[k].x = x, a[k].cnt = 1;
			b[k].x = x, b[k].cnt = k;
		} else {
			a[fa[x + N]].cnt++;
		}
	}
	sort(a + 1, a + 1 + k, cmp);
	sort(b + 1, b + 1 + k, cmp1);
	for (int i = 1; i <= k; i++) {
		fb[b[i].x + N] = b[i].cnt;
	}
	for (int i = 1; i <= k; i++) {
		fa[a[i].x + N] = i;
	}
	int l = 1, r = k;
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (cheak(mid) == true) {
			l = mid + 1;
			ans = max(ans, com(fb[a[mid].x + N]));
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}