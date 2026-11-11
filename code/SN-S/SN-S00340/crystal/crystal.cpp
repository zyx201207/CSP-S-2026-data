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

const int N = 5e5+10;
ll a[N], sum[N];
int ans = 0;
int n;
ll M;

void start() {
	cin >> n >> M;
	for (int i=1; i<=n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];
	for (int i=1; i<=n; ++i) {
		int now = 0;
		for (int k=(1<<__lg(i)); k; k>>=1) {
			if (now + k > i) continue;
			ll cost = a[i] * (now + k) - (sum[i] - sum[i - (now + k)]);
			if (cost <= M) now += k;
		}
		ans = max(ans, now);
	}	
	cout << ans << '\n';
}

bool MED;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string name = "crystal";
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
//	cerr << "-- " << (&MBE - &MED) / 1048576 << " Mib\n";
	int test_cnt = 1;
//	cin >> test_cnt;
	while (test_cnt--) start();
//	cerr << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}

