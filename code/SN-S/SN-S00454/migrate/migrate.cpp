//SN-S00454  杨建傲措  陕西省西安爱知中学
#include <bits/stdc++.h>

using namespace std;

int c, t, n, d, a[5005], ans;

struct node {
	int m, ans;
} p[5005][5005];

void bfs(int o) {
	queue <int> q;
	q.push(o);
	int t = 0;
	while(!q.empty()) {
		t++;
		int x = q.front(); q.pop();
		for(int i = x; x <= n; i++) {
			if(a[i] - a[x] > d) break;
			if(p[o][i].m < t) {
				p[o][i].m = t;
				p[o][i].ans = 0;
			} else p[o][i].ans++;
			q.push(i);
		}
	}
	for(int i = o; i <= n; i++) {
		if(p[o][i].ans == 2) ans++;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) bfs(i);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
