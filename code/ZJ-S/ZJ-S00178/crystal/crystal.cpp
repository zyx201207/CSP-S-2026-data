#include<bits/stdc++.h>
#define int long long
using namespace std;
//auto getmax = [](auto &a, auto b) {a = max(a, b);};
//auto getmin = [](auto &a, auto b) {a = min(a, b);};
const int N = 5e5 + 7;
int n, m, a[N], cnt, ans;
deque<int> d;

bool check(int i)
{
	int ch = d.size() * a[i] - cnt;
//	cout << ch << ' ' << i << '\n';
	return ch > m;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		while (d.size() && check(i)) cnt -= a[d.front()], d.pop_front();
		d.push_back(i); cnt += a[i];
		ans = max(ans, (int)d.size());
//		cout << cnt << ' ' << i << '\n';
	}
	cout << ans;
	return 0;
}
