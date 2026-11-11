#include <bits/stdc++.h>
using namespace std;

const int N = 2000010;
long long x[N], L;

void qr(long long &x) {
	x = 0;
	int f = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
	x = f ? -x : x;
}

void qr(int &x) {
	x = 0;
	int f = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
	x = f ? -x : x;
}

void tackle(int X) {
	int n;
	long long d;
	qr(n); qr(d);
	//if (X == 3) cout << n << ' ' << d << endl;
	vector<int> rf(n + 5), lf(n + 5), rs(n + 5), ls(n + 5), pre(n + 5), suf(n + 5); 
	vector<int> q;
	for (int i = 1; i <= n; i ++ ) {
		qr(x[i]);
		//if (X == 3) cout << x[i] << ' ';
	}
	for (int i = 1, j = 1; i <= n; i ++ ) {
		while (j < n && x[j + 1] <= x[i] + d) j ++ ;
		rf[i] = j;
		if (rf[i] != i) ls[rf[i]] ++ ;
	}
	for (int i = n, j = n; i >= 1; i -- ) {
		while (j > 1 && x[j - 1] >= x[i] - d) j -- ;
		lf[i] = j;
		if (lf[i] != i) rs[lf[i]] ++ ;
	}
	int cnt = 0;
	vector<int> vis(n + 5, 0), id(n + 5);
	for (int i = 1; i <= n; i ++ ) {
		if (vis[i]) continue;
		vis[i] = true;
		q.clear();
		id[i] = ++cnt;
		int j = i;
		while (rf[j] != j && lf[rf[j]] == j) {
			j = rf[j];
			vis[j] = true;
			id[j] = cnt;
			q.push_back(j);
		}
		int sum = 0;
		for (int j = 0; j < q.size(); j ++ ) {
			sum += ls[q[j]];
			pre[q[j]] = sum;
		}
		sum = 0;
		for (int j = (int)q.size() - 1; j >= 0; j -- ) {
			sum += rs[q[j]];
			suf[q[j]] = sum;
		}
	}
	long long ans = 0;
	for (int i = 1; i < n; i ++ ) {
		if (id[i] == id[i + 1]) continue;
		if (x[i + 1] - x[i] > d) continue;
		if (lf[i + 1] == i || rf[i] == i + 1) continue;
		ans += 1ll * (ls[i + 1] + (lf[i] == lf[i + 1] && rf[lf[i + 1]] == i + 1) * pre[lf[i + 1]]) * (rs[i] + (rf[i] == rf[i + 1] && lf[rf[i]] == i) * suf[rf[i]]);
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int cc, T;
	qr(cc); qr(T);
	for (int i = 1; i <= T; i ++ ) tackle(i);
	return 0;
}
