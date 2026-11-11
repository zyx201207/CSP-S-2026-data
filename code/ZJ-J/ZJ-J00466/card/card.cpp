#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 3e5 + 10, N = 5e5 + 10;
int cnt[M];
int a[N];
int n, m;
int jushu[M];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int st[n + 1];
	int chuxian[m + 1];
	for(int i = 1; i <= n; i++) {
		memset(st, 0, sizeof st);
		memset(chuxian, -1, sizeof chuxian);
		int r = 0;
		for(int j = i; j <= n; j++) {
			int p = 0;
			for(int k = 1; k <= r; k++) {
				if(st[k] == a[j]) {
					p = k;
					break;
				}
			}
			if(p != 0) {
				r = p;
			} else {
				r++;
				st[r] = a[j];
			}
		}
		for(int j = 1; j <= r; j++) {
			cnt[st[j]] += 1;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
