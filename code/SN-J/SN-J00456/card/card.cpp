#include<bits/stdc++.h>
using namespace std;
int a[500005];
int maxw[500005], nxt[500005];
int f[500005], ans[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxw[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) nxt[i] = maxw[a[i]];
	for (int i = 1; i <= n; i++) f[i] = 1;
	for (int i = 1; i <= n; i++) {
		ans[a[i]] += f[i];
		f[nxt[i] + 1] += f[i]; 
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
// 还记得你说家是唯一的城堡，闻着稻香河流继续奔跑。
