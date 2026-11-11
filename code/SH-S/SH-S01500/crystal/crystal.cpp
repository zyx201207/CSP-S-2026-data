#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long cnt;
long long a[500005];
long long maxx;
void dfs(int step) {
	long long cnt = 0;
	if (step > m) return;
	step++;
	a[1]++;
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[1]) cnt++;
	}
	if (cnt > maxx) maxx = cnt;
	dfs(step);
}
int main() {
	freopen("crtstal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <=n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	dfs(0);
	cout << maxx;
	return 0;
}
