#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

ll line[21][5000005] = {0};

struct Node {
	ll a = 0, t[21] = {0}; //a站厅 t站台
	ll line[21] = {false};
	bool Go = true;
} w[500005];

struct Q {
	ll a, b;
} q[100005];
/*
struct Line{
	bool Node[500005];//True则在Line[n]的n号线
	ll Tra[500005]={0};
}line[21];
*/
queue<ll>ser;

ll nowlinepoint(ll i, ll a) {
	for (ll j = 1; j <= 500000; j++) {

		if (line[i][j] == a)
			return j;
	}
}

void bfs(ll a, ll b, ll nowline, ll ans) {
	//前后换
	if (a == b) {
		cout << ans;
		return ;
	}

	for (ll i = 1; i <= 20; i++) {

		if (w[a].line[i]) {
			ll point = nowlinepoint(i, a);
			bfs(line[i][a + 1],b,nowline, ans);
		}

		if (w[a].line[i]) {
			ll point = nowlinepoint(i, a);
			bfs(line[i][a - 1],b,nowline, ans);
		}

		if (w[a].line[i]) {
			ll trasport = 0;

			for (ll j = 1; j <= 20; j++) {

				if (line[j][a])
					trasport = j;
				ans += w[j].t += w[i].t;
				bfs(a, b, j, ans);
			}
		}
	}

}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c, n, m, d, Q, ans = 0;
	cin >> c >> n >> m >> d >> Q;

	for (ll i = 1; i <= m; i++) {

		cin >> w[i].a;
	}

	ll x;
	ll node;

	for (ll i = 1; i <= n; i++) {

		cin >> x;

		for (ll j = 1; j <= x; j++) {

			cin >> node;
			cin >> w[node].t;
			w[node].line[n] = true;
			line [n][node]++;
		}
	}

	for (ll i = 1 ; i <= Q; i++) {

		ans = 0;
		cin >> q[i].a >> q[i].b;
		ans += w[q[i].a].a;
		cout << bfs(q[i].a, q[i].b, ans) << endl;
	}

	return 0;

}
