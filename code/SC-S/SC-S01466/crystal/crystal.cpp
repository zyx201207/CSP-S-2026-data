#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define req(i, r, l) for(int i = r; i >= l; i--)
#define pb push_back
#define int ll
inline int rd() {
	int res = 0, f = 1; char ch;
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) { res = (res << 3) + (res << 1) + (ch ^ 48); ch = getchar(); }
	return f * res;
}
using namespace std;
const int N = 5e5 + 8;
int n;
ll m;
ll a[N], s[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);	
	n = rd(); m = rd();
	rep(i, 1, n) a[i] = rd();
	sort(a + 1, a + n + 1);
	int ans = 0;
	rep(i, 1, n) {
		s[i] = s[i - 1] + a[i];
		int l = 1, r = i, pos = i;
		while(l <= r) { 
			int mid = (l + r) >> 1;
			if(a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) pos = mid, r = mid - 1;
			else l = mid + 1;
		}
//		rep(mid, 1, i) cout << a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) << " ";
//		cout << "\n";
		ans = max(ans, i - pos + 1);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/