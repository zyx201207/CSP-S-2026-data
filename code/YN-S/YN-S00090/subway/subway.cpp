#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[100001];
int sta[100001];
long long an[100001];
bool flag[10001][10001];
int Next[10001][10001];
int start;

struct node {
	int st;
	int time;
} t[10001][10001];

void f(int s, long long ans, int end, int now) {
	if (s == end) {
		ans += t[now][s].time;
		an[q] = min(an[q], ans);
		return;
	} else {
		for (int i = 1; i <= n; i++) {
			if (flag[s][i] == true) {
				if (i == now) {
					if (s == start)
						ans += t[now][s].time;
					f(t[i][s + 1].st, ans, end, now);
				} else {
					if (s == start)
						ans -= t[now][s].time;
					f(t[i][Next[i][s]].st, ans + t[now][s].time + t[i][s].time, end, i);
				}
			}
		}
		return;
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> sta[i];
		for (int j = 1; j <= sta[i]; j++) {
			cin >> t[i][j].st >> t[i][j].time;
			flag[t[i][j].st][i] = true;
			Next[i][t[i][j].st] = j + 1;
		}
	}
	int p = q;
	while (q > 0) {
		an[q] = 100000001;
		int end;
		cin >> start >> end;
		int now;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= sta[i]; j++) {
				if (t[i][j].st == start) {
					now = i;
					break;
				}
			}
		}
		f(start, 0, end, now);
		an[q] += (w[now] + w[end]);
		q--;
	}
	for (int i = p; i >= 1; i--) {
		cout << an[i] << endl;
	}
	return 0;
}