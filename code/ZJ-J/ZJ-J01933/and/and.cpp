#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 0;
const long long N = 2e5 + 5;
long long a[N];
long long t[4] = {0, 0, 0, 0};
bitset<N>vis;
void dfs(long long cnt,long long num) {
	if (cnt == m) {
		ans = max(ans, num);
		return;
	}
	for (long long i = 1;i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(cnt + 1, (long long)num & a[i]);
			vis[i] = false;
		}
	}
	return;
}
bool check(long long x) {
	while (x%2==0) x/=2;
	if (x == 1) return true;
	return false;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m; 
	long long mx = -1, smand = LLONG_MAX; 
	bool flagB = true, flagA = true;
	for (long long i = 1;i <= n; i++) {
		cin >> a[i];
		if (a[i]!=i-1)flagB = false;
		if (flagA&&!check(a[i] + 1)) flagA = false;
		if (a[i] == 1) t[1]++;
		if (a[i] == 2) t[2]++;
		if (a[i] == 3) t[3]++;
		mx = max(mx, a[i]);
		smand = smand & a[i];
	}
	if (m == 1) {
		cout << mx;
		return 0;
	}
	if (m == n) {
		cout << smand;
		return 0;
	}
	if (m == 2) {
		long long ansm2 = -1;
		for (int i = 1;i <= n; i++) 
			for (int j = 1;j <= n; j++) 
				if (i != j) ansm2 = max(ansm2, a[i] & a[j]);
		cout << ansm2;
		return 0;
	}
	if (mx < 4) {
		if (t[3] >= m) cout << 3;
		else if (t[2] + t[3] >= m) cout << 2;
		else if (t[3] + t[1] >= m) cout << 1;
		else cout << 0;
		return 0;
	}
	if (flagA) {
		sort(a+1, a+n+1);
		cout << a[n - m + 1];
		return 0;
	}
	if (flagB) {
		long long ansB = LLONG_MAX;
		for (int i = n;i >= n-m+1;i--) 
			ansB=ansB&a[i];
		cout << ansB;
		return 0;
	}
	if (m == n - 1) {
		long long mn[N];
		for (int i = 1;i < N; i++) 
			mn[i] = LLONG_MAX;
		for (int i = 1;i <= n;i++) 
			for (int j = 1;j <= n ;j++) 
				if (i != j) mn[i] = mn[i] & a[j];
		long long ansmn = -1;
		for (int i = 1;i <= n ;i++) 
			ansmn = max(ansmn, mn[i]);
		cout << ansmn;
		return 0;
	}
	dfs(0, LLONG_MAX);
	cout << ans;
	return 0;
}