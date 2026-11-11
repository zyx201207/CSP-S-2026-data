// pwd: j:Trick||Treat! s:Oct31==Dec25?
// shen ren kao chang, kai kao 5 fen zhong hai mei fa ti
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const int N = 5e5 + 5;
int n;
ll m, a[N], sum[N];

bool check(int mid)
{
    for (int i = mid; i <= n; i++)
    {
        int l = i - mid + 1, r = i;
        ll x = a[i];
        ll s = sum[r] - sum[l - 1];
        ll c = x * mid - s;
        if (c <= m) return 1;
    }
    return 0;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    int l = 1, r = n;
    while (l + 1 < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << '\n';
	return 0;
}
