#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
bool vis[300005];

int main() {

	freopen("card.in","r",stdin);
	freopen("card.out ","w",stdout);

	stack<int>s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (vis[a[i]] == 0) {
			vis[a[i]] = 1;
		} else {
			while (s.top() != a[i]) {
				s.pop();
			}
			s.pop();
		}
		s.push(a[i]);
	}
	while (s.empty() != 1) {
		cout << s.top()<<" ";
		s.pop();
	}
	return 0;
}
