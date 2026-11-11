#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, fx = 1;
int a[N];

int midle(int l, int r) {
	return l + (r - l) / 2;
}

struct node {
	int z, c;
};
vector<node>v;

bool compare(node a, node b) {
	return a.c < b.c;
}

int work(int l, int r) {
	v.clear();
	int times = 0, cz = m;
	int md = midle(l, r);
	int mid = a[md];
	for (int i = 1; i <= n; i++) {
		int jz = mid - a[i];
		if (jz >= 0)
			v.push_back({a[i], jz});
	}
	sort(v.begin(), v.end(), compare);
	int len = v.size();
	while (cz > 0 && times < len && times <= n) {
		if (v[times].c > cz)
			break;
		cz -= v[times].c;
		times++;
	}
	if (cz > 0)
		fx = 1;
	else
		fx = 0;
	return times;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = n;
	int ans = 0;
	int last = 0;
	while (l <= r) {
		int mm = midle(l, r);
		ans = max(ans, work(l, r));
		if (fx == 1 && last < ans)
			l = mm + 1;
		else
			r = mm - 1;
		last = ans;
	}
	cout << ans;
	return 0;
}