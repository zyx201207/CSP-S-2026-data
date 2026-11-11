#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long INF = (1LL << 31) - 1;
int n, m;
long long a[N]; 
bool vis[N];
long long ans;
int logg[50];
void dfs(int k, long long res) {
	if(k > m) {
		ans = max(ans, res);
	}
	for(int i = 1;i <= n;i++) {
		if(!vis[i]) {
			vis[i] = true;
			dfs(k + 1, res & a[i]);
			vis[i] = false;
		}
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	long long maxn = 0;
	long long sp = INF;
	bool spA = true, spB = true;
	long long minn = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		sp &= a[i];
		if((1LL << ((long long)log2(a[i]) + 1)) - 1 != a[i]) spA = false;
		if(a[i] != i - 1) spB = false;
	}
	if(spA) {
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
	}
	else if(spB && (1LL << (long long)log2(n)) == n) {
		logg[1] = logg[2] = 1;
		for(int i = 3;i <= (int)log2(n);i++) {
			logg[i] = (1 << (i - 1)) - 1; 
		}
		int i = (int)log2(n), sum = 0;
		while(i >= 1 && sum < m) {
			sum += logg[i];
			i--;
		}
		cout << a[n - m - ((int)log2(n) - i - 1) + 1];
	}
	else if(m == 1) {
		cout << maxn;
	}
	else if(m == n) {
		cout << sp;
	}
	else if(m == 2) {
		long long res = 0;
		for(int i = 1;i < n;i++) {
			for(int j = i + 1;j <= n;j++) {
				res = max(res, a[i] & a[j]);
			}
		}
		cout << res;
	}
	else {
		dfs(1, INF);
		cout << ans;
	}
	return 0;
}
