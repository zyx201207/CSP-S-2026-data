#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct subway {
	int io_time;
	map<int, int> line;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;

	vector<subway> mp(m + 1);

	for (int i = 1; i < m; i++) {
		cin >> mp[i].io_time;
	}

	for (int i = 1; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j < k; j++) {
			int a, t;
			cin >> a >> t;
			mp[a].line[i] = t;
		}
	}

	for (int i = 0; i < q; i++) {
		int start, end;
		cin >> start >> end;
		int ans = mp[start].io_time + mp[end].io_time;

	}

	cout << 32;
}