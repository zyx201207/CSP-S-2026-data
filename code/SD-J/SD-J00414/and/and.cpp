#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005], pre[200005];
int f(int x) {
	int cnt = 0;
	while (x) {
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}
int g(int x) {
	int cnt = 0;
	while (x) {
		cnt++;
		x >>= 1;
	}
	return cnt;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (m == 1) {
		int maxn = -1;
		for (int i = 1; i <= n; i++) maxn = max(maxn, a[i]);
		cout << maxn;
	}
	else if (m == 2) {
		int maxn = -1;
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				maxn = max(maxn, a[i] & a[j]);
		cout << maxn;
	}
	else if (m == n) {
		pre[1] = a[1];
		for (int i = 2; i <= n; i++) pre[i] = pre[i - 1] & a[i];
		cout << pre[n];
	}
	else {
		bool bujidao = 1;
		for (int i = 1; i <= n; i++) 
			if (f(a[i]) != g(a[i])) bujidao = 0;
		if (bujidao) {
			sort(a + 1, a + 1 + n, greater<int>());
			cout << a[m];
		}
		else cout << 0;
	}
	return 0;
} 
