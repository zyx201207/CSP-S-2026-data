#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	vi a(n + 1), nw(n + 2, 0), lst(m + 1, 0), nxt(n + 2, 0), sz(n + 2, 1), t(m + 1, 0);
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) lst[a[i]] = i;
	for(int i=n; i>=1; i--) {
		nw[i] = t[a[i]];
		t[a[i]] = i;
	}
	for(int i=1; i<=n; i++) {
		if(nw[i] != 0) nxt[i] = nw[i];
		else nxt[i] = i + 1;
	}
	sz[n + 1] = 0;
	for(int i=1; i<=n; i++) sz[nxt[i]] += sz[i];
	for(int i=1; i<=m; i++) cout << sz[lst[i]] << (i == m ? "" : " ");
	return 0;
}
