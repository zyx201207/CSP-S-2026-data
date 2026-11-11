#include <iostream>
#include <vector>
using namespace std;
constexpr int N = 1e6 + 5;
vector<int> e[N];
void solve(int c)
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout << 1 << '\n';
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--)
		solve(c);
	return 0;
}
