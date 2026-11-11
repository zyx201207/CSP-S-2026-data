#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
long long w[500010];

long long k[510];
long long temp;
vector<int> a[510];
vector<int> t[510];

long long x, y;

long long aprc[510][30][5], ans;

void bfs() {
	queue<long long> q1, q2, q3;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &k[i]);
		a[i].push_back(-1);
		t[i].push_back(-1);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%lld", &temp);
			aprc[temp][++aprc[temp][0][0]][1] = i;
			aprc[temp][aprc[temp][0][0]][2] = j;
			a[i].push_back(temp);
			scanf("%lld", &temp);
			t[i].push_back(temp);
		}
	}
	for (int r = 1; r <= q; r++) {
		scanf("%lld%lld", &x, &y);
		ans = LLONG_MIN;
		bfs();
	}
	return 0;
}