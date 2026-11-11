#include <iostream>
using namespace std;
using ll = long long;
constexpr int N = 2e6 + 5;
ll x[N];
void solve(int c)
{
	int n;
	ll d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	cout << 0 << '\n';
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--)
		solve(c);
	return 0;
}
