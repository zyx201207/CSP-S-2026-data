#include <bits/stdc++.h>

const int N = 4005;

int k, n, ans, fa[N], cut_center[N][2], md[N], anti_md[N];
std::vector<int> ver[N], stk;

void dfs1(int x) {
	for (int i = 0; i < ver[x].size(); ++i) {
		int v = ver[x][i];
		if (v == fa[x]) {
			continue;
		}	
		fa[v] = x;
		dfs1(v);
	}
}

void dfs2(int x, int ea, int eb, int ff) {
	md[x] = 0;
	for (int i = 0; i < ver[x].size(); ++i) {
		int v = ver[x][i];
		if (v == ff || (x == ea && v == eb) || (x == eb && v == ea)) {
			continue;
		}
		dfs2(v, ea, eb, x);
		md[x] = std::max(md[x], md[v] + 1);
	}
	return ;
}

int dist[N];

void dfs3(int x, int ea, int eb, int ff) {
	for (int i = 0; i < ver[x].size(); ++i) {
		int v = ver[x][i];
		if (v == ff || (x == ea && v == eb) || (x == eb && v == ea)) {
			continue;
		}
		dist[v] = dist[x] + 1;
		dfs3(v, ea, eb, x);
	}
	return ;
}

int target, now_x, now_y;

void dfs4(int x, int ea, int eb, int ff) {
	stk.push_back(x);
	if (x == target) {
		int s = stk.size();
		cut_center[now_x][now_y] = stk[s / 2];
	}
	for (int i = 0; i < ver[x].size(); ++i) {
		int v = ver[x][i];
		if (v == ff || (x == ea && v == eb) || (x == eb && v == ea)) {
			continue;
		}
		dfs4(v, ea, eb, x);
	}
	stk.pop_back();
}

void solve() {
	scanf("%d%d", &n, &k);
	ans = n;
	for (int i = 1; i <= n; ++i) {
		ver[i].clear();
		fa[i] = 0;
	}
	for (int i = 1; i <= n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ver[x].push_back(y);
		ver[y].push_back(x);
	}
	dfs1(1);
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dist[j] = 0;
		}
		dist[i] = 1;
		dfs3(i, i, fa[i], 0);
		int m_n = 0, m_s = 0;
		for (int j = 1; j <= n; ++j) {
			if (dist[j] > dist[m_n]) {
				m_n = j;
			}
		}
		for (int j = 1; j <= n; ++j) {
			dist[j] = 0;
		}
		dist[m_n] = 1;
		dfs3(m_n, i, fa[i], 0);
		for (int j = 1; j <= n; ++j) {
			if (dist[j] > dist[m_s]) {
				m_s = j;
			}
		}
		target = m_s;
		now_x = i, now_y = 0;
		dfs4(m_n, i, fa[i], 0);
		
		
		for (int j = 1; j <= n; ++j) {
			dist[j] = 0;
		}
		dist[fa[i]] = 1;
		dfs3(fa[i], i, fa[i], 0);
		m_n = 0, m_s = 0;
		for (int j = 1; j <= n; ++j) {
			if (dist[j] > dist[m_n]) {
				m_n = j;
			}
		}
		for (int j = 1; j <= n; ++j) {
			dist[j] = 0;
		}
		dist[m_n] = 1;
		dfs3(m_n, i, fa[i], 0);
		for (int j = 1; j <= n; ++j) {
			if (dist[j] > dist[m_s]) {
				m_s = j;
			}
		}
		target = m_s;
		now_x = i, now_y = 1;
		dfs4(m_n, i, fa[i], 0);
		
		for (int j = 1; j <= n; ++j) {
			anti_md[j] = md[j] = 0;
		}
		dfs2(cut_center[i][0], i, fa[i], 0);
		dfs2(cut_center[i][1], i, fa[i], 0);
		for (int j = 1; j <= n; ++j) {
			++anti_md[md[j]];
		}
		int sum = 0, tmp_ans = n;
		for (int j = n; j >= 1; --j) {
			sum += anti_md[j];
			if (sum <= k) {
				tmp_ans = j;
			}
		}
		ans = std::min(ans, tmp_ans);
	}
	printf("%d\n", ans);
	return ;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		solve();
	}
	return 0;
}
