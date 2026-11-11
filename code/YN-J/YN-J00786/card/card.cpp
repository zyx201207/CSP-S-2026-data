#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s += (char)(x + '0');
		ans[x] = i;
	}
	for (int i = n - 1; i >= 0; i--) {
		int flag1 = 0;
		for (int j = 0; j < i; j++) {
			int flag = s.find(s[j]);
			if (flag != -1 && flag > i)
				flag1 ++;
		}
		ans[s[i] - '0'] -= flag1;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
