#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int en,fe,wa;
	Edge() {}
	Edge(int a,int b,int c):en(a),fe(b),wa(c) {}
};

int c,n,m,d,q,w[500009],k;
int st,en,ans,ansn;
vector<Edge> a[500009];

void dfs(int l,int fa,int was,int r) {
//	cout << l << ans << ++k << endl;
	if (l == en) {
//		cout << l;
		ansn = min(ansn,ans);
		return;
	}
//	for (Edge e : a[l]){
//		if (e.en != fa){
//			ans++;
//			dfs(e.en,l);
//		}
//	}
//	cout << l << ' ';
//	cout << a[l][1].en << ' ';
	for (int i = 0; i < a[i].size(); i++) {
		Edge e = a[l][i];
		if (e.en != fa) {
			cout << l << ' ';
			if (e.wa != was) {
				int h = a[fa][r].fe + e.fe;
				ans += h;
//				cout << h << ' ';
				dfs(e.en,l,e.wa,i);
				ans -= h;
			} else {
//				cout << l << ' ';
				dfs(e.en,l,e.wa,i);
			}
		}
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ansn = INT_MAX;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int l;
		cin >> l;
		int l1 = 0,r1 = 0,l2 = 0,r2 = 0;
		for (int j = 1; j <= l; j++) {
//			cout << j;
			cin >> l2 >> r2;
			if (j != 1) {
//				cout << j << ' ';
				a[l1].push_back(Edge(l2,r1,i));
				a[l2].push_back(Edge(l1,r2,i));
			}
			l1 = l2;
			r1 = r2;
		}
	}
	while(q--) {
		cin >> st >> en;
		dfs(st,-1,n+100,0);
		ansn = ansn + w[st] + w[en];
		cout << ansn << endl;
	}
	return 0;
}
