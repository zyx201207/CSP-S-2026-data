#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[100005], c[100005];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int b[100005];
		memset(b, 0, sizeof b);
		map<int, int>mp;
		int top = 0;
		for (int j = i; j <= n; j++) {
			b[++top] = a[j];
			if (mp[a[j]] != 0) {
				int yyy = mp[a[j]];
				for (int k = mp[a[j]]+1; k <= top; k++)
					mp[k] = 0;
				top = yyy;
				b[top] = a[j];
				//cout << "1:";
			} else
				mp[a[j]] = top;//, cout << "2:";
//			for (int k = 1; k <= top; k++)
//				cout << a[k] << ' ';
//			cout << endl;
		}
		for (int j = 1; j <= top; j++)
			c[b[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << c[i] << ' ';
	return 0;
}