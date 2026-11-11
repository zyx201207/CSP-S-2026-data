#include <iostream>
#include <map>
#include <stack>
using namespace std;
int n, m;
const int N = 5e5;
int a[N + 1], b[N + 1];
map<int, int> vis, has;
int	main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		stack<int> stk;
		vis.clear();
		for (int j = i; j <= n; j++) {
			if (vis.count(a[j])) {
				while(stk.size() && stk.top() != vis[a[j]])
					stk.pop();
				if (stk.size() && stk.top() == vis[a[j]])
					stk.pop();
			}
			stk.push(j);
			vis[a[j]] = j;
		}
		while (stk.size()) {
			has[a[stk.top()]]++;
			cout << a[stk.top()] << " ";
			stk.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << has[i] << " ";
	}
	return 0;
}
