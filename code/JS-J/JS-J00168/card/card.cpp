#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 500010;

int n, m, a[N], cnt[N], ans[N];

void solve1() {
	stack<int> s;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			cnt[j] = 0;
		for(int j = i; j <= n; j++) {
			if(cnt[a[j]] != 0)
				while(s.top() != a[j])
					cnt[s.top()]--, s.pop();
			else
				cnt[a[j]]++, s.emplace(a[j]);
		}
		while(!s.empty())
			ans[s.top()]++, s.pop();
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	solve1();
	return 0;
}