#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define de second

using namespace std;

const int N = 16 + 10;

int h[N];
int n, m;
int maxx = 0;

void fn(int x) {
	int mx = m;
	int mm = 0;
	int i = 0, j = 0;
	while (mx >= 0) {
		if ((h[x] - h[x - i]) <= (h[x + j] - h[x])) {
			i++;
			if (mx >= (h[x] - h[x - i])) {
				mm++;
				mx -= (h[x] - h[x - i]);
			} else {
				maxx = max(mm, maxx);
				return ;
			}
		} else {
			j++;
			if (mx >= (h[x + j] - h[x])) {
				mm++;
				mx -= (h[x + j] - h[x]);
			} else {
				maxx = max(mm, maxx);
				return ;
			}
		}
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	sort(h + 1, h + n + 1);
	h[0] = -1e18;
	h[n + 1] = 1e18;
	for (int i = 1; i <= n; i++) {
		fn(i);
	}
	cout << maxx + 1 << endl;
	return 0;
}