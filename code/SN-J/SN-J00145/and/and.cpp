#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], ma = -1, s = 0;

int main() {
	//freopen("and.in", "w", stdin);
	//freopen("and.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (m == 1)
	{
		for (int i = 1; i <= n; i++) ma = max(ma, a[i]);
		cout << ma;
		return 0;
	}
	else if (m == n)
	{
		for (int i = 1; i <= n; i++) s += a[i];
		cout << s;
		return 0;
	}
	else if (m == 2)
	{
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++) ma = max(ma, (a[i] & a[j]));
		cout << ma;
		return 0;
	}
	return 0;
} 
