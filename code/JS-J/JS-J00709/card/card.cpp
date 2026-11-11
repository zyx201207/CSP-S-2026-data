#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], cnt[N];

inline void solve(int x) {
	map <int, int> mp;
	deque <int> q;
	for (int i = x; i <= n; i++) {
		if (!mp[a[i]]) {
			q.push_back(a[i]);
			mp[a[i]]++;
		}
		else {
			int y;
			for (int j = 0; j < q.size (); j++) {
				if (q[j] != a[i])
					continue;
				y = j;
			}
			for (int j = y; j < q.size (); j++) {
				mp[q.back()]--;
				q.pop_back();
			}
			q.push_back(a[i]);
		}
	}
	for (auto i : mp)
        if (i.second)
            cnt[i.first]++;
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		solve(i);
    for (int i = 1; i <= m; i++)
        cout << cnt[i] << ' ';
}
