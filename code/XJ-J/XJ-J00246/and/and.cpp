#include <iostream>
#include <vector>
using namespace std;

int n, m, answer, a[200010];
bool vis[200010];
// vector<int> vec;

void dfs(int cur, int total, int mm)
{
	if (mm == m)
	{
		answer = max(answer, total);
//		for (int i = 0; i <vec.size(); ++i)
//			cout<< vec[i]<< ' ';
//			cout << endl;
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (cur == i) continue;
		if (vis[i]) continue;
//		vec.push_back(a[i]);
		vis[i] = true;
		dfs(i, total & a[i], mm + 1);
		vis[i] = false;
//		vec.pop_back();
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n>> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		int ans = -1;
		for (int i = 1;  i <= n; ++i)
		{
			ans = max(ans, a[i]);
		}
		cout << ans << endl;
		return 0;
	}
	if (m == n)
	{
		int ans = a[1];
		for (int i = 2; i <= n; ++i)
		{
			ans = ans & a[i];
		}
		cout << ans << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		vis[i] = true;
		dfs(i, a[i], 1);
		vis[i] = false;
	}
	cout << answer << endl;
	return 0;
}

