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
const int N = 510;
const int M = 5e5 + 10;
const int MM = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int c, n, m, d, q, w[M], k[N], dis[MM][MM];
vt<int> a[N], t[N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	rp(i, m) {
		cin >> w[i];
	}
	if(c <= 11) {
		memset(dis, 0x3f, sizeof dis);
		rp(i, n) {
			cin >> k[i];
			rp(j, k[i]) {
				int aa, bb;
				cin >> aa >> bb;
				a[i].pb(aa);
				t[i].pb(bb);
			}
			rp(j, k[i]) {
				rep(jj, j + 1, k[i]) {
					dis[a[i][j - 1]][a[i][jj - 1]] = min(t[i][j - 1] + t[i][jj - 1], dis[a[i][j - 1]][a[i][jj - 1]]);
					dis[a[i][jj - 1]][a[i][j - 1]] = min(t[i][j - 1] + t[i][jj - 1], dis[a[i][jj - 1]][a[i][j - 1]]);
				}
			}
		}
		rp(i, m) dis[i][i] = 0;
		rp(k, m) {
			rp(i, m) {
				rp(j, m) {
					if(dis[i][k] != INF && dis[j][k] != INF) {
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
		}
		rp(i, q) {
			int l, r;
			cin >> l >> r;
			cout << w[l] + w[r] + dis[l][r] << endl;
		}
		return 0;
	}
	return 0;
}
/*
*/

