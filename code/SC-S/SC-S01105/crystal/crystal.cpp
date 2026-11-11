#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
long long m;
int ans = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; ++i) {
		int c = a[i] - a[i - 1];
		if (m < (i - 1) * (a[i] - a[i - 1])) {
			cout << ans;
			return 0;
		} else {
			m -= (i - 1) * (a[i] - a[i - 1]);
			ans++;
		}
	}
	cout << ans;
	//I LOVE CCF
	//CCF nb
	//I LOVE CCF
	//CCF nb
	//I LOVE CCF
	//CCF nb
	//乞求CCF多给点分 orz orz orz
	//许愿米提亚，芙宁娜不歪 十连三金
	return 0;
}