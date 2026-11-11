#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
const int N = 5e5 + 5;
int n, m, a[N];
int s[N], ans;

//求一个值x使a的一个子集b的长度len最大并满足  ∑b + m = len * x

bool check(int mid, int p, int x) {
	int b = s[p] - s[mid - 1];
	return b + m >= (p - mid + 1) * x;
}

int f(int x) {
	int p = upper_bound(a + 1, a + n + 1, x) - a - 1;
	int l = 1, r = p;
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid, p, x)) r = mid;
		else l = mid + 1;
	}
	return p - l + 1;
}

void solve() {
	cin>>n>>m;
	int mx = 0, dis, flag = 1;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		mx = max(mx, a[i]);
	}

	sort(a + 1, a + n + 1);

	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		if(i == 1) continue;
		else if(i == 2) dis = a[i] - a[i - 1];
		else if(a[i] - a[i - 1] != dis) flag = 0;
	}

	if(flag) {
		cout<<f(a[n]);
	} else {
		for(int i = mx; i; i--) {
			ans = max(ans, f(i));
		}

		cout<<ans;
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
