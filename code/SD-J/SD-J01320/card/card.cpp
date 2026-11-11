#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int SIZE = 5e5 + 5, T = 816;
int n, m, a[SIZE], ans[SIZE];
stack <int> st;
bool vis[SIZE], f = 1;
int lst[SIZE];
void _main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] < a[i - 1])f = 0;
	}
	if (m == 1) {
		cout << n;
		return;
	}
	if (f) {
		for (int i = 1; i <= n; i++) {
			lst[a[i]] = i;
		}
		for (int i = 1; i <= m; i++) {
			cout << lst[i] << " ";
		}
		return;
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++){
			if (!vis[a[j]]){
				st.push(a[j]);
				vis[a[j]] = 1;
			}
			else {
				while (st.top() != a[j]){
					vis[st.top()] = 0;
					st.pop();
				}
			}
		}
		while (!st.empty()){
			vis[st.top()] = 0;
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return;
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	while (t --> (T^T)){
		_main();
	}
	return 0; 
}
