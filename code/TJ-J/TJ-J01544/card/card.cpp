#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N];
int l = 1, r = 1;
int que[N];
int ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			for(int k = l; k <= r; k++) {
				if(que[k] == a[j]) {
					r = k - 1;
				}
			}
			que[r + 1] = a[j];
			r++;
		}
		for(int j = l; j <= r; j++) {
			for(int k = 1; k <= m; k++) {
				if(que[j] == k) {
					ans[k]++;
				}
			}
		}
		l = 1, r = 1;
		memset(que, 0, sizeof(que));
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
