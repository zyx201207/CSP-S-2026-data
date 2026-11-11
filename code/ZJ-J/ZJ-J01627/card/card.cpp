#include<bits/stdc++.h>
//#define int long long
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
int n, m, t[N], ans[N], a[N], flag = 1, pos[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rp(i, n) {
		cin >> a[i];
		pos[a[i]] = pos[a[i]] == 0 ? a[i] : pos[a[i]];
		if(a[i] < a[i - 1]) flag = 0;
	}
	if(flag) {
		rp(i, m) {
			cout << n - pos[i] + 1 << " ";
		}
		return 0;
	}
	rp(i, n) {
		int tot = 0;
		int stk[N];
		rp(j, m) t[j] = 0;
		rep(j, i, n) {
			if(t[a[j]]) {
				while(1) {
					if(stk[tot] == a[j]) break;
					tot--;
					t[stk[tot + 1]]--;
				}
			} else {
				stk[++tot] = a[j];
				t[a[j]]++;
			}
		}
		rp(j, m) ans[j] += t[j];
	}
	rp(i, m) {
		cout << ans[i];
		if(i != m) cout << " ";
	}
	return 0;
}
/*

*/

