// pwd: j:Trick||Treat! s:Oct31==Dec25?
// shen ren kao chang, kai kao 5 fen zhong hai mei fa ti
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const int N = 2e6 + 5;
int c, T;
int n, d, a[N];

void solveA()
{
    int dd = a[2] - a[1];
    int x = d / dd;
    if (x <= 1)
    {
        cout << 0 << '\n';
        return;
    }
    cout << max(0ll, n - (2 * x) + 1) << '\n';
}

void solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (c == 11 || c == 12)
    {
        solveA();
        return;
    }
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while (T--)
    {
        solve();
    }
	return 0;
}
