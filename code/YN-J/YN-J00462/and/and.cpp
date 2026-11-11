#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, maxn = 0;
int a[200005];

int abool(int x) {
	int sz[20], i = 1, bo = 0;

	while (x > 0) {
		sz[i] = x % 2;
		x = x / 2;
		i++;
	}

	for (int j = i - 1; j > 0; j--) {

		bo = bo * 10;
		bo += sz[j];
		sz[j] = 0;
	}

	return bo;
}

int bbool(int x) {
	int po = 0, t = 0;

	while (x > 0) {
		t += x % 10 * pow( 2, po );
		x = x / 10;
		po++;
	}

	return t;
}

int aand(int z, int y) {
	int lsz[20], k = 1, ao = 0;

	while (z > 0 || y > 0) {
		lsz[k] = abs(z % 10 + y % 10 - 1);
		z = z / 10;
		y = y / 10;
		k++;
	}

	for (int j = k - 1; j > 0; j--) {

		ao = ao * 10;
		ao += lsz[j];
		lsz[j] = 0;
	}

	return ao;
}

void dfs(int dep, int cnt, int cut, int flag) {
	if (dep >= n) {
		return ;
	}

	if (cut == m) {
		maxn = max(maxn, cnt);
		return ;
	} else {
		if (cnt == 0 && flag == 0) {
			dfs(dep + 1, 0, cut, 0);
			dfs(dep + 1, a[dep], cut + 1, 1);
		} else {
			dfs(dep + 1, cnt, cut, 1);
			dfs(dep + 1, aand(cnt, a[dep]), cut + 1, 1);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		a[i] = abool(a[i]);
	}

	dfs(1, 0, 0, 0);
	cout << bbool(maxn);

	return 0;
}