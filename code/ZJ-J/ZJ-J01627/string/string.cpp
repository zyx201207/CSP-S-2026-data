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
const int N = 2e5 + 10;
int n, a[N], li[N], ans;
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	rp(i, n) {
		cin >> a[i] >> c[i];
	}
	int now = n;
	rp(i, n) {
		if(now == i) break;
		while(1) {
			if(a[now] >= a[i]) {
				if(c[i] != c[now]) {
					ans += a[i];
				}
				a[now] -= a[i];
				a[i] = 0;
				break;
			} else if(a[now] < a[i]) {
				if(c[i] != c[now]) {
					ans += a[now];
				}
				a[i] -= a[now];
				a[now] = 0;
				now--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

