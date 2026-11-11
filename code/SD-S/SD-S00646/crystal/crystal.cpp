#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 5e5+2;
int n; ll m, a[MAXN];
void Solve1()
{
	sort(a+1, a+n+1);
	int ans = 0;
	for (int i = n; i >= 1; --i){
		int sum = 1; ll left = m;
		for (int j = i-1; j >= 1; --j){
			ll cost = a[i] - a[j];
			if (cost <= left) ++sum, left -= cost;
			else break;
		}
		ans = max(ans, sum);
	}
	cout << ans << "\n";
}
void Solve2()
{
	sort(a+1, a+n+1);
	int ans = 0, sum = 0, left = m, l = n, r = n;
	while (l >= 1){
		ll cost = a[r] - a[l];
		if (cost <= left) ++sum, left -= cost, --l;
		else left += (a[r] - a[r-1]) * sum, --r, --sum;
		ans = max(ans, sum);
	}
	cout << ans << "\n";
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string file = "crystal";
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	Solve2();
	return 0;
}
