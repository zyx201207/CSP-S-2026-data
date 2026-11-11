#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,a[500005];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) {
		int cnt = 0;
		for(int j = 1;j <= i;j++) {
			cnt += abs(a[i] - a[j]);
		}
		if(cnt > m) {
			cout << i - 1;
			return 0;
		}
	}
	return 0;
}