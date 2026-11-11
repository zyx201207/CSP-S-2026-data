#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, res[M], lst[M];
vector<int>a;
vector<pair<int, int> > e[M];
int in[N], sum[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	a.push_back(0);
	for (int i = 1, t; i <= n; i++)
		cin >> t, a.push_back(t);
	reverse(a.begin() + 1, a.end());
	for (int i = 1; i <= n; i++) {
//		cout << a[i] << '\n';
		if (!lst[a[i]]) {
			e[i].push_back({i - 1, a[i]});
			in[i - 1]++;
		} else {
			e[i].push_back({lst[a[i]], 0});
			in[lst[a[i]]]++;
		}
		lst[a[i]] = i;
		sum[i] = 1;
	}
	queue<int>q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto i : e[u]) {
			int v = i.first, w = i.second;
			res[w] += sum[u];
			sum[v] += sum[u];
			in[v]--;
			if (in[v] == 0)
				q.push(v);
		}
	}
	for (int i = 1; i <= m; i++)
		cout << res[i] << ' ';
	return 0;
}