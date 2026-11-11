#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5; 
int n, m;
int a[N], ans[N], lp[N];
bool sizA = true, sizB;
int main() { 
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i<= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) sizA = false;	
	}
	if (sizA) {
		for (int i = 1; i <= m; i++) cout << i << " ";
		return 0;
	}
	int maxl = 0, maxr = 0;
	for (int i = 1; i <= n; i++) {
		maxl = maxr = 0;
		for (int j = 1; j <= m; j++) lp[j] = 0; 
		for (int j = i; j <= n; j++) {
			if (lp[a[j]] == 0) lp[a[j]] = j;
			if (j - lp[a[j]] >= maxr - maxl) maxr = j, maxl = lp[a[j]];
		}
		for (int j = i; j < maxl; j++) ans[a[j]]++;
		for (int j = maxr; j <= n; j++) ans[a[j]]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
