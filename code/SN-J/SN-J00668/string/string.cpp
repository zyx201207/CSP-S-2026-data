//wangyichitongchuanshidierzhongxueSN-J00668
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, ans = 0; string s = "";

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; char c; cin >> x >> c;
		for (int i = 1; i <= x; i++) s += c; 
	}
	ll m = s.length();
	for (int i = 0; i <= m / 2; i++) if (s[i] != s[m - i - 1]) ans++;
	cout << ans;
}
