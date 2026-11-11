#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
const int N = 5e5+10;
ll a[N];
ll p[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	rep(i, 1, n) p[i] = p[i-1] + a[i];
	int ans = 1;	
	rep(r, 1, n) {
		int L = 1, R = r;
		while (L<R) {
//			cout <<L << ' ' << R << '\n';
			int mid = L+R>>1;
			if (1ll*a[r]*(r-mid)-p[r-1]+p[mid-1]<=m) R = mid;
			else L = mid+1;
		}
//		cout << L << '\n';
		ans = max(ans, r-L+1);
	}
	cout <<ans;
}
