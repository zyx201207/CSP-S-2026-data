#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> nxt, lst, now, a;
vector<vector<int> > pos;
vector<int> ans;
int n, m;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	a.resize(n);
	ans.resize(m, 0);
	nxt.resize(n, n);
	lst.resize(n, n);
	pos.resize(m);
	for (int i = 0; i < n; i++) {
		int kind;
		cin >> kind;
		kind--;
		a[i] = kind;
		if (pos[kind].size()) nxt[pos[kind].back()] = i, lst[i] = pos[kind].back();
		pos[kind].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		int same = n, same_begin;
		for (int j = i; j < n; j++) {
			if (j == same) {
				for (int k = now.size() - 1; k >= same_begin; k--) now.pop_back();
			}
			if (same > nxt[j]) {
				same = nxt[j];
				same_begin = j;
			}
			now.push_back(a[j]);
		}
		for (int i = 0; i < now.size(); i++) {
			ans[now[i]]++;
		}
	}
	for (int i = 0; i < m; i++) cout << ans[i] << ' ';
	return 0;
}
/*
10 3
0 1 2 3 4 5 6 7 8 9
3 1 2 1 3 2 3 1 2 1
4 3 5 7 6 8 - 9 - -
- - - 1 0 2 4 3 5 7
*/
