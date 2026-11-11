#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
int n;
ll m;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	vector<ll> a(n, 0), b(n, 0);
	vector<int> ch(n, 0);
	map<ll, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());

	b.erase(unique(b.begin(), b.end()), b.end());
	int len = b.size();
	int cnt = 0;

	for (int i = 0; i < len; i++) {
		mp[b[i]] = ++cnt;
	}

	for (int i = 0; i < n; i++) {
		ch[mp[a[i]]]++;
	}
	int maxx = 0;
	for (int i = 0; i < len; i++) {
		int ans = ch[ mp[b[i]] ];
		ll sum = m;
		for (int j = i - 1; j >= 0; j--) {
			if (sum <= 0)
				break;
			if (ch[mp[b[j]]] * (b[i] - b[j]) <= sum) {
				sum -= ch[mp[b[j]]] * (b[i] - b[j]);
				ans += ch[mp[b[j]]];
			} else {
				ans += sum / (b[i] - b[j]);
				break;
			}
		}
		maxx = max(maxx, ans);
	}
	cout << maxx;
	return 0;
}
//priority_queue
//Oct31==Dec25 有趣的密码
//检查RECE 检查数据量 检查耗时