#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int N = 2e5 + 5;
int a[N];
map<int, int>mp;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			mp[a[j]] ++;
		}
	}
	for (auto it : mp) {
		cout << it.second << ' ';
	}
	return 0;
}