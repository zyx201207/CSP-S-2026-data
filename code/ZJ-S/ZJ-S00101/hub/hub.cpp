#include <bits/stdc++.h>
using namespace std;

const int N = 2000010;
int C;
int h[N], e[N * 2], ne[N * 2], idx;

void addedge(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> d(n + 5);
	idx = 0;
	for (int i = 1; i <= n; i ++ ) h[i] = -1;
	for (int i = 1; i < n; i ++ ) {
		int a, b;
		scanf("%d%d", &a, &b);
		addedge(a, b), addedge(b, a);
		d[a] ++ , d[b] ++ ;
	}
	if (n == 2) {
		puts("0");
		return;
	}
		int Ans = 1e9;
		for (int i = 0; i <= idx; i += 2) {
			int ban = i;
			vector<int> dd(n + 5);
			dd = d;
			dd[e[ban]] -- , dd[e[ban ^ 1]] -- ;
			queue<int> q, q2;
			for (int j = 1; j <= n; j ++ )
				if (dd[j] == 1)
					q.push(j);
			int ans = 0, cnt = n;
			while (cnt > k) {
				ans ++ ;
				//cout << cnt << endl;
				while (q.size()) {
					int t = q.front();
					q.pop();
					cnt -- ;
					if (dd[t] == 0) cnt += 1;
					for (int j = h[t]; ~j; j = ne[j]) {
						if (j == ban || j == (ban ^ 1))
							continue;
						if (-- dd[e[j]] == 1)
							q2.push(e[j]);
					}
				}
				swap(q, q2);
			}
			Ans = min(Ans, ans);
		}
		printf("%d\n", Ans);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T;
	scanf("%d%d", &C, &T);
	while (T -- ) solve();
	return 0;
}
