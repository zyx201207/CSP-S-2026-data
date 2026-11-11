#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long ma = -1, apt, aaa;
long long a[200010], s[200010];
long long vis[200010], xxx[200010];
void dfs(long long x, long long id) {
	if(x == m+1) {
		long long xxxx = a[xxx[1]];
		for(long long i = 2; i <= m; i++) xxxx&=a[xxx[i]];
		aaa = max(aaa, xxxx);
		return;
	}
	for(long long i = id + 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			xxx[x] = i;
			dfs(x + 1, i);
			vis[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	ma = a[1];
	apt = a[1];
	s[1] = a[1];
	for(long long i = 2; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] & a[i];
		ma = max(ma, a[i]);
		apt &= a[i];
	}
	if(m == 1) {
		cout << ma << endl;
		return 0;
	}
	if(m == n) {
		cout << apt << endl;
		return 0;
	}
	if(m == n - 1) {
		for(long long i = 1; i <= n; i++) 
			aaa = max(aaa, apt&-a[i]);
		cout << aaa << endl;
		return 0;
	}
	if(m == 2) {
		for(long long i = 1; i <= n; i++) 
			for(long long j = i + 1; j <= n; j++) 
				aaa = max(aaa, a[i] & a[j]);
		cout << aaa << endl;
		return 0;
	}
	dfs(1, 0);
	cout << aaa << endl;
	return 0;
}