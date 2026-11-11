#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
#define LL long long

int p[maxn][40];
bool flag[maxn];
LL pow2[40];

int n, m;
LL ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1, a; i <= n; i ++) {
		cin >> a;
		for (int w = 1; a; a >>= 1, w ++) {
			p[i][w] = a & 1;
		}
	}
	
	pow2[0] = 1;
	for (int i = 1; i < 40; i ++) {
		pow2[i] = pow2[i - 1] * 2;
	}
	
	for (int i = 32; i >= 1; i --) {
		int cnt = 0;
		for (int j = 1; j <= n; j ++) {
			if (!flag[j] && p[j][i]) cnt ++;
		}
		if (cnt >= m) {
			ans += pow2[i - 1];
			for (int j = 1; j <= n; j ++) {
				if (!p[j][i]) flag[j] = 1;
			}
		}
	}
	
	return cout << ans, 0;
}

