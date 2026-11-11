#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int N = 100005;
int n, m, a[N], ans[N], vis1[N], vis2[N], vis[N];
stack<int>q;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; ++i) cin >> a[i];
	for (int i = 1 ; i <= n ; ++i) {
		memset(vis, 0, sizeof vis);
		while(!q.empty()) q.pop();
		for (int j = i ; j <= n ; ++j) {
			if (vis[a[j]]) {
				while (!q.empty() && q.top()!= a[j]) {
					vis[q.top()]--;
					q.pop();
				}
				q.pop();
			}
			q.push(a[j]);
			vis[a[j]] = 1;
		}
		while (!q.empty()) {
			ans[q.top()]++;
			q.pop();
		}
	}
	for (int i = 1 ; i <= m ; ++i) cout << ans[i] << " ";
	return 0;
}
