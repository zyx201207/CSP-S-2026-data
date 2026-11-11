#include <bits/stdc++.h>
using namespace std;
#define freopen(io) freopen(io".in", "r", stdin), freopen(io".out", "w", stdout)
#define int long long

const int MAXN = 200007;
int n;
string s;
int ans = 0;

signed main()
{
	freopen("string");
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int p; char c; cin >> p >> c;
		for (int j = 0; j < p; j++) s.push_back(c);
	}
	for (size_t i = 0; i < s.size(); i++)
		if (s[i] != s[s.size() - i - 1]) ans++;
	cout << ans / 2 << '\n';
}