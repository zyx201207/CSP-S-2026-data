#include <bits/stdc++.h>
using namespace std;
long long m, a[500005], ans = -0x3f3f3f3f, n, cnt[500005];
map<long long, long long>mp;
bool flag = true;

void dfs(int pos) {
	if (pos == m + 1) {
		long long k = -0x3f3f3f3f;
		for (auto c = mp.begin(); c != mp.end(); c++)
			k = max(k, c->second);
		ans = max(ans, k);
		return;
	}
	for (int i = 1; i <= n; i++) {
		mp[cnt[i]]--;
		cnt[i]++;
		mp[cnt[i]]++;
		dfs(pos + 1);
		mp[cnt[i]]--;
		cnt[i]--;
		mp[cnt[i]]++;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], cnt[i] = a[i], mp[a[i]]++;
	for (int i = 2; i < n; i++) {
		flag = flag & (a[i] - a[i - 1] == a[i + 1] - a[i]);
		if (!flag)
			break;
	}
	if (flag) {
		int d = a[2] - a[1];
		m /= d;
		m = (-1 + sqrt(8 * m + 1)) / 2;
		cout << m + 1;
	} else
		dfs(1);
	cout << ans;
	return 0;
}
