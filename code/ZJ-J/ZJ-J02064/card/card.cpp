#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m;
int a[N];
int cnt[M];
int r[M];
int num[M];
int ans[M];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int flagA = 1;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] < a[i-1]) {
			flagA = 0;
		}
	}
	if(flagA) {
		for(int i = 1; i <= n; i++) {
			ans[a[i]] = i;
		}
		for(int i = 1; i <= m; i++) {
			cout << ans[i] << " ";
		}
		return 0;
	}
	int p = 0;
	while(p <= n) {
		p++;
		memset(cnt, 0, sizeof(cnt));
		memset(r, 0, sizeof(r));
		memset(num, 0, sizeof(num));
		int now = 0;
		for(int i = p; i <= n; i ++) {
			if(cnt[a[i]] == 1) {
				int now1=now;
				for(int j = r[a[i]]; j <= now1; j ++) {
					cnt[num[j]] = 0;
					now --;
				}
			}
			cnt[a[i]] = 1;
			num[++ now] = a[i];
			r[a[i]] = now;
		}
		for(int i = 1; i <= m; i ++) {
			if(cnt[i] == 1) {
				ans[i] ++;
			}
		}
	}
	for(int i = 1; i <= m; i ++) {
		cout << ans[i] << " ";
	}
}