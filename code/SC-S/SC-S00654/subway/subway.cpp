////现在应该在老师的屏幕上了，屏幕前的家人们们觉得我会被鞭吗
//#include <bits/stdc++.h>不写了破防了
//using namespace std;不写了破防了
//typedef pair<int, int> pii;
//int c, n, m, d, q, sp[100005], dj[100005], x[100005], y[100005];不写了破防了
//bool f[100005];不写了破防了
//vector<pii> g[100005];不写了破防了
//int djsk(int start, int needn) {不写了破防了
//	memset(dj, 0x3f, sizeof dj);不写了破防了
//	memset(f, 0, sizeof f);不写了破防了
//	dj[start] = 0;不写了破防了
//	priority_queue<pii, vector<pii>, greater<pii>> h;不写了破防了
//	h.push({0, start});不写了破防了
//	while (!h.empty()) {不写了破防了
//		pii t = h.top();不写了破防了
//		h.pop();不写了破防了
//		int v = t.second;不写了破防了
//		if (f[v])continue;不写了破防了
//		f[v] = 1;不写了破防了
//		for (int i = 0; i < (int)g[v].size(); i++) {不写了破防了
//			int j = g[v][i].first, w = g[v][i].second;不写了破防了
//			if (dj[j] > dj[v] + w) {不写了破防了
//				dj[j] = dj[v] + w;不写了破防了
//				h.push({dj[v], w});不写了破防了
//				break;不写了破防了
//			}不写了破防了
//		}不写了破防了
//	}不写了破防了
//	return dj[needn];不写了破防了
//}不写了破防了
//int main() {不写了破防了
//	freopen("subway.in", "r", stdin);不写了破防了
//	freopen("subway.out", "w", stdout);不写了破防了
//	cin >> c >> n >> m >> d >> q;不写了破防了
//	for (int i = 1; i <= m; i++) {不写了破防了
//		cin >> sp[i];不写了破防了
//	}不写了破防了
//	//。。。。。。。。。。
//	for (int i = 1; i <= q; i++) {不写了破防了
//		int x, y;不写了破防了
//		cin >> x >> y;不写了破防了
//		cout << djsk(x, y) + sp[x] + sp[y] << endl;
//	}不写了破防了
//	return 0;不写了破防了
//}不写了破防了
