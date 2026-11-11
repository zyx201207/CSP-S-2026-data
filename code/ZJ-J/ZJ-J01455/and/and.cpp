#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

const long long N = 2e5 + 10;
const long long LOG = 35;

long long n, m, a[N], id[N];
long long bit[N][LOG];

long long vis[N];

int main() {
	freopen("and.in", "r", stdin); 
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];

	for (long long i = 1; i <= n; i++) {
		long long len = 0;
		long long tmp = a[i];
		while (tmp > 0) {
			bit[i][len++] = tmp % 2;
			tmp /= 2;
		}
	}

//	for (long long i = 1; i <= n; i++) {
//		for (long long j = 0; j < LOG; j++) {
//	  		cout << bit[i][j];
//		}
//		cout << "\n";
//	}

	for (long long i = 1; i <= n; i++)
		vis[i] = 1;

	for (long long j = LOG - 1; j >= 0; j--) {
		long long cnt = 0;

		for (long long i = 1; i <= n; i++) {
			if (!vis[i]) continue;
			if (bit[i][j]) cnt++;
		}

		if (cnt < m) continue;

		if (cnt == m) {
			for (long long i = 1; i <= n; i++) {
				if (!vis[i]) continue;
				if (!bit[i][j]) vis[i] = 0;
			}
			break;
		}

		if (cnt > m) {
			for (long long i = 1; i <= n; i++) {
				if (!vis[i]) continue;
				if (!bit[i][j]) vis[i] = 0;
			}
		}
	}

	vector<long long> s;

	for (long long i = 1; i <= n; i++) {
		if (!vis[i]) continue;
		s.push_back(i);
	}

//	for (long long x : s) 
//		cout << x << " ";
//	cout << "\n";

	long long ans = -1LL;

	for (long long i = 0; i < m; i++) {
		ans = ans & a[s[i]];
	}

	cout << ans << "\n";

	return 0;
}

/*
5 2
0 1 2 3 4
*/