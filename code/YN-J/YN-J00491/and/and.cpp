#include<bits/stdc++.h>
using namespace std;

bool MST;
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define N 200010
int n, m;
int a[N];
int p[N], top;
void solve_() {
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
	}
	per(k, 31, 0) {
		top = 0;
		rep(i, 1, n) {
			if ((1 << k)&a[i]) {
				p[++top] = i;
			}
		}
		if (top >= m) {
			rep(i, 1, top) {
				a[i] = a[p[i]];
			}
			n = top;
		}
	}
	int ans = a[1];
	rep(i, 1, m) {
		ans = (ans & a[i]);
	}
	cout << ans << "\n";
}
bool MED;
signed main() {
//	cerr << abs(&MST - &MED) / 1024 / 1024 << "MB\n";
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve_();
	return 0;
}
