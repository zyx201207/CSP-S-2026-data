#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;

struct node {
	int kz;
	vector<pair<int, int>> v;
} s[500005];

struct node1 {
	vector<int> vv;
} t[505];
bool vis[500005];

void dfs(int x, int y) {
	int cnt = 0;
	if (x == y) {
		cout << cnt;
		return;
	}
	cnt += s[x].kz;
	for (int i = 0; i < s[x].v.size(); i++) {
		for (int j = 0; j < t[s[x].v[j].first].size(); i++) {
			cnt += s[x].v[j].second;
			x = t[s[x].v[j].first].vv[j];
			vis[x] = 1;
			dfs(x, y);
			vis[x] = 0;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int A,B;
	cin >> c >> n >> m >> d >> q; //n_路数，m_站数，d_最多被几条穿过
	for (int i = 1; i <= m; i++)
		cin >> s[i].kz;
	for (int i = 1; i <= n; i++) {
		int zd;
		cin >> zd;
		while (zd--) {
			int a, b;
			cin >> a >> b;
			A=a;B=b;
			s[a].v.push_back({i, b});
			vv[i].push_back(a);
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		dfs(x, y);
	}
	cout<<1111;
	return 0;
}