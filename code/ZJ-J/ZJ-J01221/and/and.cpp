#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2e5 + 7;
int n, m;
LL cnt[50], p[50];
int lowbit(int x) {
	return x & -x;
}
int get(int x) {
	int res = x;
	while (x) { 
		int l = lowbit(x);
		int num = 0;
		while (l) {
			l /= 2;
			++num; 
		}
		if (cnt[num] < m) {
			res -= lowbit(x);
		}
		x -= lowbit(x);
	}
	return res;
}
void count(int x) {
	while (x) {
		int res = 0;
		int l = lowbit(x);
		while (l) {
			l /= 2;
			++res;
		}
		++cnt[res];
		x -= lowbit(x);
	}
}
struct Node {
	int a, b;
} a[N];
LL ans = 0;
bool cmp(Node x, Node y) {
	if (x.b != y.b)
		return x.b > y.b;
	return x.a > y.a;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].a;
	}
	for (int i = 1; i <= n; ++i) {
		count(a[i].a);
	}
	for (int i = 1; i <= n; ++i) {
		a[i].b = get(a[i].a);
	}
	sort (a + 1, a + n + 1, cmp); 
	ans = a[1].b;
	for (int i = 2; i <= m; ++i) {
		ans &= a[i].b;
	}
	cout << ans;
	return 0;
}
