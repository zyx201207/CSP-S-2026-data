#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], k, a[500005], t[500005], cnt[500005] = {}, x, y;

bool sp[500005] = {};

struct sub {
	int to = 0, time = 0;
};
struct sub s[500005][400];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++)
			cin >> a[j] >> t[j];
		for (int j = 0; j < k; j++) {
			for (int u = 0; u < k; u++) {
				if (j != u) {
					cnt[j]++;
					s[a[j]][cnt[j]].to = a[u];
					s[a[j]][cnt[j]].time = t[j] + t[u];
				}
			}
		}
	}
	int way[1 >> 31];
	unsigned long long temp[500005] = {};
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		int p = x, head = -1, tail = 0;
		way[0] = x;
		while (head != tail) {
			head++;
			p = way[head];
			if (p == y)
				continue;
			for (int i = 0; i < cnt[p]; i++) {
				int next = s[p][i].to;
				if (sp[next]) {
					if (temp[next] <= temp[p] + s[p][i].time) {
						continue;
					} else {
						temp[next] = temp[p] + s[p][i].time;
						way[++tail] = next;
					}
				} else {
					sp[next] = 1;
					temp[next] = temp[p] + s[p][i].time;
					way[++tail] = next;
				}
			}
		}
		cout << temp[y] + w[x] + w[y] << endl;
	}
	return 0;
}