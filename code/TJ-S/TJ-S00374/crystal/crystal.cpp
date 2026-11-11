#include <bits/stdc++.h>

using namespace std;

long long n,m,a[500009],ans,k;
long long b[500009],o = 0;

void dfs(long long l,long long remain,long long* b) {
//	cout << ++k << ' ';
	if (!remain) {
		o = 0;
//		sort(b+1,b+n+1);
		for (int i = 1; i <= n; i++) {
			if (b[i] != b[i-1]) {
				ans = max(ans,o);
				o = 1;
			} else {
				o++;
			}
		}
		return;
	}
	for (int i = l; i <= n; i++) {
		if (b[i]+1 <= b[n]) {
			b[i]++;
			dfs(i,remain-1,b);
			b[i]--;
		}
	}
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
//	cout << 1 << ' ';
	for (int i = 1; i <= n; i++) {
		b[i] = a[i];
	}
	dfs(1,m,b);
	cout << ans;
	return 0;
}
