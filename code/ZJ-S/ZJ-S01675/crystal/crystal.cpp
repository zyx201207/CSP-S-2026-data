#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#define rp(i, a) for(int i = 1; i <= a; i++)
#define rd(i, a) for(int i = 0; i < a; i++)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, a, b) for(int i = b; i >= a; i--)
#define vt vector
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 5e5 + 10;
int n, m, a[N], b[N], c[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rp(i, n) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	rep(i, 2, n) {
		b[i] = a[i] - a[i - 1];
		c[i] = c[i - 1] + b[i];
	}
	int qian = 1, hou = 1, now = 0, ans = 0;
	rep(i, 2, n) {
		hou++;
		now += b[i] * (hou - qian);
		while(hou > qian && now > m) {
			qian++;
			now -= c[hou] - c[qian - 1];
		}
		ans = max(ans, hou - qian + 1);
	}
	cout << ans << endl;
	return 0;
}
/*
5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
