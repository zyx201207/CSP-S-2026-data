/*
Author: fortyqin
*/
#include <bits/stdc++.h>
//#define int long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using LLL = __int128;
using uLLL = unsigned __int128;
bool MBE;

int cc;

namespace sub1 {

const int N = 5005;
int nxt[N];
int pre[N];
int dis[N];
int f[N];
ll X[N];
int n;
ll D;

void solve() {
	cin >> n >> D;
	for (int i=1; i<=n; ++i) cin >> X[i];
	for (int i=1; i<=n; ++i) {
		auto p = upper_bound(X+i, X+n+1, X[i] + D) - X - 1;
		nxt[i] = (int)p;
	}
	for (int i=1; i<=n; ++i) {
		auto p = lower_bound(X+1, X+i+1, X[i] - D) - X;
		pre[i] = (int)p;
	}
	
//	for (int i=1; i<=n; ++i) {
//		cerr << i << " -> " << nxt[i] << ' ' << pre[i] << '\n'; 
//	}
	
	int ans = 0;
	for (int s=1; s<n; ++s) {
		int t = s;
		while (t < n && nxt[t] != t) ++t;
		dis[s] = 0;
		int last = s;
		while (last < t) {
			int to = nxt[last];
			int tmp = dis[last] + 1;
			for (int i=last+1; i<=to; ++i) dis[i] = tmp;
			last = to;
		}
		f[s-1] = 0;
		f[s] = 1;
		int key = s; 
		for (int i=s+1; i<=t; ++i) {
			int L = max(s, pre[i]);
			int R;
			if (dis[i] == dis[i-1]) R = key;
			else R = key = i - 1;
			if (L <= R) f[i] = f[R] - f[L - 1];
			else f[i] = 0;
			if (f[i] >= 3) f[i] = 3;
			if (f[i] == 2) ++ans;
			f[i] += f[i-1];
		}
	}
	cout << ans << '\n';
}

}

void start() {
	if (cc <= 10) {
		sub1::solve();
	}
}

bool MED;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string name = "migrate";
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
//	cerr << "-- " << (&MBE - &MED) / 1048576 << " Mib\n";
	int test_cnt = 1;
	cin >> cc;
	cin >> test_cnt;
	while (test_cnt--) start();
//	cerr << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}

