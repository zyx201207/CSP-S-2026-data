#include<bits/stdc++.h>
#define file "hub"
#define int long long
using namespace std;
int c, T, n, k;
struct Edge {
	int v, nxt;
}edge[2000000 + 5];
int head[1000000 + 5], idx;
void add(int u, int v) {
//	cerr << u << ' ' << v << ' ' << w << endl;
	edge[++idx] = { v, head[u] };
	head[u] = idx;
}
int32_t main() {
	freopen(file ".in", "r", stdin);
	freopen(file ".out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) head[i] = 0; idx = 0;
		for (int i = 1, u, v; i < n; ++i)
			cin >> u >> v, add(u, v), add(v, u);
		if (c <= 3) {
			static int perm[1000];
			for (int i = 1; i <= n - k; ++i) perm[i] = 0;
			for (int i = n - k + 1; i <= n; ++i) perm[i] = 1;
			int ans = n;
			do {
				int mx = 0, cnt = 0;
				function<int(int, int, int, int)>dfs = [&](int x, int fa, int lst, int dep) {
					if (lst != dep - 1 && perm[x]) cnt++;
					int mndp = n;
					for (int i = head[x]; i; i = edge[i].nxt) {
						if (edge[i].v == fa) continue;
//						cout << x << ' ' << edge[i].v << ' ' << fa << endl;
						mndp = min(mndp, dfs(edge[i].v, x, perm[x] ? dep : lst, dep + 1));
					}
					if (perm[x]) return dep;
//					cout << x << ':' << mndp << ' ' << min(dep - lst, mndp - dep) << endl;
					mx = max(min(dep - lst, mndp - dep), mx);
					return mndp;
				};
				dfs(1, 1, -n, 0);
				if (cnt > 2) continue;
//				for (int i = 1; i <= n; ++i) cout << perm[i] << ' '; cout << endl;
//				cout << mx << endl;
				ans = min(ans, mx);
			} while(next_permutation(perm + 1, perm + n + 1));
			cout << ans << endl;
		}
	}
	return 0;
}
/*
I saw a light, a shiny tear.
The end you seek. Does it bring you peace.
If only you can see, your history remain in me.
A signal sprouting
A signal blooming
A signal watching
I walk through the path
Fingertips pollinating

Somedays I hope you to be you here
Far far away countless lightyears
No need to hurry my dear
If you lost in disbelief
I'll sait besides you quietly
Hold you hands squzzing tightly
And let your tears depand my sleeves
By the time you strong, I'm nowhere to be found
As if I was never around

啊，还是背不下来，坠机了。
你是谁，请支持崩坏星穹铁道的昔涟谢谢喵~
你是谁，请支持明日方舟的特蕾西娅谢谢喵~
我是 starfallen，可以来洛谷找我玩，但是不保证在（因为要被 whk 草饲了呜呜呜）

//freopen
froepen
CCF
*/