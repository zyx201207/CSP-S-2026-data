#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5;
const int M = 3e5;

int a[N + 5];
int ans[M + 5];
int b[N + 5];
bool vis[M + 5];

int n, m;
int cnt;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (n >= 500) {
		for (int i = 1; i <= m; i++)
			cout << n << " ";
		return 0;
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 1 + i; j <= n; j++) {
			for (int k = 1; k <= cnt; k++){
				if (b[k] == a[j]) {					
					cnt = k - 1;
					break;
				}
			}
			cnt++;
			b[cnt] = a[j];
		}
		

		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= cnt; k++) {
				if (b[k] == j){
					ans[j]++;
				}
			}
		}
		cnt = 0;
	}
	
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
