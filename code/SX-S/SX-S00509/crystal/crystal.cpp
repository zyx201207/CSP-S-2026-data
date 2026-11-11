#include <bits/stdc++.h>
using namespace std;
template<typename T>
void read(T& x) {
	x = 0;
	bool neg = false;
	char ch = getchar();
	while (ch<'0' || ch>'9') {
		neg |= (ch=='-');
		ch = getchar();
	}
	while (ch>='0' && ch<='9') {
		x = (x<<3) + (x<<1) + (ch^48);
		ch = getchar();
	}
	if (neg)
		x = -x;
}
constexpr int N = 500007;
int n;
__int128 m;
__int128 a[N];
__int128 pre[N];
bool check(int l, int r) {
	return a[r]*(r-l+1)-(pre[r]-pre[l-1]) <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i-1] + a[i];
	int l = 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (!check(l, i))
			++l;
		ans = max(ans, i-l+1);
	}
	printf("%d\n", ans);
	return 0;
}
