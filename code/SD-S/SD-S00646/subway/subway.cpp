#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
#define fi first
#define se second 
using namespace std;
const int MAXN = 502, MAXM = 5e5+2; const ll INF = 2e18;
int c, n, m, d, q; ll ans, w[MAXN], k[MAXN];
pair<ll,ll> rd[MAXN][1002];
vector<pair<ll,ll>> link[MAXN];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string file = "subway";
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i){
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j){
			int nd, t; cin >> nd >> t;
			rd[i][j] = {nd, t};
			link[nd].push_back({i, t});
		}
	}
	while (q--){
		int x, y; cin >> x >> y;
		cout << "IDK\n";
	}
	return 0;
}
