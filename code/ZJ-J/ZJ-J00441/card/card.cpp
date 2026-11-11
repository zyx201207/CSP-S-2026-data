#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10; 
int n, m, a[N], lt[N], lst[N], ans[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++){
		for (int j = i; j <= n; j ++){
			if (lst[a[j]]) for (int k = lst[a[j]]; k <= j - 1; k ++) lst[a[k]] = 0;
			lst[a[j]] = j;
		}
		for (int j = i; j <= n; j ++) if (lst[a[j]]) lst[a[j]] = 0, ans[a[j]] ++;
	}
	for (int i = 1; i <= m; i ++){
		cout << ans[i];
		if (i != m) cout << " ";
	}
	return 0;
}
