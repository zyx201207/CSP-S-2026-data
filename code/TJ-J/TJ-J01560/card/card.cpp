#include <bits/stdc++.h>
using namespace std;

int ans[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		s += to_string(num);
	}
	for (int i = 1; i <= m; i++) {
		cout << s.rfind(char('0' + i)) - s.find(char('0' + i)) + 1 + s.find(char('0' + i)) - 0 << " ";
	}
	return 0;
}