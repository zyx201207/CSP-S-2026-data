#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[200005], dist[];
struct Station {
    int i, id, t;
};
vector<Station> line[505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    int T;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int last = 0;
        for (int j = 1; j <= k; j++) {
            int id, t; cin >> id >> t;
            T = t;
            line[last].push_back({i, id, t});
            line[id].push_back({i, last, line[last].t});
            last = id;
        }
    }
    cout << T * m - 1;
	return 0;
}
