#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, cnt;
int a[N], nex[N], fro[N], ans[N];
int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		nex[fro[a[i]]] = i;
		fro[a[i]] = i;
	}
	nex[0] = 0;
	for(int i = n; i >= 1; --i) {
		if(nex[nex[i]]) nex[i] = nex[nex[i]];
	}
//	for(int i = 1; i <= n; ++i) cout << nex[i] << " ";	
	for(int i = 1; i <= n; ++i) {
		int till = i;
		while(till <= n) {
			if(nex[till]) till  = nex[till];
			ans[a[till]]++;
			till++;
//			cout <<till << "\n";
		}
	}
	for(int i = 1; i <= m; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}
