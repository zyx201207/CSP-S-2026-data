#include<iostream>
#include<string>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
char c[N];
namespace baoli {
	string s;
	void pre() {
		for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= a[i] ; ++j)
		s.push_back(c[i]);
	}
	void solve() {
		pre();
		int len = s.size();
		s = " " + s;
		int ans = 0;
		for (int i = 1 ; i <= len / 2 ; ++i)
		if (s[i] != s[len - i + 1]) ans++;
		cout << ans;
	}
}int f[N], g[N];
namespace MAYBE__zhengjie {
	void solve() {
		
		for (int i = 1 ; i <= n ; ++i) f[i] = f[i - 1] + a[i];
		for (int i = n ; i >= 1 ; --i) g[i] = g[i + 1] + a[i];
		long long i = 0, j = n + 1, ans = 0;
		int pre = 0, suf = 0, lastA = 0, lastB = 0;
		while (i <= j) {
			if (pre < suf) i++, pre += a[i];
			else if (suf < pre) j--, suf += a[j];
			else if (pre == suf) {
				i++, pre += a[i];
				j--, suf += a[j];
			}
			if (i >= j) break;
			if (c[i] == c[j]) continue;
			ans += (min(pre, suf) - max(g[j + 1], f[i - 1])) ;
		}
		cout << ans;
	}
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; ++i) {
		cin >> a[i] >> c[i];
	}
//	if (num <= 1e5) baoli::solve();
//	else {
		MAYBE__zhengjie::solve();
//	}
	return 0;
}


