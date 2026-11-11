#include <iostream>
#include <fstream>

using namespace std;
using ll = long long;

ifstream fin("in");
ofstream fout("out");

const int kN = 2e6 + 1;

int T, c, n, nxt[kN], b[kN][2];
ll d, ans, a[kN];

int main() {
	fin.tie(0)->sync_with_stdio(0);
	fin >> c >> T;
	while (T--) {
		fin >> n >> d, ans = 0;
		for (int i = 1; i <= n; i++)
			fin >> a[i], b[i][0] = b[i][1] = 0;
		for (int i = 1, j = i; i <= n; i++) {
			for (; j <= n && a[j] - a[i] <= d; j++);
			nxt[i] = j - 1;
		}
		auto Check = [](int x) {
			if (nxt[x] >= x + 3 && nxt[nxt[x]] == nxt[nxt[x] - 2] && nxt[nxt[x]] != nxt[x])
				return 3;
			if (nxt[x] >= x + 2 && nxt[nxt[x]] == nxt[nxt[x] - 1] && nxt[nxt[x]] != nxt[x])
				return 2;
			return 1;
		};
		// for (int i = 1; i <= n; i++)
		// 	cerr << nxt[i] << ' ';
		// cerr << '\n';
		for (int i = 1; i <= n; i++) {
			b[i][0]++, ans += 1ll * b[i][1] * (nxt[i] - i);
			if (nxt[i] >= i + 1) {
				if (Check(i) == 2) {
					if (Check(nxt[i]) >= 2)
						ans += 1ll * b[i][0] * (nxt[nxt[nxt[i]]] - nxt[nxt[i]] - 1);
					else
						b[nxt[nxt[i]]][1] += b[i][0];
				} else if (Check(i) == 1)
					b[nxt[i]][0] += b[i][0], b[nxt[i]][1] += b[i][1];
			}
			cerr << Check(i) << '\n';
			if (nxt[i] >= i + 2)
				ans += 1ll * b[i][0] * (nxt[nxt[i] - 1] - nxt[nxt[i] - 2]);
		}
		fout << ans << '\n';
	}
	return 0;
}
/*
10 3
0 3 6 7 8 9 10 13 16 19
0 1
6 12
-10 -6 -2 2 6 10

*/