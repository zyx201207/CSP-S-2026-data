#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
ll n, m, a[N], ans[M];
string s;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i] + '0';
	}
	for (int i = 0; i < n; i++) {
		string s1;
		for (int j = i; j < s.size(); j++)
			s1 += s[j];
		for (int j = i + 1; j < s1.size(); j++) {
			if (s1[j] == s[i])
				s1.erase(i, j - i);
		}
//		cout << s1 << '\n';
		for (int j = 0; j < s1.size(); j++)
			ans[s1[j] - '0']++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}