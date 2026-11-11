#define first x
#define second y
#include <iostream>
#include <map>
#include <vector>
#undef first
#undef second
#define NAME "subway"

using namespace std;
typedef long long ll;

namespace mian {

int c, n, m, d, q;
ll ws[500008];
int ks[504];
vector<int> as[504];
vector<ll> ts[504];
map<int, ll> mgraph[500008];
vector<int> ngraph[504];
ll floyd[504][504];

void main() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		cin >> ws[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> ks[i];
		as[i].resize(ks[i]);
		ts[i].resize(ks[i]);
		for (int j = 0; j < ks[i]; j++) {
			cin >> as[i][j] >> ts[i][j]; as[i][j]--;
//			cout << ts[i][j] << " T\n";
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ks[i]; j++) {
			mgraph[as[i][j]].insert({i, ts[i][j]});
			ngraph[i].push_back(as[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			floyd[i][j] = 0x3fefffffffffff3f;
		}
		floyd[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (pair<int, ll> j : mgraph[i]) {
			for (pair<int, ll> k : mgraph[i]) {
				floyd[j.x][k.x] = min(floyd[j.x][k.x], j.y + k.y);
				floyd[k.x][j.x] = min(floyd[k.x][j.x], j.y + k.y);
			}
		}
	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << floyd[i][j] << " ";
//		} cout << "\n";
//	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << floyd[i][j] << " ";
//		} cout << "\n";
//	}
	
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v; u--; v--;
		ll ans = 0x3fefffffffffff3f;
		for (pair<int, ll> j : mgraph[u]) {
			for (pair<int, ll> k : mgraph[v]) {
				ans = min(ans, j.y + k.y + floyd[j.x][k.x]);
			}
		}
		cout << ans + ws[u] + ws[v] << "\n";
	}
}

}

int main() {
	freopen(NAME ".in", "r", stdin);
	freopen(NAME ".out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	mian::main();
	cout << flush;

	return 0;
}
