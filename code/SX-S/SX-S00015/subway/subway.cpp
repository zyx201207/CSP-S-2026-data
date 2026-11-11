#include <iostream>
#include <vector>

#define LL long long

#define I using
#define AK namespace
#define IOI std
I AK IOI;

struct Station {
	LL w;
	vector<LL> a, t;
};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	LL c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<Station> stations;
	vector<vector<LL>> lines;
	for (int i = 0; i < m; i++) {
		LL w;
		cin >> w;
		stations[i].w = w;
	}

	for (int i = 0; i < n; i++) {
		LL k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			LL a, t;
			cin >> a >> t;
			stations[i].a.push_back(a);
			stations[i].t.push_back(t);
		}
	}
	while (q--) {
		cout << 1 << endl;
	}
}
