#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = k * 10 + (c - '0');
		c = getchar();
	}
	return k * f;
}

const int N = 2e6 + 5;

int c, T;
int n;
ll d;
ll p[N];
int num[N];

int cnt, step;
void dfs(int u, int v, int k) {
	for (int i = u; i <= v; ++ i) {
		if (i == v) {
			num[++ k] = v;
			int len = 0, s = 0;
			for (int i = 2; i <= num[k]; ++ i) {
				len += p[num[i]] - p[num[i - 1]];
				if (len > d) {
					s ++;
					len = p[num[i]] - p[num[i - 1]];
				}
			}
			if (s == step) cnt ++;
			if (s < step) {
				step = s;
				cnt = 1;
			}
			return ;
		}
		dfs(i + 1, v, k);
		num[++ k] = i;
		dfs(i + 1, v, k + 1);
	}
}

void solve() {
	n = read(), d = read();
	
	ll dif;
	bool flag;
	for (int i = 1; i <= n; ++ i) {
		p[i] = read();
		ll tmp;
		if (i >= 2) tmp = p[i] - p[i - 1];
		if (i == 2) dif = p[i] - p[i - 1];
		else if (dif != tmp) flag = 1;
	}
	
	if (n <= 9) {
		int ans = 0;	
		for (int i = 1; i <= n; ++ i) {
			for (int j = i + 3; j <= n; ++ j) {
				cnt = 0, step = 1e9;
				num[1] = i;
				dfs(i, j, 1);
				if (cnt == 2) ans ++;
			}
		} 
		printf("%d\n", ans);
	}
	
	/*if (flag == 0) {
		puts("Fuck CCf");
	}*/
	
}


int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	
	c = read(), T = read();
	while (T --) {
		solve();
	}
	
	return 0;
}
