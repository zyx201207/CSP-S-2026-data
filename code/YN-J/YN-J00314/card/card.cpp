#include <bits/stdc++.h>
using namespace std;
int n, m, tot, to[300005], a[500005], la[300005], cnt[300005], ind[300005];

struct uv {
	int to, nt;
} e[300005];

void bfs() {
	queue<int>q;

	for (int i = 1; i <= m; i++) {

		if (ind[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front(), v = to[u];
		q.pop();
		cnt[v] += cnt[u];
		ind[v]--;

		if (ind[v] == 0) {
			q.push(v);
		}
	}

	return;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	freopen("111.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		cnt[a[i]]++;
		la[a[i]] = i;
	}

	for (int i = 1; i <= m; i++) {

		int u = i, v = a[la[i] + 1];
		to[u] = v;
		ind[v]++;
	}

	bfs();

//	for (int i = 1; i <= m; i++) {
//
//		cout << to[i] << " ";
//	}
//
//	cout << '\n';

	for (int i = 1; i <= m; i++) {

		cout << cnt[i] << " ";

	}

	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/