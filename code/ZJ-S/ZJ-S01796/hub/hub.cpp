#include <bits/stdc++.h>
#define LL long long
#define ST string
#define DB double

#define fr(x, y, z) for (int x = y; x <= z; x ++ )
#define dfr(x, y, z) for (int x = y; x >= z; x -- )

using namespace std;

const int N = 15, M = 30;
int c, t, n, m;

int mndep[N], res, col[N];
bool vis[N], isc[N];
vector <int> v[N];
void flood(int x, int c) {
	col[x] = c;
	fr (i, 0, (int)v[x].size() - 1) {
		if (!col[v[x][i]] && isc[v[x][i]])
			flood(v[x][i], c);
	}
}

void get(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	if (isc[x]) return mndep[x] = 0, void();
	fr (i, 0, (int)v[x].size() - 1) {
		if (!vis[v[x][i]]) get(v[x][i]);
		mndep[x] = min(mndep[x], mndep[v[x][i]] + 1);
	}
}

void chk() {
	int cnt = 0;
	fr (i, 1, n) vis[i] = col[i] = 0;
	fr (i, 1, n) if (!col[i] && isc[i]) {
		cnt ++ ; if (cnt > 2) return ;
		flood(i, i);
	}
	
	int nres = 0;
	fr (i, 1, n) mndep[i] = n + 1;
	fr (i, 1, n) get(i), nres = max(nres, mndep[i]);
	
	res = min(res, nres);
}

void dfs(int x, int cnt) {
	if (cnt == m) return chk();
	if (x == n + 1) return ;
	isc[x] = 1, dfs(x + 1, cnt + 1);
	isc[x] = 0, dfs(x + 1, cnt);
}

void solve() {
	cin >> n >> m;
	res = n + 1;
	int x, y;
	fr (i, 1, n) v[i].clear();
	fr (i, 2, n) cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
	dfs(1, 0);
	cout << res << '\n';
}

signed main() {
	 freopen("hub.in", "r", stdin);
	 freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> t;
	
	while (t -- ) solve();
	
	return 0;
}

// 15

/*
  Genshen Impact is the best game around the world.
  I'm a friendly and modest person(if you don't say any impolite words).
  If you play it too, it will be my honor to make friends with you and play with you.
  (I'm a new player who has only 100 days' experience of playing)
  my uid: 346 444 555. (HyvialValerius)
  hope someone could see it :)
  (My English is not well, so if my words have any problems, please excuse me^^)
  
  Happy birthday to Luo Xiaohei
*/
